<?php
namespace ConciertosProyecto\app\core;
use ConciertosProyecto\app\configuracion;
require_once __DIR__ . '/../app/conf/config.inc';

class ConexionBd
{ private $con;

  public function __construct()
  { $params = (new Configuracion())->getDbParams();

  $dsn = 'mysql:dbname=dbs10502680;host=db5012491916.hosting-data.io;port=3306';
  $usuario = "dbu1658396";
  $password = "Diego$1234";

    try
    { /*$this->con = new \PDO("mysql:host={$params['server']},{$params['port']};
                            dbname={$params['dbname']}",
                           $params['user'], $params['pass']);*/
        $this->con = new \PDO($dsn,$usuario,$password);
      $this->con->setAttribute(\PDO::ATTR_ERRMODE, \PDO::ERRMODE_EXCEPTION);
    }catch(\PDOException $ex)
    { die("Error de conexión ".$ex->getMessage());
    }
  }
  public function getConexion()
  { return $this->con;
  }
}
