<?php
namespace ConciertosProyecto\app\Modelo;

use ConciertosProyecto\app\Modelo\UsuarioException;

class Usuario
{
    private string $nombre;
    private string $primerApellido;
    private string $segundoApellido;
    private \DateTime $fechaNacimiento;
    private string $email;
    private string $telefonoMovil;
    private string $genero;
    private string $docIdentificacion;

    public function __construct(array $datosUsuario)
    {
      if(!$this->setNombre(htmlspecialchars(stripslashes(trim($datosUsuario['nombre'])))))
        {
            $errores['nombre'] = 'Nombre Incorrecto';
        }

        if(!$this->setPrimerApellido(htmlspecialchars(stripslashes(trim($datosUsuario['primerApellido'])))))
        {
            $errores['primerApellido'] = 'Primer Apellido Incorrecto';
        }

        if(!$this->setSegundoApellido(htmlspecialchars(stripslashes(trim($datosUsuario['segundoApellido'])))))
        {
            $errores['segundoApellido'] = 'Segundo Apellido Incorrecto';
        }


        if(!$this->setFecha($datosUsuario['fechaNacimiento']))
        {
            $errores['fechaNacimiento'] = 'Fecha Incorrecto';
        }

        if(!$this->setEmail(htmlspecialchars(stripslashes(trim($datosUsuario['email'])))))
        {
            $errores['email'] = 'Email Incorrecto';
        }

        

        if(!$this->setTelefonoMovil(htmlspecialchars(stripslashes(trim($datosUsuario['telefonoMovil'])))))
        {
            $errores['telefonoMovil'] = 'Movil Incorrecto';
        }

        if(!$this->setGenero(htmlspecialchars(stripslashes(trim($datosUsuario['genero'])))))
        {
            $errores['genero'] = 'Genero Incorrecto';
        }

       

        if(!$this->setDocIdentificacion(htmlspecialchars(stripslashes(trim($datosUsuario['docIdentificacion'])))))
        {
            $errores['docIdentificacion'] = "Documento de Identidad Incorrecto";
        }

        if(isset($errores))
        {
            throw new UsuarioException($errores);
        }
    }

 
  public function setNombre(string $nombre): bool
  {
    $expReg = '/^[A-Z]{1}[a-záéíóú]*$/';
    if($nombre == '')
    {
      return false;
    }else if(!preg_match($expReg,$nombre))
    {
        return false;
    }

    $this->nombre = $nombre;
    return true;
  }


  
  public function setPrimerApellido(string $primerApellido): bool
  {
    $expReg = '/^[A-Z]{1}[a-záéíóú]*$/';
    if($primerApellido == '')
    {
      return false;
    }else if(!preg_match($expReg,$primerApellido))
    {
        return false;
    }

    $this->primerApellido = $primerApellido;
    return true;
  }


  public function setSegundoApellido(string $segundoApellido): bool
  {
    $expReg = '/^[A-Z]{1}[a-záéíóú]*$/';
    if($segundoApellido == '')
    {
      return false;
    }else if(!preg_match($expReg,$segundoApellido))
    {
        return false;
    }

    $this->segundoApellido = $segundoApellido;
    return true;
  }

  

  

    public function setFecha(\DateTime $fechaNacimiento):bool
    {
        $date1 = new \DateTime("now");
        $date2 =  $fechaNacimiento;
        $date1->sub(new \DateInterval('P18Y0M0DT0H0M0S'));
       
        if(empty($fechaNacimiento))
        {
          return false;
        }else if($date1<$date2)
        {
           
            return false;
        }
        $this->fechaNacimiento=$fechaNacimiento;
        return true;

        
    }

   
  public function setEmail(string $email): bool
  {
    if(empty($email))
    {
        return false;
    }else if(!filter_var($email,FILTER_VALIDATE_EMAIL))
    {
        return false;
    }
        $this->email=$email;
        return true;
  }

   

  
  public function setGenero(string $genero): bool
  {
    if(!($genero == 'Masculino') && !($genero == 'Femenino')){
      return false;
    }

    $this->genero = $genero;
    return true;
  }

  



 
  public function setTelefonoMovil(string $telefonoMovil): bool
  {
      $expReg="/^[986]{1}[0-9]{8}$/";
      if(empty($telefonoMovil))
      {
        return false;
      }else if(!preg_match($expReg, $telefonoMovil)){
        return false;
      }

      $this->telefonoMovil = $telefonoMovil;
      return true;
  }


  public function setDocIdentificacion(string $docIdentificacion):bool
  {
    $expReg="/^[0-9]{7,8}[T|R|W|A|G|M|Y|F|P|D|X|B|N|J|Z|S|Q|V|H|L|C|K|E]$/";
    if(empty($docIdentificacion))
      {
        return false;
      }else if(!preg_match($expReg, $docIdentificacion))
      {
        return false;
      }
      $this->docIdentificacion = $docIdentificacion;
      return true;
  }

  




    //Getters

 

    public function getNombre():string
    {
        return $this->nombre;
    }

 

    public function getPrimerApellido():string
    {
        return $this->primerApellido;
    }

 

    public function getSegundoApellido():string
    {
        return $this->segundoApellido;
    }

    public function getFechaNacimiento():\DateTime
    {
        return $this->fechaNacimiento;
    }

    

    public function getGenero():string
    {
        return $this->genero;
    }

    public function getEmail():string
    {
        return $this->email;
    }

    

    public function getTelefonoMovil():string
    {
        return $this->telefonoMovil;
    }

   

    

    public function getDocIdentificacion():string
    {
      return $this->docIdentificacion;
    }

}