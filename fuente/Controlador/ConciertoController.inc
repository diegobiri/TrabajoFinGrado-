<?php
namespace ConciertosProyecto\app\controlador;
use ConciertosProyecto\app\Modelo\Concierto;
use ConciertosProyecto\app\Modelo\ConciertoException;
use ConciertosProyecto\app\Repositorio\ConciertoRepositorio;
use ConciertosProyecto\app\Repositorio\EntradaRepositorio;
use ConciertosProyecto\app\Repositorio\ArtistaRepositorio;
class ConciertoController
{
    public function addConcierto():void
    {
        if(isset($_SESSION['usuario']) && $_SESSION['rol'] == 'ADMIN')
        {
            if(isset($_POST["Enviar"]))
            {
                $erroresImagenes = [];
                $fechaTrans  = substr($_POST['fecha'],0,10)  . ' ' . substr($_POST['fecha'],11,2) . ':' . substr($_POST['fecha'],14,2) . ':' . '00';
                try {
                    $fecha = new \DateTime($fechaTrans);
                } catch (\Exception $e) {
                    $errores['fecha'] = "fecha Incorrecta";
                    $fecha = new \DateTime("now");
                }
                if($_FILES["imagenes"]["name"][0] == "")
                {
                    $erroresImagenes['imagenes'] = "Debes seleccionar al menos una imagen";
                }else{
                    $extensiones = ['image/jpeg','image/png','image/gif','image/jpg'];
                    foreach ($_FILES["imagenes"]["error"] as $key => $error) {
                        if ($error == UPLOAD_ERR_OK) {
                            if(!in_array($_FILES["imagenes"]["type"][$key],$extensiones))
                            {
                                $erroresImagenes['imagenes'] = "Formato incorrecto";
                            }else if($_FILES["imagenes"]["size"][$key] > 10485760)
                            {
                                $erroresImagenes["imagenes"] =  "Debes seleccionar una imagen con un tamaño inferior";
                            }elseif(count($_FILES["imagenes"]["name"]) > 10 )
                            {
                                $erroresImagenes["imagenes"] =  "No puedes subir mas de 10 imagenes";
                            }
                        }
                    }

                   
                }

                    $datosConcierto[0]['nombre'] = $_POST["nombre"];
                    $datosConcierto[0]['lugar'] = $_POST["lugar"];
                    $datosConcierto[0]['fecha'] = $_POST["fecha"];
                    $datosConcierto[0]['aforo'] = $_POST["aforo"];
                    $datosConcierto[0]['idArtista'] = $_POST["artistas"];
                    $datosConcierto[0]['numEntradasNormales'] = (int)$_POST["numEntradasNormales"];
                    $datosConcierto[0]['precioEntradasNormales'] = (float)$_POST["precioEntradasNormales"];
                    $datosConcierto[0]['numEntradasVip'] = (int)$_POST["numEntradasVip"];
                    $datosConcierto[0]['precioEntradasVip'] = (float)$_POST["precioEntradasVip"];
                    $datosConcierto[0]['latitud'] = (float)$_POST["latitud"];
                    $datosConcierto[0]['longitud'] = (float)$_POST["longitud"];

                
                
                    try {
                    $concierto = (new Concierto(['nombre'=>$_POST["nombre"],'lugar'=>$_POST["lugar"],'fecha'=>$fecha,'aforo' => (int)$_POST["aforo"],'idArtista'=>(int)$_POST['artistas'],'numEntradasNormales'=>(int)$_POST['numEntradasNormales'],'precioEntradasNormales'=>(float)$_POST['precioEntradasNormales'],'numEntradasVip'=>(int)$_POST['numEntradasVip'],'precioEntradasVip'=>(float)$_POST['precioEntradasVip'],'latitud'=>(float)$_POST['latitud'],'longitud'=>(float)$_POST['longitud']]));
                } catch (ConciertoException $ex) {
                $errores = $ex -> getErrores();
                }

                if(!isset($erroresImagenes['imagenes']) || empty($erroresImagenes['imagenes']))
                {
                if(!isset($errores))
                {
                    $conciertoBd = (new ConciertoRepositorio())->addConcierto($concierto);
                }


                if(isset($conciertoBd) && $conciertoBd != -1)
                {
                    $uploads_dir = '.web/imagenes';
                    foreach ($_FILES["imagenes"]["error"] as $key => $error) {
                        if ($error == UPLOAD_ERR_OK) {

                            $tmp_name = $_FILES["imagenes"]["tmp_name"][$key];
                            $extension = substr($_FILES['imagenes']['name'][$key],strpos($_FILES['imagenes']['name'][$key],'.')+1);
                            //Obtenemos la extension del archivo que estamos recorriendo a traves de la posicion del punto usando un substring
                            $name = basename($_FILES["imagenes"]["name"][$key]);
                            $destination_path = getcwd().DIRECTORY_SEPARATOR; //Ruta 
                            $nombreBd = time() .$conciertoBd . $key . '.' . $extension;
                            $target_path = $destination_path.  'web/imagenes/'.$nombreBd;
                            move_uploaded_file($_FILES['imagenes']['tmp_name'][$key], $target_path);
                            $imagenBd = (new ConciertoRepositorio())->addImagenConcierto($conciertoBd,$nombreBd);
                        }
                        
                    }
                    
                    $errores['conciertoCorrecto'] = "Concierto insertado con exito";
                    header('Location:index.php?ctl=listarConcierto');
                }else{
                    $errores['conciertoCorrecto'] = "Concierto no insertado con exito";
                }

            }

                
                
            }
            $artistas = (new ArtistaRepositorio())->getArtistas();
                $accion = 'añadir';
            require __DIR__ . '/../../app/plantillas/addConcierto.php';
        }else{
            $link = 'Location:index.php?ctl=login';
            header($link);
        }
        
    }

