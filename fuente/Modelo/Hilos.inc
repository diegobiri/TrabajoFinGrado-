<?php
namespace ConciertosProyecto\app\Modelo;

use ConciertosProyecto\app\Modelo\HilosException;

class Hilos
{
    private string $titulo;
    private string $descripcion;
    

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

        

        if(isset($errores))
        {
            throw new HilosException($errores);
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

    
   
    //GETTERS

    public function getTitulo():string
    {
        return $this->titulo;
    }


    public function getDescripcion():string
    {
        return $this->descripcion;
    }
    
}