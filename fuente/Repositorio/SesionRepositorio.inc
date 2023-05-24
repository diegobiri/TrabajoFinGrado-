<?php
namespace ConciertosProyecto\app\Repositorio;
use ConciertosProyecto\app\core\ConexionBd; 
class SesionRepositorio
{
    public function getSesion(string $usu):?array
    {
        $sql = "SELECT pass, rol FROM sesion WHERE email = :usu";

        $pass = null;

        $rol = null;

        require_once __DIR__ . '../../../core/conexionBd.inc';

        try {
            $con = (new ConexionBd())->getConexion();
            $snt = $con->prepare($sql);
            $snt->bindValue(':usu', $usu);
            $snt->execute();
            $snt->bindColumn('pass', $pass);
            $snt->bindColumn('rol', $rol);
            $snt->fetch(\PDO::FETCH_ASSOC);
            if(is_null($pass))
                return null;
            else    
                return ['pass'=>$pass,'rol'=>$rol];
        } catch (\PDOException $ex) {
            throw $ex;
        } finally{
            unset($snt);
            unset($con);
        }
        
    }

    public function addSesion(int $idUsuario) : int
    {
      $sql = "INSERT INTO sesion (idUsuario, fInicio,fFin) VALUES (:idUsuario,:fInicio,null)";
  
      require_once __DIR__ . "../../../core/conexionBd.inc";
      try {
        $con = (new ConexionBd())->getConexion();
        $con->beginTransaction(); // Iniciamos transacción
        $snt = $con->prepare($sql);
         $fecha = (new \DateTime('now'))->format('Y-m-d H:i:s');
        $fecha = str_replace(" ", "T",$fecha );
            $snt->bindValue(":fInicio",$fecha);
        $snt->bindValue(':idUsuario', $idUsuario);
        $snt->execute();
        $resultado = $con->lastInsertId();
        $con->commit(); // Todo ha ido bien, hacemos commit
        return $resultado;
      } catch (\PDOException $ex) {
        $con->rollBack(); // Ha saltado una excepción, hacemos rollback del procedimiento
        throw $ex;
        return -1;
      }finally {
        unset($snt);
        unset($con);
      }
    }

    public function updateFechaFinSesion(int $idSesion):bool
    {
        $sql = "UPDATE Sesion SET fFin = :fFin WHERE idSesion = :idSesion";
        require_once __DIR__ . '/../../core/conexionBd.inc';
        try {
            $con = (new ConexionBd())->getConexion();
            $snt = $con->prepare($sql);
            $fecha = (new \DateTime('now'))->format('Y-m-d H:i:s');
        $fecha = str_replace(" ", "T",$fecha );
            $snt->bindValue(":fFin",$fecha);
            $snt->bindValue(":idSesion",$idSesion);
            $snt->execute();
            return true;
        } catch (\Exception $ex) {
            throw $ex;
            return false;
        }finally
        {
            unset($con);
            unset($snt);
        }
    }

    public function getEmailUsu(string $email):array
    {
      $sql = "SELECT email FROM usuarios WHERE email = :ema";
  
      require_once __DIR__ . "../../../core/conexionBd.inc";
      try {
        $con = (new ConexionBd())->getConexion();
        $snt = $con->prepare($sql);
        $snt->bindValue(':ema', $email);
        $snt->execute();
        return $snt->fetchAll(\PDO::FETCH_ASSOC);
      } catch (\PDOException $ex) {
        throw $ex;
        return $error = [];
      }finally {
        unset($snt);
        unset($con);
      }
    }

    public function updatePass(string $email,string $pass):array
    {
      $sql = "UPDATE usuarios SET pass = :pass  WHERE email = :ema";
  
      require_once __DIR__ . "../../../core/conexionBd.inc";
      try {
        $con = (new ConexionBd())->getConexion();
        $snt = $con->prepare($sql);
        $pass = password_hash($pass, PASSWORD_DEFAULT);
        $snt->bindValue(':pass', $pass);
        
        $snt->bindValue(':ema', $email);
        $snt->execute();
        return $snt->fetchAll(\PDO::FETCH_ASSOC);
      } catch (\PDOException $ex) {
        throw $ex;
        return $error = [];
      }finally {
        unset($snt);
        unset($con);
      }
    }
    
}
?>