    public function verConcierto()
    { 
        if(isset($_GET["concierto"]) || isset($_POST['idConcierto']))
        {
            if(isset($_GET["concierto"])){
                $idConcierto = (int)$_GET["concierto"];
            }else{
                $idConcierto = (int)$_POST["concierto"];
            }
            $imagenesCarrusel = (new ConciertoRepositorio())->getImgsConcierto($idConcierto);

            $conciertos = (new ConciertoRepositorio) -> getConcierto($idConcierto);

            require __DIR__ . '/../../app/plantillas/infConcierto.php';
        }else{
            $error = "Concierto no encontrado";
            require __DIR__ . '/../../app/plantillas/error.php';
        }
        
    }

    public function updateConcierto():void
    {
        if(isset($_SESSION['usuario']) && $_SESSION['rol'] == 'ADMIN')
        {
            if(isset($_POST["Enviar"]))
            {
                $fechaTrans  = substr($_POST['fecha'],0,10)  . ' ' . substr($_POST['fecha'],11,2) . ':' . substr($_POST['fecha'],14,2) . ':' . '00';
                try {
                    $fecha = new \DateTime($fechaTrans);
                } catch (\Exception $e) {
                    $errores['fecha'] = "fecha Incorrecta";
                    $fecha = new \DateTime("now");
                }

                

                try {
                    $conciertos = (new Concierto(['nombre'=>$_POST["nombre"],'lugar'=>$_POST["lugar"],'fecha'=>$fecha,'aforo' => (int)$_POST["aforo"],'idArtista'=>(int)$_POST['artistas'],'numEntradasNormales'=>(int)$_POST['numEntradasNormales'],'precioEntradasNormales'=>(float)$_POST['precioEntradasNormales'],'numEntradasVip'=>(int)$_POST['numEntradasVip'],'precioEntradasVip'=>(float)$_POST['precioEntradasVip'],'latitud'=>(float)$_POST['latitud'],'longitud'=>(float)$_POST['longitud']]));
                } catch (ConciertoException $ex) {
                $errores = $ex -> getErrores();
                }

            
                if(!isset($errores))
                {
                    $conciertoBd = (new ConciertoRepositorio())->updateConcierto($conciertos,$_POST['codConcierto']);
                }

                if(isset($conciertoBd) && $conciertoBd)
                {
                    if(!isset($_FILES['imagenes']['size']) || $_FILES['imagenes']['size'] == 0)
                    {
                        $img = $_POST['imgConcierto']; //Imagen Antigua
                    }else{
                        unlink('./web/imagenes/'.$_POST['imgConcierto']);
                        $uploads_dir = '.web/imagenes';
                        foreach ($_FILES["imagenes"]["error"] as $key => $error) {
                            if ($error == UPLOAD_ERR_OK) {
        
                                $tmp_name = $_FILES["imagenes"]["tmp_name"][$key];
                                $extension = substr($_FILES['imagenes']['name'][$key],strpos($_FILES['imagenes']['name'][$key],'.')+1);
                                //Obtenemos la extension del archivo que estamos recorriendo a traves de la posicion del punto usando un substring
                                $name = basename($_FILES["imagenes"]["name"][$key]);
                                $destination_path = getcwd().DIRECTORY_SEPARATOR; //Ruta 
                                $nombreBd = time() . $_POST['codConcierto'] . $key . '.' . $extension;
                                $target_path = $destination_path.  'web/imagenes/'.$nombreBd;
                                move_uploaded_file($_FILES['imagenes']['tmp_name'][$key], $target_path);
                                $imagenBd = (new ConciertoRepositorio())->updateImagenConcierto($_POST['codConcierto'],$nombreBd);
                            }
                            
                        }

                        
                    }
                    $mensaje = "El concierto ha sido actualizado con éxito";
                    header('Location:index.php?ctl=listarConcierto');
                }else{
                    $mensaje = "El concierto no ha sido actualizado con éxito";
                }
               
            }
             if(isset($_GET['idConcierto']))
                {
                    $idConcierto = $_GET['idConcierto'];
                }
            $accion = 'update';
            $datosConcierto = (new ConciertoRepositorio())->getConcierto($_GET['idConcierto']);
                $artistas = (new ArtistaRepositorio())->getArtistas();
             require __DIR__ . '/../../app/plantillas/addConcierto.php';
        }else{
            $error = "Concierto no encontrado";
            require __DIR__ . '/../../app/plantillas/error.php';
        }
    }

