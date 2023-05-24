<?php
namespace ConciertosProyecto\app\Repositorio;
use ConciertosProyecto\app\Modelo\Hilos;
use ConciertosProyecto\app\Modelo\Comentario;
use ConciertosProyecto\app\core\ConexionBd;
class ForoRepositorio
{
    public function addHilo(Hilos $hilo):bool
    {
        $sql = "INSERT INTO HilosForo(titulo,descripcion) SELECT :titl,:desc FROM DUAL 
        WHERE NOT EXISTS (SELECT * FROM HilosForo WHERE titulo = '" . $hilo->getTitulo() . "') ";
        require_once __DIR__ . '/../../core/conexionBd.inc';
        try {
            $con = (new ConexionBd())->getConexion();
            $con->beginTransaction(); // Iniciamos transacción
            $snt = $con->prepare($sql);
            $snt->bindValue(":titl",$hilo->getTitulo());
            $snt->bindValue(":desc",$hilo->getDescripcion());
            $snt->execute();
            $con->commit();
            return true;
        } catch (\Exception $ex) {
            $con->rollback();
            throw $ex;
            return false;
        }finally
        {
            unset($con);
            unset($snt);
        }
    }

    
    


    public function getTemasHilos():array {
        $sql = "SELECT * FROM HilosForo";
        require_once __DIR__ . '/../../core/conexionBd.inc';
        try {
            $con = (new ConexionBd())->getConexion();
            $snt = $con->prepare($sql);
            $snt->execute();
            return $snt->fetchAll(\PDO::FETCH_ASSOC);
        } catch (\Exception $ex) {
            throw $ex;
            return ($error = []);
        }finally{
            unset($con);
            unset($snt);
        }
    }

    public function getMensajesHilos(int $codHilo):int {
        $sql = "SELECT count(c.idComentario) FROM Comentarios c LEFT JOIN HilosForo hf ON hf.idHilo = c.idHilo WHERE hf.idHilo = :codHilo";
        require_once __DIR__ . '/../../core/conexionBd.inc';
        try {
            $con = (new ConexionBd())->getConexion();
            $snt = $con->prepare($sql);
            $snt->bindValue(":codHilo",$codHilo);
            $snt->execute();
            return $snt->fetchAll(\PDO::FETCH_ASSOC);
        } catch (\Exception $ex) {
            throw $ex;
            return ($error = []);
        }finally{
            unset($con);
            unset($snt);
        }
    }


    public function getHilo(int $codHilo):array
    {
        $sql = "SELECT * FROM HilosForo  WHERE idHilo = :codHilo";
        require_once __DIR__ . '/../../core/conexionBd.inc';
        try {
            $con = (new ConexionBd())->getConexion();
            $snt = $con->prepare($sql);
            $snt->bindValue(":codHilo",$codHilo);
            $snt->execute();
            return $snt->fetchAll(\PDO::FETCH_ASSOC);
        } catch (\Exception $ex) {
            throw $ex;
            return ($error = []);
        }finally{
            unset($con);
            unset($snt);
        }
    }

    public function addComentarioHilo(Comentario $comentario):int
    {
       
        $sql = "INSERT INTO Comentarios(titulo,descripcion,fecha,idUsuario,idHilo) VALUES (:titl,:desc,:fecha,:codUsuario,:codHilo)";
        require_once __DIR__ . '/../../core/conexionBd.inc';
        try {
            $con = (new ConexionBd())->getConexion();
            $con->beginTransaction(); // Iniciamos transacción
            $fecha = $comentario->getFecha()->format('Y-m-d H:i:s');
            $fecha = str_replace(" ", "T",$fecha );
            $snt = $con->prepare($sql);
            $snt->bindValue(":titl",$comentario->getTitulo());
            $snt->bindValue(":desc",$comentario->getDescripcion());
            $snt->bindValue(":fecha",$fecha);
            $snt->bindValue(":codUsuario",$comentario->getIdUsuario());
            $snt->bindValue(":codHilo",$comentario->getIHilos());
            $snt->execute();
            $con->commit();
            $resultado = $con->lastInsertId();
            return intval($resultado);
        } catch (\Exception $ex) {
            $con->rollback();
            throw $ex;
            return -1;
        }finally
        {
            unset($con);
            unset($snt);
        }
    }


    public function getComentario(int $codHilo):array
    {
       
        $sql = "SELECT usu.*,com.* FROM Comentarios com LEFT JOIN Usuarios usu ON usu.idUsuario = com.idUsuario  WHERE com.idHilo = :codHilo";
        require_once __DIR__ . '/../../core/conexionBd.inc';
        try {
            $con = (new ConexionBd())->getConexion();
            $snt = $con->prepare($sql);
            $snt->bindValue(":codHilo",$codHilo);
            $snt->execute();
            return $snt->fetchAll(\PDO::FETCH_ASSOC);
        } catch (\Exception $ex) {
            throw $ex;
            return ($error = []);
        }finally{
            unset($con);
            unset($snt);
        }
    }

    public function deleteComentario(int $codComentario,int $codUsuario):bool
    {
       
        $sql = "DELETE FROM Comentarios WHERE idComentario = :codComentario AND idUsuario = :codUsuario";
        require_once __DIR__ . '/../../core/conexionBd.inc';
        try {
            $con = (new ConexionBd())->getConexion();
            $snt = $con->prepare($sql);
            $snt->bindValue(":codComentario",$codComentario);
            $snt->bindValue(":codUsuario",$codUsuario);
            $snt->execute();
            return true;
        } catch (\Exception $ex) {
            throw $ex;
            return false;
        }finally{
            unset($con);
            unset($snt);
        }
    }

    public function deleteHilo(int $codHilo):bool
    {
       
        $sql = "DELETE FROM HilosForo WHERE idHilo = :codHilo";
        require_once __DIR__ . '/../../core/conexionBd.inc';
        try {
            $con = (new ConexionBd())->getConexion();
            $snt = $con->prepare($sql);
            $snt->bindValue(":codHilo",$codHilo);
            $snt->execute();
            return true;
        } catch (\Exception $ex) {
            throw $ex;
            return false;
        }finally{
            unset($con);
            unset($snt);
        }
    }

    public function updateHilo(Hilos $hilos,int $codHilo):bool
    {
        $sql = "UPDATE HilosForo SET titulo = :titl , descripcion = :desc  WHERE idHilo = :codHilo";
        require_once __DIR__ . '/../../core/conexionBd.inc';
        try {
            $con = (new ConexionBd())->getConexion();
            $snt = $con->prepare($sql);
            $snt->bindValue(":titl",$hilos->getTitulo());
            $snt->bindValue(":desc",$hilos->getDescripcion());
            $snt->bindValue(":codHilo",$codHilo);
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

    public function deleteComentariosHilo(int $codHilo):bool
    {
       
        $sql = "DELETE FROM Comentarios  WHERE idHilo = :codHilo";
        require_once __DIR__ . '/../../core/conexionBd.inc';
        try {
            $con = (new ConexionBd())->getConexion();
            $snt = $con->prepare($sql);
            $snt->bindValue(":codHilo",$codHilo);
            $snt->execute();
            return true;
        } catch (\Exception $ex) {
            throw $ex;
            return false;
        }finally{
            unset($con);
            unset($snt);
        }
    }

    

    

    

    
}