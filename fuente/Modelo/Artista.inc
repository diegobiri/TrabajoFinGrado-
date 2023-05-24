<?php
namespace ConciertosProyecto\app\Modelo;

use ConciertosProyecto\app\Modelo\ConciertoException;

class Artista
{
    private string $nombre;
    private string $generoMusical;
    private string $pais;
    private string $descripcion;
    private string $imagenArtista;

    public function __construct(array $datosArtista)
    {
        if(!$this->setNombre(htmlspecialchars(stripslashes(trim($datosArtista['nombre'])))))
        {
            $errores['nombre'] = 'Nombre Incorrecto';
        }

        if(!$this->setGeneroMusical(htmlspecialchars(stripslashes(trim($datosArtista['generoMusical'])))))
        {
            $errores['generoMusical'] = 'Genero Musical Incorrecto';
        }

        if(!$this->setPais(htmlspecialchars(stripslashes(trim($datosArtista['pais'])))))
        {
            $errores['pais'] = 'Pais Incorrecto';
        }

        if(!$this->setDescripcion(htmlspecialchars(stripslashes(trim($datosArtista['descripcion'])))))
        {
            $errores['descripcion'] = 'Descripcion Incorrecto';
        }

        

        

        if(isset($errores))
        {
            throw new ArtistaException($errores);
        }else{
            if(!$this->setImagenArtista(htmlspecialchars(stripslashes(trim($datosArtista['imagenes'])))))
            {
                $errores['imagenes'] = 'Imagen Incorrecto';
            }
        }
    }

    public function setNombre(string $nombre):bool
    {
        
        if(empty($nombre))
        {
            return false;
        }else if(strlen($nombre)>30)
        {
            return false;
        }
        $this->nombre=$nombre;
        return true;
    }

    public function setGeneroMusical(string $generoMusical):bool
    {
        $expReg = '/^[A-Z]{1}[a-záéíóú]*$/';
        if(empty($generoMusical))
        {
            return false;
        }
        $this->generoMusical=$generoMusical;
        return true;
    }

    public function setPais(string $pais):bool
    {
        
        if(empty($pais))
        {
            return false;
        }
        $this->pais=$pais;
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

    

    

    public function setImagenArtista(string $imagenArtista):bool
    {
        $this->imagenArtista=$imagenArtista;
        return true;
    }

    //GETTERS

    public function getNombre():string
    {
        return $this->nombre;
    }

    public function getGeneroMusical():string
    {
        return $this->generoMusical;
    }

    public function getPais():string
    {
        return $this->pais;
    }

    public function getDescripcion():string
    {
        return $this->descripcion;
    }
    
   
    public function getImagenArtista():string
    {
        return $this->imagenArtista;
    }
   
}