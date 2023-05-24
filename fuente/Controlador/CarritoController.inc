<?php
namespace ConciertosProyecto\app\controlador;
use ConciertosProyecto\app\Modelo\Concierto;
use ConciertosProyecto\app\Modelo\ConciertoException;
use ConciertosProyecto\app\Repositorio\ConciertoRepositorio;
use ConciertosProyecto\app\Repositorio\EntradaRepositorio;
use ConciertosProyecto\app\Repositorio\RegistroRepositorio;


class CarritoController
{
    public function addEntradaCarrito():void
    {
        if(isset($_POST['Comprar']))
        {
            if(isset($_POST['numEntradas']) && $_POST['numEntradas'] <= 0 ){
                $errorNumEntradas = "No puedes comprar entradas negativas ni 0";
            }else if($_POST['numEntradas'] > 5){
                $errorNumEntradas = "No puedes comprar mas de 5 entradas a la vez";
            }
            else{
                if(isset($_SESSION['usuario']))
                {
                    
                    $entradasSuficientes = false;
                    $concierto = (new ConciertoRepositorio())->getConcierto($_POST['codConcierto']);
                    if( $_POST['tipoEntrada'] == 'normal' && $_POST['numEntradas'] <= $concierto[0]["numEntradasNormales"])
                    {
                        $entradasSuficientes = true;
                        
                    }else if($_POST['tipoEntrada'] == 'vip' && $_POST['numEntradas'] <= $concierto[0]["numEntradasVip"])
                    {
                        $entradasSuficientes = true;
                    
                    }
                    
                    if($entradasSuficientes){
                        if(isset($_SESSION["carrito"]))
                        {
                            $carrito = $_SESSION["carrito"];
                            $sumEntradas = $_POST['numEntradas'];
                            foreach($carrito as $clave => $value){
                                if($value[0] == $_POST['codConcierto'])
                                {
                                    $sumEntradas += $value[1];
                                    
                                }
                                
                            }
                            
                            if($sumEntradas > 5 )
                            {
                                $errorNumEntradas = "No puedes comprar mas de 5 entradas en total";
                            }else{
                                array_push($carrito,[$_POST['codConcierto'],$_POST['numEntradas'],$_POST['tipoEntrada']]);
                            }
                        
                        }else{
                            $carrito = [];
                            array_push($carrito,[$_POST['codConcierto'],$_POST['numEntradas'],$_POST['tipoEntrada']]);
                        }
                        $_SESSION["carrito"] = $carrito;
                    }else{
                        $errorNumEntradas = "No hay entradas suficientes";
                    }

                    
                    

                }else{
                    $errorCompra = "No puedes comprar si no estas logueado";
                    $link = 'Location:index.php?ctl=login&concierto=' . $_POST['codConcierto'];
                    header($link);
                }
            }
            
          
        }

        if(isset($_GET['codConcierto']))
        {
            $idConcierto = $_GET['codConcierto'];
        }else{
            $idConcierto = $_POST['codConcierto'];
        }
        
        $conciertos = (new ConciertoRepositorio())->getConcierto($idConcierto);
        $imagenesCarrusel = (new ConciertoRepositorio())->getImgsConcierto($idConcierto);         

        require __DIR__ . '/../../app/plantillas/infConcierto.php';  
       
    }

    public function listarCarrito() {
        if(isset($_SESSION["carrito"])){
            $carrito = $_SESSION["carrito"];
        }else{
            $carrito = [];
        }

        $entradaCarrito = []; //Array numConcierto y el value numero de entradas
        $entradaCarritoVip = [];
        foreach($carrito as $clave => $value){
            if($value[2] == 'normal'){
                if(isset($entradaCarrito[$value[0]]))
                {
                    $entradaCarrito[$value[0]] +=  (intval($value[1]));
                }else{
                    $entradaCarrito[$value[0]] =  (intval($value[1]));
                }
            }else{
                if(isset($entradaCarritoVip[$value[0]]))
                {
                    $entradaCarritoVip[$value[0]] +=  (intval($value[1]));
                }else{
                    $entradaCarritoVip[$value[0]] =  (intval($value[1]));
                }
            }
        }
        $conciertos = [];
        foreach($entradaCarrito as $clave => $value){
            $concierto = (new ConciertoRepositorio())->getConcierto($clave);
            $concierto['vip'] = 0;
            array_push($conciertos,$concierto);
        }

        foreach($entradaCarritoVip as $clave => $value){
            $concierto = (new ConciertoRepositorio())->getConcierto($clave);
            $concierto['vip'] = 1;
            array_push($conciertos,$concierto);
        }
        require __DIR__ . '/../../app/plantillas/listarCarrito.php'; 
    }

