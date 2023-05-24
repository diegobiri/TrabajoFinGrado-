<?php
// Ejemplo de controlador para página home de la aplicación
namespace ConciertosProyecto\app\controlador;
use ConciertosProyecto\app\Repositorio\SesionRepositorio;
use ConciertosProyecto\app\Repositorio\ConciertoRepositorio;
use ConciertosProyecto\app\Repositorio\ArtistaRepositorio;
use ConciertosProyecto\app\Repositorio\RegistroRepositorio;
class DefaultController
{ public function inicio()
  {
    $conciertos = (new ConciertoRepositorio)->getConciertosPortada();
    $conciertosCarrousel = (new ConciertoRepositorio)->getConciertosCarrousel();
    $artistas = (new ArtistaRepositorio)->getArtistaPortada();
    $imagenes = [];
    foreach($conciertos as $clave => $value){
      $imagenesConcierto = (new ConciertoRepositorio)->getImagenConcierto($value['idConcierto']);
      $imagenes[$value['idConcierto']] = $imagenesConcierto[0]['ruta']; 
    }
    require __DIR__ . '/../../app/plantillas/inicio.php';
  
  }

  public function logIn()
  {
      if(isset($_POST['ok']))
      {
            if(empty($_POST['email']) || empty($_POST['pass']))
            {
                $error = true;
            }else
            {
                $sesion = (new RegistroRepositorio())->getSesion($_POST['email']);
                if(isset($sesion[0])){
                  $sesion = $sesion[0];
                if(is_null($sesion) || empty($sesion) || !password_verify($_POST['pass'],$sesion['pass']))
                {
                    $error = true;
                }else
                {
                    $_SESSION['usuario'] = $_POST['email'];
                    $_SESSION['idSesion'] = (new SesionRepositorio())->addSesion($sesion['idUsuario']);
                    $_SESSION['id'] = $sesion['idUsuario'];
                    $_SESSION['rol'] = $sesion['rol'];
                    if(!isset($_POST["codConcierto"]) || $_POST["codConcierto"] != "")
                    {
                      header('Location:index.php?ctl=infConcierto&concierto='.$_POST["codConcierto"]);
                    }else{
                      header('Location:index.php?ctl=inicio');
                    }
                }
            }     
        }
      }
    require __DIR__ . '/../../app/plantillas/login.php';
  }

  public function logOut()
  {

       $sesion = (new SesionRepositorio())->updateFechaFinSesion($_SESSION['idSesion']);
    session_destroy();
      session_unset();
      session_abort();
      header('location: index.php');  
      
  }

  
}
