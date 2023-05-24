<?php
namespace ConciertosProyecto\app\Repositorio;
use ConciertosProyecto\app\Modelo\Artista;
use ConciertosProyecto\app\core\ConexionBd;
class ArtistaRepositorio
{
    public function addArtista(Artista $artista):int
    {
        $sql = "INSERT INTO artista(nombre,generoMusical,pais,descripcion,imagenArtista) SELECT :nom,:genM,:pa,:desc,:imgA FROM DUAL WHERE NOT EXISTS (SELECT * FROM Artista WHERE nombre = '" . $artista->getNombre() . "')";
        require_once __DIR__ . '/../../core/conexionBd.inc';
        try {
            $con = (new ConexionBd())->getConexion();
            $con->beginTransaction(); // Iniciamos transacción
            $snt = $con->prepare($sql);
            $snt->bindValue(":nom",$artista->getNombre());
            $snt->bindValue(":genM",$artista->getGeneroMusical());
            $snt->bindValue(":pa",$artista->getPais());
            $snt->bindValue(":desc",$artista->getDescripcion());
            $snt->bindValue(":imgA",$artista->getImagenArtista());
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

    public function getArtistas():array {
        $sql = "SELECT * FROM Artista";
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

    
    public function getArtista(int $codArtista):array {
        $sql = "SELECT * FROM Artista WHERE idArtista = :codArtista";
        require_once __DIR__ . '/../../core/conexionBd.inc';
        try {
            $con = (new ConexionBd())->getConexion();
            $snt = $con->prepare($sql);
            $snt->bindValue(":codArtista",$codArtista);
            
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

    public function getArtistaPortada():array {

        $sql = "SELECT * FROM Artista ORDER BY RAND () LIMIT 6;";
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


    public function updateArtista(Artista $artista,int $codArtista):bool
    {
        $sql = "UPDATE Artista SET nombre = :nom , generoMusical = :genM , pais = :pa , descripcion = :descr , imagenArtista = :imgA  WHERE idArtista = :codArtista";
        require_once __DIR__ . '/../../core/conexionBd.inc';
        try {
            $con = (new ConexionBd())->getConexion();
            $snt = $con->prepare($sql);
            $snt->bindValue(":nom",$artista->getNombre());
            $snt->bindValue(":genM",$artista->getGeneroMusical());
            $snt->bindValue(":pa",$artista->getPais());
            $snt->bindValue(":descr",$artista->getDescripcion());
            $snt->bindValue(":imgA",$artista->getImagenArtista());
            $snt->bindValue(":codArtista",$codArtista);
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

    public function updateImagenArtista(int $codArtista,string $imagen):bool 
    {
        $sql = "UPDATE Artista SET  imagenArtista = :imagen  WHERE idArtista = :codArtista";
        require_once __DIR__ . '/../../core/conexionBd.inc';
        try {
            $con = (new ConexionBd())->getConexion();
            $snt = $con->prepare($sql);
            $snt->bindValue(":imagen",$imagen);
            $snt->bindValue(":codArtista",$codArtista);
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

    public function deleteArtista(int $codArtista):bool
    {
        $sql = "DELETE FROM Artista WHERE idArtista = :codArtista";
        require_once __DIR__ . '/../../core/conexionBd.inc';
        try {
            $con = (new ConexionBd())->getConexion();
            $snt = $con->prepare($sql);
            $snt->bindValue(":codArtista",$codArtista);
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

    public function getImgsArtista(int $codArtista):array
    {
        $sql = "SELECT imagenArtista FROM Artista WHERE idArtista = :codArtista";
        require_once __DIR__ . '/../../core/conexionBd.inc';
        try {
            $con = (new ConexionBd())->getConexion();
            $snt = $con->prepare($sql);
            $snt->bindValue(":codArtista",$codArtista);
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

    public function getGenerosMusicales():array
    {
        $sql = "SELECT DISTINCT generoMusical FROM Artista";
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

    public function getConciertosArtista(int $codArtista):array{
        $sql = "SELECT * FROM Conciertos WHERE idArtista = :codArtista";
        require_once __DIR__ . '/../../core/conexionBd.inc';
        try {
            $con = (new ConexionBd())->getConexion();
            $snt = $con->prepare($sql);
            $snt->bindValue(":codArtista",$codArtista);
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

    
}