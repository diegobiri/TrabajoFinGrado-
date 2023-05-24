<?php
/* configuraciones comunes a la aplicación */
namespace ConciertosProyecto\app;
class configuracion
{ private $dbParams = []; /*Vector con parámetros de configuración del SGBD */

  public function __construct()
  { $this->dbParams = ["driver"=>"mysql", //no utilizada realmente
                       "server"=>"db5012317337.hosting-data.io", //nombre servidor
                       "port"=>"3306", //puerto por el que escucha las peticiones de la aplicación
                       "dbname"=>"dbs10361756", //nombre de la base de datos
                       "user"=>"dbu2279743", //usuario definido para la aplicación
                       "pass"=>"Diego$1234", //contraseña del usuario
                       "charset"=>"utf-8"]; //conjunto de caracteres
  }

  public function getDbParams(): Array
  { return $this->dbParams;
  }
}
