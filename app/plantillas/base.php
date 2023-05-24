<!-- Vista común a la mayoría (sino todas) las vistas de la aplicación
     Suele contener la imagen corporativa de la apliación Web
     Concretamente esta página contiene el nombre de la empresa
     "Cadena Tiendas Media" y una barra de hiperenlaces con un enalace a la
     página home, llamado "inicio"
     El nombre del archivo es indiferente: layout, comun, etc.
-->
<!DOCTYPE html>
<html>
  <head>
  <link rel="stylesheet" href="https://unpkg.com/leaflet@1.9.3/dist/leaflet.css" integrity="sha256-kLaT2GOSpHechhsozzB+flnD+zUyjE2LlfWPgU04xyI=" crossorigin="" />
  <link rel="preconnect" href="https://fonts.googleapis.com">
  <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
  <link href="https://fonts.googleapis.com/css2?family=Titan+One&display=swap" rel="stylesheet">
  <script src="https://unpkg.com/leaflet@1.9.3/dist/leaflet.js" integrity="sha256-WBkoXOwTeyKclOHuWtc+i2uENFpDZ9YPdf5Hf+D7ewM=" crossorigin=""></script>
  <script src="https://kit.fontawesome.com/eef29a3e87.js" crossorigin="anonymous"></script>
    <title></title>
    <meta charset="utf-8">
    <link rel="stylesheet"  type="text/css" href="web/Bootstrap/css/bootstrap.min.css">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" type="text/css" href='web/css/general.css' />
  </head>
  <body>
    <header class="py-3 bg-dark text-white">
        <!--<nav class="navbar navbar-expand-md bg-dark navbar-dark text-center">
          <div class="container-fluid ">
           <a href="index.php" class="nav-link px-2 text-secondary text-dark"><img class="bi"  width="24" height="24" src="web/resources/house.svg"></img></a>
            <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#collapsibleNavbar">
              <span class="navbar-toggler-icon"></span>
            </button>
            <div class="collapse navbar-collapse" id="collapsibleNavbar">
            <?php if (isset($_SESSION['usuario']) && $_SESSION['rol'] == 'ADMIN'): ?>
              <a class="nav-link dropdown-toggle ligh" href="#" role="button" data-bs-toggle="dropdown">Acciones Administrador</a>
              <ul class="dropdown-menu">
                
                  <li class="nav-item"><a href="index.php?ctl=addConcierto" class="nav-link px-2 text-secondary dropdown-item">Añadir Concierto</a></li>
                  <li class="nav-item"><a href="index.php?ctl=crearHilosForo" class="nav-link px-2 text-secondary dropdown-item">Añadir Hilos Foro</a></li>
                  <li><a href="index.php?ctl=addArtista" class="nav-link px-2 text-white dropdown-item">Añadir Artista</a></li>
                  <li><a href="index.php?ctl=listarConcierto" class="nav-link px-2 text-white dropdown-item">Gestionar Conciertos</a></li>
                  <li><a href="index.php?ctl=listarArtistas" class="nav-link px-2 text-white dropdown-item">Gestionar Artistas</a></li>
                  <li><a href="index.php?ctl=verTodasEntradasAdmin" class="nav-link px-2 text-white dropdown-item">Gestionar Entradas</a></li>
                  <li><a href="index.php?ctl=listarTemasAdmin" class="nav-link px-2 text-white dropdown-item">Gestionar Hilos Foro</a></li>
                  
              </ul>
            <?php endif; ?>

              
              <div class="text-end w-100">
                <?php if (!isset($_SESSION['usuario'])): ?>
                  <a  href="index.php?ctl=listarHilos"><button type="button" class="btn btn-outline-dark me-2">Foro</button></a>
                  <a  href="index.php?ctl=buscador"><button type="button" class="btn btn-outline-dark me-2">Buscar Conciertos</button></a>
                  <a  href="index.php?ctl=login"><button type="button" class="btn btn-outline-dark me-2">Login</button></a>
                  <a  href="index.php?ctl=registroUsuario"><button type="button" class="btn btn-warning">Registrarse</button></a>
                <?php else: ?>
                  <a  href="index.php?ctl=buscador"><button type="button" class="btn btn-outline-dark me-2">Buscar Conciertos</button></a>
                  <a  href="index.php?ctl=listarHilos"><button type="button" class="btn btn-outline-dark me-2">Foro</button></a>
                  <a  href="index.php?ctl=verEntradas"><button type="button" class="btn btn-outline-dark me-2">Mis Entradas</button></a>
                  <a  href="index.php?ctl=logOut"><img class="bi m-1"  width="24" height="24" src="web/resources/door-closed.svg"></img></a>
                  <a  href="index.php?ctl=listarCarrito"><img class="bi m-1"  width="24" height="24" src="web/resources/cart2.svg"></img></a>
                  <a  href="index.php?ctl=editPerfil"><img class="bi m-1"  width="24" height="24" src="web/resources/person.svg"></img></a>
                <?php endif; ?>
              </div>
            </div>
          </div>
      </nav>
      !-->
      <nav class="navbar navbar-expand-lg navbar-dark bg-dark">
  <div class="container-fluid">
  <a href="index.php" class="nav-link px-2 text-secondary text-dark"><img class="bi"  width="24" height="24" src="web/resources/house.svg"></img></a>
    <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
      <span class="navbar-toggler-icon"></span>
    </button>
    <div class="collapse navbar-collapse" id="navbarSupportedContent">

      <ul class="navbar-nav me-auto mb-2 mb-lg-0">
        <?php if (isset($_SESSION['usuario']) && $_SESSION['rol'] == 'ADMIN'): ?>
          <li class="nav-item dropdown">
          <a class="nav-link dropdown-toggle" href="#" id="navbarDropdown" role="button" data-bs-toggle="dropdown" aria-expanded="false">
          <button type="button" class="btn btn-outline-dark me-2">Acciones Administrador</button>
          </a>
            <ul class="dropdown-menu" aria-labelledby="navbarDropdown">
              <li><a class="dropdown-item" href="index.php?ctl=addConcierto" class="nav-link px-2 text-secondary dropdown-item">Añadir Concierto</a></li>
              <li><a class="dropdown-item" href="index.php?ctl=crearHilosForo" class="nav-link px-2 text-secondary dropdown-item">Añadir Hilos Foro</a></li>
              <li><a class="dropdown-item" href="index.php?ctl=addArtista" class="nav-link px-2 text-white dropdown-item">Añadir Artista</a></li>
              <li><a class="dropdown-item" href="index.php?ctl=listarConcierto" class="nav-link px-2 text-white dropdown-item">Gestionar Conciertos</a></li>
              <li><a class="dropdown-item" href="index.php?ctl=listarArtistas" class="nav-link px-2 text-white dropdown-item">Gestionar Artistas</a></li>
              <li><a class="dropdown-item" href="index.php?ctl=verTodasEntradasAdmin" class="nav-link px-2 text-white dropdown-item">Gestionar Entradas</a></li>
              <li><a class="dropdown-item" href="index.php?ctl=listarTemasAdmin" class="nav-link px-2 text-white dropdown-item">Gestionar Hilos Foro</a></li>
            </ul>
          </li>
        <?php endif; ?>
        <?php if (!isset($_SESSION['usuario'])): ?>
          <li class="nav-item">
            <a class="nav-link" href="index.php?ctl=listarHilos" ><button type="button" class="btn btn-outline-dark me-2">Foro</button></a>
          </li>  
          <li class="nav-item">
            <a class="nav-link" href="index.php?ctl=buscador"><button type="button" class="btn btn-outline-dark me-2">Buscar Conciertos</button></a>
          </li>
          <li class="nav-item">
              <a class="nav-link" href="index.php?ctl=login"><button type="button" class="btn btn-outline-dark me-2">Login</button></a>
          </li>
          <li class="nav-item">
            <a class="nav-link" href="index.php?ctl=registroUsuario"><button type="button" class="btn btn-outline-dark me-2">Registrarse</button></a>
          </li>
        <?php else: ?>
          <li class="nav-item">
            <a class="nav-link" href="index.php?ctl=buscador" ><button type="button" class="btn btn-outline-dark me-2">Buscar Conciertos</button></a>
          </li>  
          <li class="nav-item">
            <a class="nav-link" href="index.php?ctl=listarHilos"><button type="button" class="btn btn-outline-dark me-2">Foro</button></a>
          </li>
          <li class="nav-item">
              <a class="nav-link" href="index.php?ctl=verEntradas"><button type="button" class="btn btn-outline-dark me-2">Mis entradas</button></a>
          </li>
          <li class="nav-item">
            <a  class="nav-link" href="index.php?ctl=logOut"><img class="bi m-1"  width="24" height="24" src="web/resources/door-closed.svg"></img></a>
          </li>
          <li class="nav-item">
            <a  class="nav-link" href="index.php?ctl=listarCarrito"><img class="bi m-1"  width="24" height="24" src="web/resources/cart2.svg"></img></a>
          </li>
          <li class="nav-item">
            <a  class="nav-link" href="index.php?ctl=editPerfil"><img class="bi m-1"  width="24" height="24" src="web/resources/person.svg"></img></a>
          </li>
          <?php endif; ?>
      </ul>
    </div>
  </div>
