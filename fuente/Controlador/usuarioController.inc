<?php
namespace ConciertosProyecto\app\controlador;

use ConciertosProyecto\app\Modelo\Usuario;
use ConciertosProyecto\app\Modelo\UsuarioException;
use ConciertosProyecto\app\Repositorio\RegistroRepositorio;
use ConciertosProyecto\app\Repositorio\SesionRepositorio;
class UsuarioController
{
    public function registro():void
    {
        if(isset($_POST['Registro']))
        {
            $errores = []; 
            try {
                $fecha = new \DateTime($_POST['fechaNacimiento']);
            } catch (\Exception $ex) {
                $errores['fechaNacimiento'] = "fecha Incorrecta";
                $fecha = new \DateTime("now");
            }

            try {
                $usuario = new Usuario(['nombre'=>$_POST["nombre"],'primerApellido'=>$_POST["primerApellido"],'segundoApellido'=>$_POST["segundoApellido"],'fechaNacimiento'=>$fecha,'email'=>$_POST['email'],'docIdentificacion'=>$_POST['docIdentificacion'],'telefonoMovil'=>$_POST['telefonoMovil'],'genero'=>$_POST['genero']]);
            } catch (UsuarioException $ex) {
                $errores = $ex->getErrores();
                

            }

            

            if(!isset($_POST['pass']) || $_POST['pass'] == '')
            {
                $errores['pass'] = "Contraseña Incorrecta";
            }else{
                    if(sizeof($errores) == 0)
                    {
                        $usuarioBd = (new RegistroRepositorio()) -> addUsuario($usuario);
                        
                        
                        if($usuarioBd != -1)
                        {
                             $comprobadorPass = (new RegistroRepositorio()) -> updateContrasenaUsuario($usuarioBd,$_POST['pass']);
                            $sesion = (new SesionRepositorio()) -> addSesion($usuarioBd);
                            if(isset($sesion) && $comprobadorPass == true)
                                {
                                    $_SESSION['usuario'] = $_POST['email'];
                                    $_SESSION['rol'] = 'USU';
                                    $_SESSION['id'] = $usuarioBd;
                                    $_SESSION['idSesion'] = $sesion;
                                    header('Location:index.php');
                                }
                        }else{
                            $errores['usuarioCorrecto'] = "Ese email ya existe en la base de datos";
                        }
                    }
                    
            }
            
                $datosUsuario[0]['nombre'] = $_POST["nombre"];
                $datosUsuario[0]['primerApellido'] = $_POST["primerApellido"];
                $datosUsuario[0]['segundoApellido'] = $_POST["segundoApellido"];
                $datosUsuario[0]['docIdentificacion'] = $_POST["docIdentificacion"];
                $datosUsuario[0]['fechaNacimiento'] = $_POST["fechaNacimiento"];
                $datosUsuario[0]['telefonoMovil'] = $_POST["telefonoMovil"];
           
        }

        require __DIR__ . '/../../app/plantillas/registroUsuario.php';
    }

    public function recuperarContraseña()
    {
        if(isset($_POST['Recuperar']))
        {
            if(isset($_POST['email']))
            {
                
                $correoUsu = (new SesionRepositorio()) -> getEmailUsu($_POST['email']);
                
                
               
                if(isset($correoUsu[0]['email']) && $_POST['email'] == $correoUsu[0]['email'])
                {
                    $contraseña = generarContrasena();
                    $updatePass = (new SesionRepositorio()) -> updatePass($_POST['email'],$contraseña);
                   
                   
                    $mail = new PHPMailer(true);

                    try {
                        //Server settings
                        $mail->isSMTP();   
                        $mail -> charSet = "UTF-8";
                        $mail->SMTPSecure = PHPMailer::ENCRYPTION_SMTPS;
                        $mail->SMTPSecure = 'tls';                                         //Send using SMTP
                        $mail->Host       = 'smtp.office365.com';                     //Set the SMTP server to send through
                        $mail->SMTPAuth   = true;                                   //Enable SMTP authentication
                        $mail->Username   = 'conciertosRioja@outlook.com';                     //SMTP username
                        $mail->Password   = 'Diego$1234';                               //SMTP password
                        $mail->Port       = 587;                                    //TCP port to connect to; use 587 if you have set `SMTPSecure = PHPMailer::ENCRYPTION_STARTTLS`

                        //Recipients
                        $mail->setFrom('conciertosRioja@outlook.com', 'ConciertosLaRioja');
                        $mail->addAddress($_POST['email'], '');     //Add a recipient

                        //Content
                        $mail->isHTML(true);                                  //Set email format to HTML
                        $mail->Subject = 'Recuperar Contraseña';
                        $mail->Body    = 'Hemos generado una contrasená automatica: '.$contraseña;

                        $mail->send();
                        $mensajeError = 'Se ha enviado con exito la contrasena a tu correo. Si no te ha llegado, compruebalo en la carpeta de Spam';
                    } catch (\Exception $e) {
                        $mensajeError = 'Ha ocurrido un error, comprueba que tu direccion de correo sea correcta';
                    }
                }else{
                    $mensajeError = "No hay ningun usuario con ese correo";
                }
            
            }
        }

        require __DIR__ . '/../../app/plantillas/recuperarContraseña.php';
    }

    public function editPerfil()
    {
        if(isset($_SESSION['usuario']))
        {
            if(isset($_POST['actualizar']))
            {
                  $errores = []; 
                try {
                    $fecha = new \DateTime($_POST['fechaNacimiento']);
                } catch (\Exception $ex) {
                    $errores['fechaNacimiento'] = "fecha Incorrecta";
                    $fecha = new \DateTime("now");
                }

                try {
                    $usuario = new Usuario(['nombre'=>$_POST["nombre"],'primerApellido'=>$_POST["primerApellido"],'segundoApellido'=>$_POST["segundoApellido"],'fechaNacimiento'=>$fecha,'email'=>$_SESSION['usuario'],'docIdentificacion'=>$_POST['docIdentificacion'],'telefonoMovil'=>$_POST['telefonoMovil'],'genero'=>$_POST['genero']]);
                } catch (UsuarioException $ex) {
                    $errores = $ex->getErrores();
                }

                if(sizeof($errores) == 0)
                    {
                        $usuarioBd = (new RegistroRepositorio()) -> updateUsuario($usuario,$_SESSION['usuario']);
                        if($usuarioBd == 1)
                        {
                            $errores['usuarioActualizado'] = "Usuario actualizado con exito";
                        }else{
                            $errores['usuarioActualizado'] = "Error al actualizar el usuario";
                        }
                    }

                    
            }

            if(isset($_POST['cambiar']))
            {
                $password = $_POST['newPass'];
                $password2 = $_POST['newPass2'];
                if(!empty($password) && !empty($password2))
                {
                    if($password == $password2)
                    {
                        $getPass = (new RegistroRepositorio())-> updateContrasenaUsuario($_SESSION['id'],$password);
                        if($getPass != false)
                        {
                            $errores['passwordError'] = "Contraseña actualizada con exito";
                        }else{
                            $errores['passwordError'] = "Error al actualizar la contraseña";
                        }
                    }else{
                        $errores['passwordError'] = "Error al actualizar la contraseña";
                    }
                }else{
                    $errores['passwordError'] = "Error al actualizar la contraseña";
                }
            }
        }else{
            $link = 'Location:index.php?ctl=login';
            header($link);
        }
        $datosUsuario = (new RegistroRepositorio()) -> getUsuarioEmail($_SESSION['usuario']);
        require __DIR__ . '/../../app/plantillas/editPerfil.php';
    }

    

    
}