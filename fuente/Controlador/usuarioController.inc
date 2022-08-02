<?php
namespace ConciertosProyecto\app\controlador;

class usuarioController
{
    public function registro():void
    {
        require __DIR__ . '/../../app/plantillas/registroUsuario.php';
    }
}