    public function comprarEntradas() {
        
       $usuario = (new RegistroRepositorio())->getUsuarioEmail($_SESSION['usuario']);
       
       if(isset($_SESSION["carrito"])){
        $carrito = $_SESSION["carrito"];
        }
        foreach($carrito as $clave=>$value)
        {
            $concierto = (new ConciertoRepositorio())->getConcierto($value[0]);
            $entradasSuficientes = false;
            if( $value[2] == 'normal' && $value[1] <= $concierto[0]["numEntradasNormales"])
            {
                $entradasSuficientes = true;
                
            }else if($value[2] == 'vip' && $value[1] <= $concierto[0]["numEntradasVip"])
            {
                $entradasSuficientes = true;
               
            }
            if($entradasSuficientes){
                
                for( $i = 0; $i < $value[1] ; $i++) {
                    if($value[2] == 'normal')
                    {
                        $entrada = (new EntradaRepositorio())->addEntradasConcierto($value[0],$concierto[0]['precioEntradasNormales'],$value[2],$usuario[0]["idUsuario"]);
                        
                    }else{
                        $entrada = (new EntradaRepositorio())->addEntradasConcierto($value[0],$concierto[0]['precioEntradasVip'],$value[2],$usuario[0]["idUsuario"]);
                    }
                    if($entrada != -1)
                    {
                        $qc = new QRCODE();
                        $textoQR = "http://localhost/ConciertosProyecto/TrabajoFinGrado-/index.php?ctl=comprobarEntrada&idEntrada=" . $entrada . "&idUsuario=" . $usuario[0]["idUsuario"];
                        $qc->TEXT($textoQR);
                        $qc->QRCODE(400,"Qr_concierto.png");
                        
                        
                        $entradas =  (new EntradaRepositorio())->getEntradaUsuario($entrada);
                        $pdf = new FPDF('P','mm','A4');
                        
                       

                        $pdf->AddPage();
                        $pdf->SetFont('Arial', '', 12);
                        $pdf->Cell(0, 10, utf8_decode('Información de la entrada de concierto'), 0, 1);
                        $pdf->Ln(5);
                        $pdf->MultiCell(0, 10,  utf8_decode('Detalles del concierto: Fecha, hora, ubicación, etc.'), 0, 'L');
                        $pdf->Ln(5);
                        $pdf->Cell(0, 10, 'Fecha: ' .substr($entradas[0]["fecha"], 8,2) . '-'.substr($entradas[0]["fecha"], 5,2) . '-' . substr($entradas[0]["fecha"], 0,4), 0, 1);
                        $pdf->Ln(5);
                        $pdf->Cell(0, 10, 'Hora:' .substr($entradas[0]["fecha"], 11,5), 0, 1);
                        $pdf->Ln(5);
                        $pdf->Cell(0, 10, utf8_decode('Ubicación:'. $entradas[0]["lugar"]), 0, 1);
                        $pdf->Ln(5);
                        $pdf->MultiCell(0, 10, 'Tipo entrada:' .$entradas[0]["tipoEntrada"], 0, 'L');
                        $pdf->Ln(5);
                        $pdf->MultiCell(0, 10, utf8_decode('Precio:' .number_format((float)$entradas[0]["precio"],2)), 0, 'L');
                        $pdf->Ln(5);
                        $pdf->Image('./web/imagenes/Qr_concierto.png', 60, 150, 90, 0, 'PNG');
                        $pdf->Output('./web/imagenes/entrada.pdf','F');
                        $mensajeEntrada = 'Compra Realizada con exito';
                        $entradasTotales = (new ConciertoRepositorio())->updateEntradasConcierto($concierto[0]['idConcierto'],$value[2]);
                        
                       
                        $contenido = ' <div class="row">
                        
                        <div class="col-md-6 col-lg-4 col-xl-4 offset-lg-2 py-2">
                            <p>Nombre del concierto: '.$entradas[0]['nombreConcierto'].'</p>
                            <p>Fecha: '.substr($entradas[0]["fecha"], 8,2) . '-'.substr($entradas[0]["fecha"], 5,2) . '-' . substr($entradas[0]["fecha"], 0,4).'</p>
                            <p>Hora: '.substr($entradas[0]["fecha"], 11,5).'</p>
                            <p>Lugar: '.$entradas[0]["lugar"].'</p>
                            <p>Tipo entrada:'.$entradas[0]["tipoEntrada"].'</p>
                            <p>Precio: '.number_format((float)$entradas[0]["precio"],2).'</p>
                        </div>
                        
                        </div>';
                        $mail = new PHPMailer(true);

                        try {
                            //Server settings
                            $mail->isSMTP();   
                            $mail->SMTPSecure = PHPMailer::ENCRYPTION_SMTPS;
                            $mail->SMTPSecure = 'tls';                                         //Send using SMTP
                            $mail->Host       = 'smtp.office365.com';                     //Set the SMTP server to send through
                            $mail->SMTPAuth   = true;                                   //Enable SMTP authentication
                            $mail->Username   = 'conciertosRioja@outlook.com';                     //SMTP username
                            $mail->Password   = 'Diego$1234';                               //SMTP password
                            $mail->Port       = 587;                                    //TCP port to connect to; use 587 if you have set `SMTPSecure = PHPMailer::ENCRYPTION_STARTTLS`

                            //Recipients
                            $mail->setFrom('conciertosRioja@outlook.com', 'ConciertosLaRioja');
                            $mail->addAddress($_SESSION['usuario'], '');     //Add a recipient

                            //Content
                            $mail->isHTML(true);                                  //Set email format to HTML
                            $mail->Subject = 'Entradas';
                            $mail->Body    = $contenido;
                            $mail->AddAttachment('./web/imagenes/entrada.pdf');
                            $mail->send();
                            $errorErrorCompra = 'Se ha enviado con exito la entrada a tu correo. Si no te ha llegado, compruebalo en la carpeta de Spam';
                        } catch (\Exception $e) {
                            $errorErrorCompra = 'Ha ocurrido un error';
                        }
                    }else{
                        $mensajeErrorCompra = 'Error en la compra';
                    }
                }
            }else{
                $errorCompraEntrada = "No hay entradas suficientes";
            }
            
        }
        if(!isset($mensajeErrorCompra)){
            $_SESSION["carrito"] = [];
            $link = 'Location:index.php?ctl=verEntradas';
            header($link);
        }
        

    }
    /*VER ENTRADAS POR USUARIO*/
    public function verEntradas()
    {
        if(isset($_SESSION['usuario']))
        {
            $usuario = (new RegistroRepositorio())->getUsuarioEmail($_SESSION['usuario']);
            $entradas =  (new EntradaRepositorio())->getEntradasUsuario($usuario[0]["idUsuario"]);
        }else{
            $link = 'Location:index.php?ctl=login';
            header($link);
        }
        
        require __DIR__ . '/../../app/plantillas/verEntradasUsuario.php'; 
    }
    /*VER TODAS ENTRADAS*/

