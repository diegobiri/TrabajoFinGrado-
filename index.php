<?php

//index.php
session_start();
error_reporting(E_ALL);
use ConciertosProyecto\app\core\ConexionBd;
use ConciertosProyecto\app\controlador\UsuarioController;
use ConciertosProyecto\app\controlador\ConciertoController;
use ConciertosProyecto\app\controlador\ArtistaController;
use ConciertosProyecto\app\controlador\CarritoController;
use ConciertosProyecto\app\controlador\ForoController;
use ConciertosProyecto\app\controlador\PHPMailer;
use ConciertosProyecto\app\controlador\SMTP;
use ConciertosProyecto\app\controlador\QrCode;
use ConciertosProyecto\app\controlador\FPDF;
use ConciertosProyecto\app\controlador\Exception;
require_once __DIR__ . '/fuente/Controlador/defaultController.inc'; /*controladores */
require_once __DIR__ . '/app/conf/rutas.inc'; /*Ubicación del archivo de rutas*/
require_once __DIR__ . '/fuente/Controlador/UsuarioController.inc';
require_once __DIR__ . '/fuente/Controlador/ConciertoController.inc';
require_once __DIR__ . '/fuente/Controlador/CarritoController.inc';
require_once __DIR__ . '/fuente/Controlador/PHPMailer.inc';
require_once __DIR__ . '/fuente/Controlador/SMTP.inc';
require_once __DIR__ . '/fuente/Controlador/FPDF.inc';

require_once __DIR__ . '/fuente/Controlador/Exception.inc';
require_once __DIR__ . '/web/funciones/funciones.php';
// Parseo de la ruta
if (isset($_GET['ctl']))
{ if (isset($mapeoRutas[$_GET['ctl']]))
  { $ruta = $_GET['ctl'];
  }else
  { header('Status: 404 Not Found');
    echo '<html><body><h1>Error 404: No existe la ruta <i>' .
          $_GET['ctl'] .
          '</p></body></html>';
    exit;
  }
}else
{ $ruta = 'inicio';
}

spl_autoload_register(function(string $class){
  if(str_contains($class, 'Repositorio')){
    $rutaAutoload = str_replace('\\','/',str_replace( 'ConciertosProyecto\\app\\', '', $class));
    require_once __DIR__.'/fuente/'.$rutaAutoload.'.inc';
  }
  else if(str_contains($class, 'core')){
    $rutaAutoload = str_replace('\\','/',str_replace( 'ConciertosProyecto\\app\\', '', $class));
    require_once __DIR__. '/'.$masAplauda.'.inc';
  }
  else{
    if(strpos($class, 'ConciertosProyecto\\app\\')===0){
      $rutaAutoload = str_replace('\\','/',str_replace( 'ConciertosProyecto\\app\\', '', $class));
      require_once __DIR__.'/fuente/'.$rutaAutoload.'.inc';
    }
  }
});


$controlador = $mapeoRutas[$ruta];
// Ejecución del controlador asociado a la ruta

if (method_exists($controlador['controller'],$controlador['action']))
{ call_user_func(array(new $controlador['controller'], $controlador['action']));
}else
{ header('Status: 404 Not Found');
  echo '<html><body><h1>Error 404: El controlador <i>' .
       $controlador['controller'] .
       '->' . $controlador['action'] .
       '</i> no existe</h1></body></html>';
}
