<?php
namespace ConciertosProyecto\app\Repositorio;
use ConciertosProyecto\app\Modelo\Concierto;
use ConciertosProyecto\app\core\ConexionBd;
class ConciertoRepositorio
{
    //Funcion que me permite crear un concierto mediante el uso de una Transaccion
    public function addConcierto(Concierto $concierto):int
    {
        $sql = "INSERT INTO conciertos(nombre,fecha,lugar,aforo,idArtista,numEntradasNormales,precioEntradasNormales,numEntradasVip,precioEntradasVip,latitud,longitud) SELECT :nom,:fcha,:lug,:aforo,:idArt,:numEntNorm,:precEntNorm,:numEntVip,:precEntVip,:lat,:long FROM DUAL WHERE NOT EXISTS (SELECT * FROM Conciertos WHERE nombre = '" . $concierto->getNombre() . "')";
        require_once __DIR__ . '/../../core/conexionBd.inc';
        try {
            $con = (new ConexionBd())->getConexion();
            $con->beginTransaction(); // Iniciamos transacción
            $snt = $con->prepare($sql);
            $snt->bindValue(":nom",$concierto->getNombre());
            $fecha = ($concierto->getFecha())->format('Y-m-d H:i:s');
            $fecha = str_replace(" ", "T",$fecha );
            $snt->bindValue(":fcha",$fecha);
            $snt->bindValue(":lug",$concierto->getLugar());
            $snt->bindValue(":aforo",$concierto->getAforo());
            $snt->bindValue(":idArt",$concierto->getIdArtista());
            $snt->bindValue(":numEntNorm",$concierto->getNumEntradasNormales());
            $snt->bindValue(":precEntNorm",$concierto->getPrecioEntradasNormales());
            $snt->bindValue(":numEntVip",$concierto->getNumEntradasVip());
            $snt->bindValue(":precEntVip",$concierto->getPrecioEntradasVip());
            $snt->bindValue(":lat",$concierto->getLatitud());
            $snt->bindValue(":long",$concierto->getLongitud());
            $snt->execute();
            $resultado = $con->lastInsertId();
            $con->commit();
            
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

    public function getConcierto(int $codConcierto):array {
        $sql = "SELECT art.idArtista as idArtista,c.latitud as latitud ,c.longitud as longitud,c.aforo as aforo,c.nombre as nombre,c.idConcierto as idConcierto , c.fecha as fecha , c.lugar as lugar , imc.ruta as ruta ,  art.nombre as nombreArtista , art.generoMusical as generoMusical, art.descripcion as descripcion, art.imagenArtista as imagenArtista, c.precioEntradasNormales as precioEntradasNormales, c.precioEntradasVip as precioEntradasVip, c.numEntradasNormales as numEntradasNormales,  c.numEntradasVip as numEntradasVip FROM Conciertos c RIGHT JOIN ImagenesConcierto imc ON imc.idConcierto = c.idConcierto LEFT JOIN Artista art ON art.idArtista = c.idArtista WHERE c.idConcierto = :idConcierto";
        require_once __DIR__ . '/../../core/conexionBd.inc';
        try {
            $con = (new ConexionBd())->getConexion();
            $snt = $con->prepare($sql);
            $snt->bindValue(":idConcierto",$codConcierto);
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


    public function getConciertosPortada():array {

        $sql = "SELECT * FROM Conciertos  WHERE fecha >= :fecha LIMIT 6";
        require_once __DIR__ . '/../../core/conexionBd.inc';
        try {
            $con = (new ConexionBd())->getConexion();
            $snt = $con->prepare($sql);
            $fecha = (new \DateTime("now"))->format('Y-m-d H:i:s');
            $fecha = str_replace(" ", "T",$fecha );
            
            $snt->bindValue(":fecha",$fecha);
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

    public function getImagenConcierto(int $idConcierto):array {
        $sql = "SELECT ruta,idConcierto  FROM ImagenesConcierto  WHERE idConcierto = :idConcierto ORDER BY RAND () LIMIT 1";
        require_once __DIR__ . '/../../core/conexionBd.inc';
        try {
            $con = (new ConexionBd())->getConexion();
            $snt = $con->prepare($sql);
            $snt->bindValue(":idConcierto",$idConcierto);
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

     public function getConciertosCarrousel():array {

        $sql = "SELECT * FROM Conciertos con WHERE fecha >= :fecha ORDER BY RAND () LIMIT 3";
        require_once __DIR__ . '/../../core/conexionBd.inc';
        try {
            $con = (new ConexionBd())->getConexion();
            $snt = $con->prepare($sql);
            $fecha = (new \DateTime("now"))->format('Y-m-d H:i:s');
            $fecha = str_replace(" ", "T",$fecha );
            
            $snt->bindValue(":fecha",$fecha);
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

    public function getConciertos():array {
        $sql = "SELECT c.*,a.nombre as 'nombreArtista' FROM Conciertos c LEFT JOIN Artista a ON c.idArtista = a.idArtista ";
        require_once __DIR__ . '/../../core/conexionBd.inc';
        try {
            $con = (new ConexionBd())->getConexion();
            $snt = $con->prepare($sql);
            $fecha = (new \DateTime("now"))->format('Y-m-d H:i:s');

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

    public function updateConcierto(Concierto $conciertos,int $codConcierto):bool
    {
        $sql = "UPDATE Conciertos SET nombre = :nom , fecha = :fcha , lugar = :lug , aforo = :aforo , idArtista = :idArt , numEntradasNormales = :numEntNorm , precioEntradasNormales = :precEntNorm , numEntradasVip = :numEntVip , precioEntradasVip = :precEntVip, latitud = :lat, longitud = :long WHERE idConcierto = :codConcierto";
        require_once __DIR__ . '/../../core/conexionBd.inc';
        try {
            $con = (new ConexionBd())->getConexion();
            $snt = $con->prepare($sql);
            $fecha = ($conciertos->getFecha())->format('Y-m-d H:i:s');
            $fecha = str_replace(" ", "T",$fecha );
            $snt->bindValue(":nom",$conciertos->getNombre());
            $snt->bindValue(":fcha",$fecha);
            $snt->bindValue(":lug",$conciertos->getLugar());
            $snt->bindValue(":aforo",$conciertos->getAforo());
            $snt->bindValue(":codConcierto",$codConcierto);
            $snt->bindValue(":idArt",$conciertos->getIdArtista());
            $snt->bindValue(":numEntNorm",$conciertos->getNumEntradasNormales());
            $snt->bindValue(":precEntNorm",$conciertos->getPrecioEntradasNormales());
            $snt->bindValue(":numEntVip",$conciertos->getNumEntradasVip());
            $snt->bindValue(":precEntVip",$conciertos->getPrecioEntradasVip());
            $snt->bindValue(":lat",$conciertos->getLatitud());
            $snt->bindValue(":long",$conciertos->getLongitud());
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

    public function addImagenConcierto(int $codConcierto,string $nombreArchivo):bool
    {
        $sql = "INSERT INTO ImagenesConcierto(idConcierto,ruta) VALUES (:codConcierto,:nombreArchivo)";
        require_once __DIR__ . '/../../core/conexionBd.inc';
        try {
            $con = (new ConexionBd())->getConexion();
            $snt = $con->prepare($sql);
            $snt->bindValue(":codConcierto",$codConcierto);
            $snt->bindValue(":nombreArchivo",$nombreArchivo);
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

    public function deleteConcierto(int $codConcierto):bool
    {
        $sql = "DELETE FROM Conciertos WHERE idConcierto = :codConcierto";
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

    

    public function getImgsConcierto(int $codConcierto):array
    {
        $sql = "SELECT * FROM ImagenesConcierto WHERE idConcierto = :codConcierto";
        require_once __DIR__ . '/../../core/conexionBd.inc';
        try {
            $con = (new ConexionBd())->getConexion();
            $snt = $con->prepare($sql);
            $snt->bindValue(":codConcierto",$codConcierto);
            $snt->execute();
            return $snt->fetchAll(\PDO::FETCH_ASSOC);
        } catch (\Exception $ex) {
            throw $ex;
            return ($error = []);
        }finally
        {
            unset($con);
            unset($snt);
        }
    }

    public function deleteImgConcierto(int $codConcierto):bool
    {
        $sql = "DELETE FROM ImagenesConcierto WHERE idConcierto = :codConcierto";
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

    public function deleteIdImgConcierto(int $codImagen){
        $sql = "DELETE FROM ImagenesConcierto WHERE idImagen = :codImagen";
        require_once __DIR__ . '/../../core/conexionBd.inc';
        try {
            $con = (new ConexionBd())->getConexion();
            $snt = $con->prepare($sql);
            $snt->bindValue(":codImagen",$codImagen);
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

    public function updateEntradasConcierto(int $idConcierto,string $tipoEntrada):bool {
        if($tipoEntrada == "normal")
        {
            $sql = "UPDATE Conciertos SET numEntradasNormales =  numEntradasNormales - 1 WHERE idConcierto = :idConcierto";
        }else{
            $sql = "UPDATE Conciertos SET numEntradasVip =  numEntradasVip - 1 WHERE idConcierto = :idConcierto";
        }
        
        require_once __DIR__ . '/../../core/conexionBd.inc';
        try {
            $con = (new ConexionBd())->getConexion();
            $snt = $con->prepare($sql);
            $snt->bindValue(":idConcierto",$idConcierto);
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

    /*UPDATE DE LAS ENTRADAS DEL CONCIERTO*/
    public function updateEntradasConciertoAdd(int $idConcierto,string $tipoEntrada):bool {
        if($tipoEntrada == "normal")
        {
            $sql = "UPDATE Conciertos SET numEntradasNormales =  numEntradasNormales + 1 WHERE idConcierto = :idConcierto";
        }else{
            $sql = "UPDATE Conciertos SET numEntradasVip =  numEntradasVip + 1 WHERE idConcierto = :idConcierto";
        }
        
        require_once __DIR__ . '/../../core/conexionBd.inc';
        try {
            $con = (new ConexionBd())->getConexion();
            $snt = $con->prepare($sql);
            $snt->bindValue(":idConcierto",$idConcierto);
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
    /*BUSQUEDAS*/
    public function buscarConcierto(string $condicion):array {
        if($condicion == "")
        {
            $sql = "SELECT c.*,a.nombre as 'nombreArtista' FROM Conciertos c LEFT JOIN Artista a ON a.idArtista = c.idArtista";
        }else{
            $sql = "SELECT c.*,a.nombre as 'nombreArtista' FROM Conciertos c LEFT JOIN Artista a ON a.idArtista = c.idArtista  WHERE " . $condicion;
        }
        
        require_once __DIR__ . '/../../core/conexionBd.inc';
        try {
            $con = (new ConexionBd())->getConexion();
            $snt = $con->prepare($sql);
            $snt->execute();
            return $snt->fetchAll(\PDO::FETCH_ASSOC);
        } catch (\Exception $ex) {
            throw $ex;
            return ($error = []);
        }finally
        {
            unset($con);
            unset($snt);
        }
    }

    public function updateImagenConcierto(int $codConcierto,string $imagen):bool
    {
        $sql = "UPDATE ImagenesConcierto SET  ruta = :imagen  WHERE idConcierto = :codConcierto";
        require_once __DIR__ . '/../../core/conexionBd.inc';
        try {
            $con = (new ConexionBd())->getConexion();
            $snt = $con->prepare($sql);
            $snt->bindValue(":imagen",$imagen);
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
}