    public function verTodasEntradasAdmin()
    {
        if(isset($_SESSION['rol']) && $_SESSION['rol'] == 'ADMIN')
        {
            $entradas = (new EntradaRepositorio())->getEntradas();
        }else{
            $link = 'Location:index.php?ctl=login';
            header($link);
        }
        require __DIR__ . '/../../app/plantillas/verTodasEntradasAdmin.php'; 
    }

    /*ELIMINAR ENTRADAS */
    public function deleteEntradaUsuario()
    {
        $entrada = (new EntradaRepositorio())->getEntrada($_GET['idEntrada']);
        $deleteEntrada = (new EntradaRepositorio())->deleteEntrada($_GET['idEntrada']);
        $updateEntrada = (new ConciertoRepositorio())->updateEntradasConciertoAdd($entrada[0]['idConcierto'],$entrada[0]['tipoEntrada']);
        $entradas = $entrada = (new EntradaRepositorio())->getEntradas();
        require __DIR__ . '/../../app/plantillas/verTodasEntradasAdmin.php'; 
    }

    public function verDetalleEntradas()
    {
        if(isset($_SESSION['usuario']))
        {
            $usuario = (new RegistroRepositorio())->getUsuarioEmail($_SESSION['usuario']);
            $entradas =  (new EntradaRepositorio())->getEntradaUsuario($_GET['idEntrada']);
            if($usuario[0]['idUsuario'] != $entradas[0]['idUsuario'])
            {
                $mensajeError = "No hay entradas asociadas a ese usuario";
            }
            
            
        }else{
            $link = 'Location:index.php?ctl=login';
            header($link);
        }
        
        require __DIR__ . '/../../app/plantillas/verEntrada.php';
    }

    public function comprobarEntrada()
    {
        $link = 'Location:index.php?ctl=comprobarEntrada';
        header($link);

        require __DIR__ . '/../../app/plantillas/comprobarEntrada.php';
    }

}