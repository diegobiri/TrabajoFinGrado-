<?php
namespace ConciertosProyecto\app\Modelo;

use ConciertosProyecto\app\Modelo\ComentarioException;

class Comentario
{
    private string $titulo;
    private string $descripcion;
    private \DateTime $fecha;
    private int $idUsuario;
    private int $idHilos;
    

    public function __construct(array $datosComentario)
    {
        if(!$this->setTitulo(htmlspecialchars(stripslashes(trim($datosComentario['titulo'])))))
        {
            $errores['titulo'] = 'Nombre Incorrecto';
        }


        if(!$this->setDescripcion(htmlspecialchars(stripslashes(trim($datosComentario['descripcion'])))))
        {
            $errores['descripcion'] = 'Descripcion Incorrecto';
        }

        $this->setFecha(new \DateTime("now"));

        if(!$this->setIdUsuario($datosComentario['idUsuario']))
        {
            $errores['idUsuario'] = 'Usuario Incorrecto';
        }

        if(!$this->setIdHilo($datosComentario['idHilos']))
        {
            $errores['idHilo'] = 'Hilo Incorrecto';
        }

        

        if(isset($errores))
        {
            throw new ComentarioException($errores);
        }
    }

    public function setTitulo(string $titulo):bool
    {
        
        if(empty($titulo))
        {
            return false;
        }
        $this->titulo=$titulo;
        return true;
    }

    

    public function setDescripcion(string $descripcion):bool
    {
        
        if(empty($descripcion))
        {
            return false;
        }
        $this->descripcion=$descripcion;
        return true;
    }

    public function setFecha(\DateTime $fecha):bool
    {
        $this->fecha=$fecha;
        return true;
    }

    public function setIdUsuario(int $idUsuario):bool
    {
        $this->idUsuario=$idUsuario;
        return true;
    }

    public function setIdHilo(int $idHilos):bool
    {
        $this->idHilos=$idHilos;
        return true;
    }

   
    //GETTERS

    public function getTitulo():string
    {
        return $this->titulo;
    }


    public function getDescripcion():string
    {
        return $this->descripcion;
    }
    
   
    public function getFecha():\DateTime
    {
        return $this->fecha;
    }
    
    public function getIdUsuario():int
    {
        return $this->idUsuario;
    }

    public function getIHilos():int
    {
        return $this->idHilos;
    }
   
}