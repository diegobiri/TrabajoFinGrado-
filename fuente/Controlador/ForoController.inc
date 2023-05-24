<?php

namespace ConciertosProyecto\app\controlador;
use ConciertosProyecto\app\Modelo\Hilos;
use ConciertosProyecto\app\Modelo\HilosException;
use ConciertosProyecto\app\Modelo\Comentario;
use ConciertosProyecto\app\Modelo\ComentarioException;
use ConciertosProyecto\app\Repositorio\ForoRepositorio;
use ConciertosProyecto\app\Repositorio\RegistroRepositorio;

class ForoController
{
    public function crearHilosForo()
    {
        if(isset($_SESSION['usuario']) && $_SESSION['rol'] == 'ADMIN')
        {
            if(isset($_POST["crear"]))
            {
                try {
                    
                    $hilo = (new Hilos(['titulo'=>$_POST["titulo"],'descripcion'=>$_POST["descripcion"]]));
                } catch (HilosException $ex) {
                    $errores = $ex -> getErrores();
                }
                if(!isset($errores))
                {
                    $hiloBd = (new ForoRepositorio())->addHilo($hilo);
                    header('Location:index.php?ctl=listarTemasAdmin');
                }else{
                    $errores['hilo'] = "Error al crear el hilo";
                }
            }
        }else{
            $link = 'Location:index.php?ctl=login';
            header($link);
        }
        

        require __DIR__ . '/../../app/plantillas/crearHilosForo.php';
    }

    public function listarHilos():void{
        $hilos = (new ForoRepositorio())->getTemasHilos();
        require __DIR__ . '/../../app/plantillas/listarHilos.php';
    }

    public function listarTemasAdmin():void{
        $hilos = (new ForoRepositorio())->getTemasHilos();
        require __DIR__ . '/../../app/plantillas/listarTemasAdmin.php';
    }

    public function deleteTemasAdmin():void{
         if(isset($_SESSION['usuario']) && $_SESSION['rol'] == 'ADMIN')
         {
            $deleteComentario = (new ForoRepositorio())->deleteComentariosHilo($_GET['idHilo']);
            $borrarHilo = (new ForoRepositorio())->deleteHilo($_GET['idHilo']);      
            $link = 'Location:index.php?ctl=listarTemasAdmin';
            header($link);
         }else{
             $link = 'Location:index.php?ctl=login';
            header($link);
         }
        
    }

    public function updateHilo():void
    {

        if(isset($_SESSION['usuario']) && $_SESSION['rol'] == 'ADMIN')
        {
            if(isset($_POST["crear"]))
            {
                try {
                    
                    $hilo = (new Hilos(['titulo'=>$_POST["titulo"],'descripcion'=>$_POST["descripcion"]]));
                } catch (HilosException $ex) {
                    $errores = $ex -> getErrores();
                }
                if(!isset($errores))
                {
                    $hiloBd = (new ForoRepositorio())->updateHilo($hilo,$_POST['codHilo']);
                    header('Location:index.php?ctl=listarTemasAdmin');
                }
            }
            $hilos = (new ForoRepositorio())->getHilo($_GET["codHilo"]);
            require __DIR__ . '/../../app/plantillas/crearHilosForo.php';
        }else{
            $link = 'Location:index.php?ctl=login';
            header($link);
        }
        

        
    }

    
    public function verTema():void{
        $hilo = (new ForoRepositorio())->getHilo($_GET['idHilo']);
        if(isset($_POST['Enviar']))
        {
            if(isset($_SESSION['usuario']))
            {
                $idUsuario = (new RegistroRepositorio())->getUsuarioEmail($_SESSION['usuario']);
                try {
                    $comentario = (new Comentario(['titulo'=>$_POST["titulo"],'descripcion'=>$_POST["descripcion"],'idUsuario'=>$idUsuario[0]["idUsuario"],'idHilos'=>intval($_POST["hilo"])]));
                    
                } catch (ComentarioException $ex) {
                    $errores = $ex -> getErrores();
                }

                if(!isset($errores))
                {
                    $comentarioBd = (new ForoRepositorio())->addComentarioHilo($comentario);
                    if(isset($comentarioBd) && $comentarioBd != -1)
                    {
                        $errorComentario = "Comentario insertado con exito";
                    }else{
                        $errorComentario = "Ha habido un problema en el comentario";
                    }
                }
            }else{
                $errorComentario = "Debe estar logueado en la pagina para poder publicar un comentario";
            }
        }

        if(isset($_GET["idComentario"]))
        {
            $idUsuario = (new RegistroRepositorio())->getUsuarioEmail($_SESSION['usuario']);
            $delComentario = (new ForoRepositorio())->deleteComentario($_GET['idComentario'],$idUsuario[0]['idUsuario']);
            if($delComentario == true)
            {
                $errorComentario = "Comentario Borrado con Exito";
            }
        }
        $allComentario = (new ForoRepositorio())->getComentario($_GET['idHilo']);
        require __DIR__ . '/../../app/plantillas/verTema.php';
    }
    

    

    
}