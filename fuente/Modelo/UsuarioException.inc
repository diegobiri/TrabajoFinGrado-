<?php
namespace ConciertosProyecto\app\Modelo;
use Exception;

class UsuarioException extends \Exception
{
    private array $errores;

    public function __construct(array $errores)
    {
        $this->errores = $errores;
    }

    public function getErrores():array
    {
        return $this->errores;
    }
}