    public function listarConcierto():void{
        $conciertos = (new ConciertoRepositorio())->getConciertos();
        require __DIR__ . '/../../app/plantillas/listarConcierto.php';
    }

    public function deleteConcierto():void{
        if(isset($_SESSION['usuario']) && $_SESSION['rol'] == 'ADMIN')
        {
            $getImagenes = (new ConciertoRepositorio())->getImgsConcierto($_GET['idConcierto']);
            for($i = 0 ; $i<sizeof($getImagenes);$i++)
            {
                unlink('./web/imagenes/'.$getImagenes[$i]['ruta']);
            }
            $imgConcierto = (new ConciertoRepositorio())->deleteImgConcierto($_GET['idConcierto']);
            $deleteEntradaConcierto = (new EntradaRepositorio())->deleteEntradaConcierto($_GET['idConcierto']);
            $deleteConcierto = (new ConciertoRepositorio())->deleteConcierto($_GET['idConcierto']);
            $conciertos = (new ConciertoRepositorio())->getConciertos();
            require __DIR__ . '/../../app/plantillas/listarConcierto.php';
        }else{
            $link = 'Location:index.php?ctl=login';
            header($link); 
        }
        
    }
    

    public function buscadorConcierto():void{
        $gustosMusicales = (new ArtistaRepositorio())->getGenerosMusicales();
        if(isset($_POST["Buscar"])){
            $condicion = "";
            if(isset($_POST["fecha"]) && $_POST["fecha"] != ''){
                $condicion .= 'c.fecha'.">='" . $_POST["fecha"] ."' AND ";
            }else if (isset($_POST["precio"]) && $_POST["precio"] != '')
            {
                $condicion .= 'c.precioEntradasNormales'."<='" . (int)$_POST["precio"] ."' AND ";
            }else if (isset($_POST["generoMusical"]) && $_POST["generoMusical"] != '')
            {
                $condicion .= 'a.generoMusical'."='" . $_POST["generoMusical"] ."' AND ";
            }
            $condicion = substr($condicion,0,-4);
            $cargarConciertos =  (new ConciertoRepositorio())->buscarConcierto($condicion);
            $imagenes = [];
            foreach($cargarConciertos as $clave => $value){
                $imagenesConcierto = (new ConciertoRepositorio)->getImagenConcierto($value['idConcierto']);
                $imagenes[$value['idConcierto']] = $imagenesConcierto[0]['ruta']; 
              }
            if(empty($cargarConciertos))
            {
                $error = "No hay conciertos disponibles";
            }
            
        }
        require __DIR__ . '/../../app/plantillas/buscador.php';
    }

