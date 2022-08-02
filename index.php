<?php
//index.php
session_start();
error_reporting(E_ALL);
use ConciertosProyecto\app\core\ConexionBd;
use ConciertosProyecto\app\controlador\usuarioController;
require_once __DIR__ . '/fuente/Controlador/defaultController.inc'; /*controladores */
require_once __DIR__ . '/app/conf/rutas.inc'; /*Ubicación del archivo de rutas*/
require_once __DIR__ . '/fuente/Controlador/usuarioController.inc';



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

spl_autoload_register(function(string $clase){
  if(str_contains($clase, 'Repositorio')){
    $mesa = str_replace( 'ConciertosProyecto\\app\\', '', $clase);
    $masAplauda = str_replace('\\', '/', $mesa);
    require_once __DIR__.'/fuente/'.$masAplauda.'.inc';
  }
  else if(str_contains($clase, 'core')){
    $mesa = str_replace('ConciertosProyecto\\app\\', '', $clase);
    $masAplauda = str_replace('\\', '/', $mesa);
    require_once __DIR__. '/'.$masAplauda.'.inc';
  }
  else{
    if(strpos($clase, 'ConciertosProyecto\\app\\')===0){
      $ruta = str_replace( 'ConciertosProyecto\\app\\', '', $clase);
      $cosa = str_replace('\\', '/', $ruta);
      require_once __DIR__.'/fuente/'.$cosa.'.inc';
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
