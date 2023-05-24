<?php

namespace ConciertosProyecto\app\Modelo;
use ConciertosProyecto\app\Modelo\EntradaException;

class Entrada
{
    private string $tipoEntrada;
    private int $idConcierto;
    private int $idUsuario;
    

    public function __construct(array $datosEntrada)
    {
        if(!$this->setTipoEntrada(htmlspecialchars(stripslashes(trim($datosEntrada['tipoEntrada'])))))
        {
            $errores['tipoEntrada'] = 'Tipo Entrada Incorrecto';
        }

        if(!$this->setIdConcierto($datosEntrada['idConcierto']))
        {
            $errores['idConcierto'] = 'Id Concierto Incorrecto';
        }

        if(!$this->setIdUsuario(htmlspecialchars($datosArtista['idUsuario'])))
        {
            $errores['idUsuario'] = 'Id Usuario Incorrecto';
        }

       
        if(isset($errores))
        {
            throw new EntradaException($errores);
        }
    }

    public function setIdUsuario(int $idUsuario):bool
    {
        $this->idUsuario=$idUsuario;
        return true;
    }

    public function setIdConcierto(int $idConcierto):bool
    {
        $this->idConcierto=$idConcierto;
        return true;
    }

    public function setTipoEntrada(int $tipoEntrada):bool
    {
        $this->tipoEntrada=$tipoEntrada;
        return true;
    }

    

    //GETTERS

    public function getIdUsuario():int
    {
        return $this->idUsuario;
    }

    public function getIdConcierto():int
    {
        return $this->idConcierto;
    }

    public function getTipoEntrada():string
    {
        return $this->tipoEntrada;
    }
    
}