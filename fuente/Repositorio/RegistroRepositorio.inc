<?php
namespace ConciertosProyecto\app\Repositorio;
use ConciertosProyecto\app\Modelo\Usuario;
use ConciertosProyecto\app\core\ConexionBd;

class RegistroRepositorio
{
    public function addUsuario(Usuario $usu):int
    {
        $sql = "INSERT INTO usuarios(nombre,primerApellido,segundoApellido,fechaNacimiento,email,docIdentificacion,telefonoMovil,genero) SELECT :nom,:primApe,:segApe,:fechaNac,:ema,:docIdentificacion,:tlfno,:gen FROM DUAL WHERE NOT EXISTS (SELECT * FROM usuarios WHERE email = :emaI OR docIdentificacion = :docIdentificacionI);";
        require_once __DIR__ ."/../../core/conexionBd.inc";

        
        
        try{
            
            $con = (new ConexionBd()) -> getConexion();
            $con->beginTransaction(); //Iniciamos la transaccion
            $snt=$con->prepare($sql);
            $snt->bindValue(":nom",$usu->getNombre());
            $snt->bindValue(":primApe",$usu->getPrimerApellido());
            $snt->bindValue(":segApe",$usu->getSegundoApellido());
            $snt->bindValue(":fechaNac",$usu->getFechaNacimiento()->format('Y-m-d'));
            
            $snt->bindValue(":ema",$usu->getEmail());
            $snt->bindValue(":docIdentificacion",$usu->getDocIdentificacion());
            $snt->bindValue(":emaI",$usu->getEmail());
            $snt->bindValue(":docIdentificacionI",$usu->getDocIdentificacion());
            $snt->bindValue(":tlfno",$usu->getTelefonoMovil());
            $snt->bindValue(":gen",$usu->getGenero());
            $snt->execute();
            $resultado = $con->lastInsertId();
            $con->commit();
            return $resultado;
        }catch(\PDOException $ex)
        {
            $con->rollback();
            throw $ex;
            return -1;
        }finally{
            unset($con);
            unset($snt);
        }
    }

    public function addGustosMusical(int $idUsuario,string $gustoMusical):bool{
        $sql = "INSERT INTO GustosMusicales(idUsuario,gustoMusical) VALUES (:idUsu,:gustoMusical)";
        require_once __DIR__ ."/../../core/conexionBd.inc";

        try{
            $con = (new ConexionBd()) -> getConexion();
            $snt=$con->prepare($sql);
            $snt->bindValue(":idUsu",$idUsuario);
            $snt->bindValue(":gustoMusical",$gustoMusical);
            $snt->execute();
            return true;
        }catch(\PDOException $ex)
        {
            throw $ex;
            return false;
        }finally{
            unset($con);
            unset($snt);
        }
    }

    public function updateUsuario(Usuario $usu,string $email):bool
    {
        $sql = "UPDATE Usuarios SET nombre = :nom , primerApellido = :primApe , segundoApellido = :segApe , fechaNacimiento = :fechaNac , docIdentificacion = :docIdentificacion , telefonoMovil = :tlfno , genero = :gen  WHERE email = :email";
        require_once __DIR__ . '/../../core/conexionBd.inc';
        try {
            $con = (new ConexionBd())->getConexion();
            $con->beginTransaction(); //Iniciamos la transaccion
            $snt=$con->prepare($sql);
            $snt->bindValue(":nom",$usu->getNombre());
            $snt->bindValue(":primApe",$usu->getPrimerApellido());
            $snt->bindValue(":segApe",$usu->getSegundoApellido());
            $snt->bindValue(":fechaNac",$usu->getFechaNacimiento()->format('Y-m-d'));
            $snt->bindValue(":docIdentificacion",$usu->getDocIdentificacion());
            $snt->bindValue(":tlfno",$usu->getTelefonoMovil());
            $snt->bindValue(":gen",$usu->getGenero());
            $snt->bindValue(":email",$email);
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

    public function updateContrasenaUsuario(int $idUsuario,string $pass):bool
    {
        $sql = "UPDATE Usuarios SET pass = :pass   WHERE idUsuario = :idUsuario";
        require_once __DIR__ . '/../../core/conexionBd.inc';
        try {
            $con = (new ConexionBd())->getConexion();
            $con->beginTransaction(); //Iniciamos la transaccion
            $snt=$con->prepare($sql);
            $pass = password_hash($pass, PASSWORD_DEFAULT);
            $snt->bindValue(":pass",$pass);
            $snt->bindValue(":idUsuario",$idUsuario);
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

    public function getSesion(string $email):array
    {
        $sql = "SELECT pass,rol,idUsuario FROM Usuarios  WHERE email = :ema";
       require_once __DIR__ . '/../../core/conexionBd.inc';
        try {
            $con = (new ConexionBd())->getConexion();
            $snt = $con->prepare($sql);
            $snt->bindValue(":ema",$email);
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

    public function getUsuarioEmail(string $email):array {
        $sql = "SELECT * FROM Usuarios WHERE email = :ema";
        require_once __DIR__ . '/../../core/conexionBd.inc';
        try {
            $con = (new ConexionBd())->getConexion();
            $snt = $con->prepare($sql);
            $snt->bindValue(":ema",$email);
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