<?php
namespace ConciertosProyecto\app\Repositorio;
use ConciertosProyecto\app\core\ConexionBd;
class EntradaRepositorio
{
    public function addEntradasConcierto(int $idConcierto,int $precio,string $tipEntrada,int $idUsuario):int
    {
        $sql = " INSERT INTO Entrada (idUsuario,idConcierto,precio,tipoEntrada,fecha) VALUES (:idUsu,:id,:prec,:tipEntrada,:fecha)";
        require_once __DIR__ . '/../../core/conexionBd.inc';
        try{
            $con = (new ConexionBd())->getConexion();
            $snt = $con->prepare($sql);
            $snt->bindValue(":idUsu",$idUsuario);
            $snt->bindValue(":id",$idConcierto);
            $snt->bindValue(":tipEntrada",$tipEntrada);
            $snt->bindValue(":prec",$precio);
            $fecha = (new \DateTime("now"))->format('Y-m-d H:i:s');
            $fecha = str_replace(" ", "T",$fecha );
            $snt->bindValue(":fecha",$fecha);
            $snt->execute();
            $resultado = $con->lastInsertId();
            return $resultado;
        }catch(\Exception $ex){
            throw $ex;
            return -1;
        }finally{
            unset($snt);
            unset($con);
        }

    }


/*TODAS LAS ENTRADAS DEL USUARIO*/
    public function getEntradasUsuario(int $idUsuario):array 
    {
        $sql = "SELECT c.*,a.*,e.*,c.nombre as nombreConcierto, a.nombre as nombreArtista  FROM Entrada e LEFT JOIN Conciertos c ON e.idConcierto = c.idConcierto LEFT JOIN Artista a ON a.idArtista = c.idArtista  WHERE e.idUsuario = :idUsuario";
        require_once __DIR__ . '/../../core/conexionBd.inc';
        try {
            $con = (new ConexionBd())->getConexion();
            $snt = $con->prepare($sql);
            $snt->bindValue(":idUsuario",$idUsuario);
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

    public function deleteEntradaConcierto(int $codConcierto):bool
    {
        $sql = "DELETE FROM Entrada WHERE idConcierto = :codConcierto";
        require_once __DIR__ . '/../../core/conexionBd.inc';
        try {
            $con = (new ConexionBd())->getConexion();
            $snt = $con->prepare($sql);
            $snt->bindValue(":codConcierto",$codConcierto);
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

    public function getEntradas():array 
    {
        $sql = "SELECT c.*,a.*,e.*,c.nombre as nombreConcierto, a.nombre as nombreArtista  FROM Entrada e LEFT JOIN Conciertos c ON e.idConcierto = c.idConcierto LEFT JOIN Artista a ON a.idArtista = c.idArtista";
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

    public function getEntrada(int $codEntrada):array 
    {
        $sql = "SELECT *  FROM Entrada  WHERE idEntrada = :codEntrada";
        require_once __DIR__ . '/../../core/conexionBd.inc';
        try {
            $con = (new ConexionBd())->getConexion();
            $snt = $con->prepare($sql);
            $snt->bindValue(":codEntrada",$codEntrada);
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


    

    public function deleteEntrada(int $codEntrada):bool
    {
        $sql = "DELETE FROM Entrada WHERE idEntrada = :codEntrada";
        require_once __DIR__ . '/../../core/conexionBd.inc';
        try {
            $con = (new ConexionBd())->getConexion();
            $snt = $con->prepare($sql);
            $snt->bindValue(":codEntrada",$codEntrada);
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

    public function getEntradaUsuario(int $codEntrada):array 
    {
        $sql = "SELECT e.idEntrada,e.idUsuario,e.tipoEntrada,e.precio,c.nombre as nombreConcierto,c.lugar,a.nombre as nombreArtista,c.fecha,c.precioEntradasNormales,c.precioEntradasVip  FROM Entrada e   LEFT JOIN Conciertos c ON c.idConcierto = e.idConcierto LEFT JOIN Artista a ON a.idArtista = c.idArtista WHERE e.idEntrada = :codEntrada LIMIT 1";
        require_once __DIR__ . '/../../core/conexionBd.inc';
        try {
            $con = (new ConexionBd())->getConexion();
            $snt = $con->prepare($sql);
            $snt->bindValue(":codEntrada",$codEntrada);
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

    
}