</nav>     
    </header>
    <?php if(isset($carrousel)){echo $carrousel;} ?>
    <div id="container" class="container-fluid">
      
        <!-- el id css facilita (si se define) la definición del aspecto visual
            de su contenido
            La variable $contenido hará que se muestre la plantilla concreta, el
            contenido concreto, según la solicitud realizada por el usuario
        -->
      <?= $contenido ?>
      
      
    </div>

    <footer class="d-flex flex-wrap justify-content-between align-items-center py-3 my-4 border-top" id="footer">
        <div class="col-md-4 d-flex align-items-center">
          <a href="/" class="mb-3 me-2 mb-md-0 text-muted text-decoration-none lh-1">
            <svg class="bi" width="30" height="24"><use xlink:href="#bootstrap"/></svg>
          </a>
          <span class="text-muted">&copy; Conciertos La Rioja</span>
        </div>

        <ul class="nav col-md-4 justify-content-end list-unstyled d-flex">
          <li class="ms-3"><a class="text-muted" href="#"><img class="bi"  width="24" height="24" src="web/resources/twitter.svg"></img></a></li>
          <li class="ms-3"><a class="text-muted" href="#"><img  class="bi" width="24" height="24" src="web/resources/instagram.svg"/></img></a></li>
          <li class="ms-3 me-4"><a class="text-muted" href="#"><img class="bi" width="24" height="24" src="web/resources/facebook.svg" ></img></a></li>

          
        </ul>
     </footer>
    <script type="text/javascript" src="web/Bootstrap/js/jquery-3.2.1.slim.min.js"></script>
    <script type="text/javascript" src="web/Bootstrap/js/bootstrap.min.js"></script>
    <script type="text/javascript" src="web/js/qrcode.js"></script>
    <script type="text/javascript" src="web/js/qrcode.min.js"></script>
    <script type="text/javascript" src="web/js/funciones.js"></script>
    
  </body>
</html>
