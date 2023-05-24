<?php
namespace ConciertosProyecto\app\controlador;
use ConciertosProyecto\app\Modelo\Artista;
use ConciertosProyecto\app\Modelo\ArtistaException;
use ConciertosProyecto\app\Repositorio\ArtistaRepositorio;
class ArtistaController
{ 
    public function addArtista()
    { 
        if(isset($_SESSION['usuario']) && $_SESSION['rol'] == 'ADMIN')
        {
                if(isset($_POST["Enviar"]))
                {
                    $erroresImagenes = [];
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
                                }elseif(count($_FILES["imagenes"]["name"]) > 1 )
                                {
                                    $erroresImagenes["imagenes"] =  "No puedes subir mas de 1 imagen";
                                }
                            }
                        }

                        $datosArtista[0]['nombre'] = $_POST["nombre"];
                        $datosArtista[0]['generoMusical'] = $_POST["generoMusical"];
                        $datosArtista[0]['pais'] = $_POST["pais"];
                        $datosArtista[0]['descripcion'] = $_POST["descripcion"];
                        

                    }

                    try{
                        $artista = (new Artista(['nombre'=>$_POST["nombre"],'generoMusical'=>$_POST["generoMusical"],'pais'=>$_POST["pais"],'descripcion'=>$_POST["descripcion"],'imagenes'=>$_FILES["imagenes"]["name"][0]]));
                    }catch (ArtistaException $ex) {
                        $errores = $ex -> getErrores();
                    }
                    if(!isset($errores) && $erroresImagenes == [])
                    {
                        $artistaBd = (new ArtistaRepositorio())->addArtista($artista); //Obtenemos el id del Artista
                        
                    }
                    
                    
                    if(isset($artistaBd) && $artistaBd != -1)
                    {
                        $uploads_dir = './web/imagenes/imagenArtista/';
                        
                        foreach ($_FILES["imagenes"]["error"] as $key => $error)
                        {
                            if ($error == UPLOAD_ERR_OK) {
                                $extension = substr($_FILES['imagenes']['name'][$key],strpos($_FILES['imagenes']['name'][$key],'.')+1);
                                $tmp_name = $_FILES["imagenes"]["tmp_name"][$key];
                                // basename() puede evitar ataques de denegación de sistema de ficheros;
                                // podría ser apropiada más validación/saneamiento del nombre del fichero
                                $nombreBd = time() .$artistaBd . $key . '.' . $extension;
                                move_uploaded_file($tmp_name, "$uploads_dir/$nombreBd");
                                $imagenArtista = (new ArtistaRepositorio())->updateImagenArtista($artistaBd,$nombreBd);
                            }                        
        
                        }
                        $errores['artistaCorrecto'] = "Artista insertado con exito";
                        header('Location:index.php?ctl=listarArtistas');
                    }else{
                        $errores['artistaCorrecto'] = "Artista no insertado con exito";
                    }
                }
                require __DIR__ . '/../../app/plantillas/addArtista.php';
        }else{
            $link = 'Location:index.php?ctl=login';
            header($link);
        }
        
    }

    public function updateArtista():void
    {
        if(isset($_SESSION['usuario']) && $_SESSION['rol'] == 'ADMIN')
        {
            if(isset($_POST["Enviar"]))
            {
                try{
                    $artista = (new Artista(['nombre'=>$_POST["nombre"],'descripcion'=>$_POST['descripcion'],'generoMusical'=>$_POST["generoMusical"],'pais'=>$_POST["pais"],'imagenes'=>$_POST['imgArtista']]));
                }catch (ArtistaException $ex) {
                    $errores = $ex -> getErrores();
                }
                if(!isset($errores))
                {
                    $artistaBd = (new ArtistaRepositorio())->updateArtista($artista,$_POST['codArtista']);
                }

             

                if(isset($artistaBd) && $artistaBd)
                {
                    $mensaje = "El artista ha sido actualizado con éxito";
                    if($_FILES['imagenes']['size'][0] == 0)
                    {
                        $img = $_POST['imgArtista']; //Imagen Antigua
                    }else{
                        unlink('./web/imagenes/imagenArtista/'.$_POST['imgArtista']);
                        $uploads_dir = './web/imagenes/imagenArtista/';
                        
                        foreach ($_FILES["imagenes"]["error"] as $key => $error)
                        {
                            if ($error == UPLOAD_ERR_OK) {
                                $extension = substr($_FILES['imagenes']['name'][$key],strpos($_FILES['imagenes']['name'][$key],'.')+1);
                                $tmp_name = $_FILES["imagenes"]["tmp_name"][$key];
                                // basename() puede evitar ataques de denegación de sistema de ficheros;
                                // podría ser apropiada más validación/saneamiento del nombre del fichero
                                $nombreBd = time() .$_POST['codArtista'] . $key . '.' . $extension;
                                move_uploaded_file($tmp_name, "$uploads_dir/$nombreBd");
                                $imagenArtista = (new ArtistaRepositorio())->updateImagenArtista($_POST['codArtista'],$nombreBd);
                            }

                        }

                    }
                    header('Location:index.php?ctl=listarArtistas');
                }else{
                    $mensaje = "El artista no ha sido actualizado con éxito";
                }
               
            }
            if(isset($_GET['idArtista']))
                {
                    $idArtista = $_GET['idArtista'];
                }
            $accion = 'update';
            $datosArtista = (new ArtistaRepositorio())->getArtista($_GET['idArtista']);
             require __DIR__ . '/../../app/plantillas/addArtista.php';
        }else{
            $link = 'Location:index.php?ctl=login';
            header($link);
        }
        
    }

    public function listarArtistas():void{
        $artistas = (new ArtistaRepositorio())->getArtistas();
        require __DIR__ . '/../../app/plantillas/listarArtistas.php';
    }

    public function deleteArtista():void{
        if(isset($_SESSION['usuario']) && $_SESSION['rol'] == 'ADMIN'){
            $conciertosArtistas = (new ArtistaRepositorio())->getConciertosArtista($_GET['idArtista']);
            if(count($conciertosArtistas) == 0){
                $artista = (new ArtistaRepositorio())->getArtista($_GET['idArtista']);
                unlink('./web/imagenes/imagenArtista/'.$artista[0]['imagenArtista']);
                $deleteArtista = (new ArtistaRepositorio())->deleteArtista($_GET['idArtista']);
                
            }else{
                $errores['conciertoArtista'] = 'Para eliminar un artista no debe tener conciertos asignados';
            }
            $artistas = (new ArtistaRepositorio())->getArtistas();        
            require __DIR__ . '/../../app/plantillas/listarArtistas.php';
        }else{
            $link = 'Location:index.php?ctl=login';
            header($link);
        }
        
    }
}
?>