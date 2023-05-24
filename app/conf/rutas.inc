<?php

// Vector multidimensional con rutas a controlador y método que debe
// atender cada enlace
/* formato:
    Primera dimensaión: nombre del enlace pasado mediante variable GET 'ctl'
     'nombreEnlace' => array() segunda dimesion con información del controlador
                       que atiende esa petición, clave 'controller', y del
                       método concreto que está especializado en su tratamiento,
                       clave 'action'
  Se debe agregar una ruta por cada valor diferente que tome la variable 'ctl'.
  La clave 'inicio' referencia la página home de la aplicación y especifica
    el controlador que debe decidir cuál es la vista que se debe mostrar
*/
$mapeoRutas =
  array('inicio' =>
          array('controller' =>'ConciertosProyecto\app\controlador\defaultController', 'action' =>'inicio'),
        'login' =>
          array('controller' =>'ConciertosProyecto\app\controlador\defaultController', 'action' =>'logIn'),
        'logOut' =>
          array('controller' =>'ConciertosProyecto\app\controlador\defaultController', 'action' =>'logOut'),
        'registroUsuario' =>
          array('controller' =>'ConciertosProyecto\app\controlador\UsuarioController', 'action' =>'registro'),
        'addConcierto' =>
          array('controller' =>'ConciertosProyecto\app\controlador\ConciertoController', 'action' =>'addConcierto'),
        'infConcierto' =>
          array('controller' =>'ConciertosProyecto\app\controlador\ConciertoController', 'action' =>'verConcierto'),
        'listarConcierto' =>
          array('controller' =>'ConciertosProyecto\app\controlador\ConciertoController', 'action' =>'listarConcierto'),
        'updateConcierto' =>
          array('controller' =>'ConciertosProyecto\app\controlador\ConciertoController', 'action' =>'updateConcierto'),
        'deleteConcierto' =>
          array('controller' =>'ConciertosProyecto\app\controlador\ConciertoController', 'action' =>'deleteConcierto'),
        'addArtista' =>
          array('controller' =>'ConciertosProyecto\app\controlador\ArtistaController', 'action' =>'addArtista'),
        'listarArtistas' =>
          array('controller' =>'ConciertosProyecto\app\controlador\ArtistaController', 'action' =>'listarArtistas'),
        'updateArtista' =>
          array('controller' =>'ConciertosProyecto\app\controlador\ArtistaController', 'action' =>'updateArtista'),
        'deleteArtista' =>
          array('controller' =>'ConciertosProyecto\app\controlador\ArtistaController', 'action' =>'deleteArtista'),
        'addEntradaCarrito' =>
          array('controller' =>'ConciertosProyecto\app\controlador\CarritoController', 'action' =>'addEntradaCarrito'),
        'listarCarrito' =>
          array('controller' =>'ConciertosProyecto\app\controlador\CarritoController', 'action' =>'listarCarrito'),
        'verEntradas' =>
          array('controller' =>'ConciertosProyecto\app\controlador\CarritoController', 'action' =>'verEntradas'),
        'verTodasEntradasAdmin' =>
          array('controller' =>'ConciertosProyecto\app\controlador\CarritoController', 'action' =>'verTodasEntradasAdmin'),
        'deleteEntradaUsuario' =>
          array('controller' =>'ConciertosProyecto\app\controlador\CarritoController', 'action' =>'deleteEntradaUsuario'),
        'comprarEntradas' =>
          array('controller' =>'ConciertosProyecto\app\controlador\CarritoController', 'action' =>'comprarEntradas'),
        'buscador' =>
          array('controller' =>'ConciertosProyecto\app\controlador\ConciertoController', 'action' =>'buscadorConcierto'),
        'recuperarContraseña' =>
          array('controller' =>'ConciertosProyecto\app\controlador\UsuarioController', 'action' =>'recuperarContraseña'),
        'editPerfil' =>
          array('controller' =>'ConciertosProyecto\app\controlador\UsuarioController', 'action' =>'editPerfil'),
        'verEntrada' =>
          array('controller' =>'ConciertosProyecto\app\controlador\CarritoController', 'action' =>'verDetalleEntradas'),
        'crearHilosForo' =>
          array('controller' =>'ConciertosProyecto\app\controlador\ForoController', 'action' =>'crearHilosForo'),
        'listarHilos' =>
          array('controller' =>'ConciertosProyecto\app\controlador\ForoController', 'action' =>'listarHilos'),
        'verTema' =>
          array('controller' =>'ConciertosProyecto\app\controlador\ForoController', 'action' =>'verTema'),
        'listarTemasAdmin' =>
          array('controller' =>'ConciertosProyecto\app\controlador\ForoController', 'action' =>'listarTemasAdmin'),
        'deleteTemasAdmin' =>
          array('controller' =>'ConciertosProyecto\app\controlador\ForoController', 'action' =>'deleteTemasAdmin'),
        'updateHilo' =>
          array('controller' =>'ConciertosProyecto\app\controlador\ForoController', 'action' =>'updateHilo'),
          'verImagenesConcierto' =>
          array('controller' =>'ConciertosProyecto\app\controlador\ConciertoController', 'action' =>'verImagenesConcierto'),
         'deleteImgConcierto' =>
          array('controller' =>'ConciertosProyecto\app\controlador\ConciertoController', 'action' =>'deleteImgConcierto'),
       );

       


       


       