    public function verImagenesConcierto()
    {
        if(isset($_SESSION['usuario']) && $_SESSION['rol'] == 'ADMIN')
        {
            if(isset($_POST['Enviar']))
            {
                 if($_FILES["imagenes"]["name"][0] == "")
                {
                    $erroresImagenes['imagenes'] = "Debes seleccionar al menos una imagen";
                }else
                {
                    $extensiones = ['image/jpeg','image/png','image/gif','image/jpg'];
                    foreach ($_FILES["imagenes"]["error"] as $key => $error) {
                        if ($error == UPLOAD_ERR_OK) {
                            if(!in_array($_FILES["imagenes"]["type"][$key],$extensiones))
                            {
                                $erroresImagenes['imagenes'] = "Formato incorrecto";
                            }else if($_FILES["imagenes"]["size"][$key] > 10485760)
                            {
                                $erroresImagenes["imagenes"] =  "Debes seleccionar una imagen con un tamaño inferior";
                            }elseif(count($_FILES["imagenes"]["name"]) > 10 )
                            {
                                $erroresImagenes["imagenes"] =  "No puedes subir mas de 10 imagenes";
                            }
                        }
                    }  
                }

                if(!isset($erroresImagenes['imagenes']))
                {
                     $uploads_dir = '.web/imagenes';
                $conciertoBd = $_POST['codConcierto'];
                    foreach ($_FILES["imagenes"]["error"] as $key => $error) {
                        if ($error == UPLOAD_ERR_OK) {

                            $tmp_name = $_FILES["imagenes"]["tmp_name"][$key];
                            $extension = substr($_FILES['imagenes']['name'][$key],strpos($_FILES['imagenes']['name'][$key],'.')+1);
                            //Obtenemos la extension del archivo que estamos recorriendo a traves de la posicion del punto usando un substring
                            $name = basename($_FILES["imagenes"]["name"][$key]);
                            $destination_path = getcwd().DIRECTORY_SEPARATOR; //Ruta 
                            $nombreBd = time() .$conciertoBd . $key . '.' . $extension;
                            $target_path = $destination_path.  'web/imagenes/'.$nombreBd;
                            move_uploaded_file($_FILES['imagenes']['tmp_name'][$key], $target_path);
                            $imagenBd = (new ConciertoRepositorio())->addImagenConcierto($conciertoBd,$nombreBd);
                        }
                        
                    }
                }
               
            }
            $getImagenes = (new ConciertoRepositorio())->getImgsConcierto($_GET['idConcierto']);
             require __DIR__ . '/../../app/plantillas/verImagenesConcierto.php';
        }else{
            $link = 'Location:index.php?ctl=login';
            header($link); 
        }
       
    }

    public function deleteImgConcierto(){
        if(isset($_SESSION['usuario']) && $_SESSION['rol'] == 'ADMIN'){
            $imgConcierto = (new ConciertoRepositorio())->getImgsConcierto($_GET['idConcierto']);
            if(count($imgConcierto) > 1)
            {
                $deleteImagen = (new ConciertoRepositorio())->deleteIdImgConcierto($_GET['idImagen']);
                
            }
              $link = 'Location:index.php?ctl=verImagenesConcierto&idConcierto='. $_GET['idConcierto'];
                header($link); 
        }else{
            $link = 'Location:index.php?ctl=login';
            header($link); 
        }
    }

}
