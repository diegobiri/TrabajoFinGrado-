<?php
/* configuraciones comunes a la aplicación */
namespace ConciertosProyecto\app;
class configuracion
{ private $dbParams = []; /*Vector con parámetros de configuración del SGBD */

  public function __construct()
  { $this->dbParams = ["driver"=>"mysql", //no utilizada realmente
                       "server"=>"localhost", //nombre servidor
                       "port"=>"3308", //puerto por el que escucha las peticiones de la aplicación
                       "dbname"=>"conciertoslarioja", //nombre de la base de datos
                       "user"=>"root", //usuario definido para la aplicación
                       "pass"=>"", //contraseña del usuario
                       "charset"=>"utf-8"]; //conjunto de caracteres
  }

  public function getDbParams(): Array
  { return $this->dbParams;
  }
}
