<?php
/* Ejemplo de plantilla que se mostrará dentro de la plantilla principal
  ob_start() activa el almacenamiento en buffer de la página. Mientras se
             almacena en el buffer no se produce salida alguna hacia el
             navegador del cliente
  luego viene el código html y/o php que especifica lo que debe aparecer en
     el cliente web
  ob_get_clean() obtiene el contenido del buffer (que se pasa a la variable
             $contenido) y elimina el contenido del buffer
  Por último se incluye la página que muestra la imagen común de la aplicación
    (en este caso base.php) la cual contiene una referencia a la variable
    $contenido que provocará que se muestre la salida del buffer dentro dicha
    página "base.php"
*/
 ?>
<?php ob_start() ?>

<link rel="stylesheet" type="text/css" href='web/css/index.css' />
  

<div class="container-fluid p-3">
  <h2 class="text-center my-5">Artistas</h2>
  <div class="row">

      <?php foreach ($artistas as $clave => $value):?>
        
        <div class="col-lg-4 col-sm-6 mb-5 col-12  text-center pe-2">
          <img class="bd-placeholder-img rounded-circle" width="160" height="160" src="./web/imagenes/imagenArtista/<?=$value["imagenArtista"];?>">

          <h4 class="text-center mt-2"><?=$value["nombre"];?></h4>
          <!--<p><?php /*<?=$value["descripcion"];?>*/?></p>-->
        </div>
        
      <?php endforeach;?>
    </div>

    <?php if(isset($conciertos) && !empty($conciertos)): ?>
      <h2 class="text-center my-5">Conciertos</h2>
        <div class="row">
          <?php foreach($conciertos as $clave => $value): ?>
            <div class="col-lg-4 col-12 col-md-6 text-center espaciado mt-2">
              <div class="card shadow-sm text-center rounded">
              <img class="bd-placeholder-img imgPortada" width="300" height="300" src="./web/imagenes/<?=$imagenes[$value['idConcierto']];?>">
                <div class="card-body">
                  <p class="card-text"><?= $value["nombre"];?></p>
                  <p class="card-text"><?= $value["lugar"];?></p>
                  <p class="card-text"><?= $value["aforo"];?></p>
                  <p class="card-text">Fecha del Concierto:<?= substr($value["fecha"],8,2). '-'.substr($value["fecha"],5,2). '-'.substr($value["fecha"],0,4);?></p>
                  <p class="card-text">Inicio del Concierto:<?= substr($value["fecha"],11,5);?></p>
                  <div class="text-end">
                    <div class="btn-group text-end">
                      <a href="index.php?ctl=infConcierto&concierto=<?=$value["idConcierto"];?>"><button type="button" class="btn btn-sm btn-outline-secondary ">Mas informacion</button></a>
                    </div>
                    
                  </div>
                </div>
              </div>
            </div>
          <?php endforeach; ?>
        </div>
      <?php endif; ?>
</div>
          

      


 <?php $contenido = ob_get_clean() ?> 
 <?php ob_start() ?>
  <?php if(sizeof($conciertosCarrousel) != 0):?>
    <div id="myCarousel" class="carousel slide text-center" data-bs-ride="carousel">
        <div class="carousel-indicators">
          <?php for($i = 0 ; $i < sizeof($conciertosCarrousel) ; $i++):?>
            <?php if($i == 0):?>
              <button type="button" data-bs-target="#myCarousel" data-bs-slide-to="<?= $i; ?>" class="active" aria-current="true" aria-label="Slide 1"></button>
            <?php else: ?>
              <button type="button" data-bs-target="#myCarousel" data-bs-slide-to="<?= $i; ?>" aria-label="Slide 1"></button>
            <?php endif; ?>
          <?php endfor;?>
        </div>
        <div class="carousel-inner">
          
             <?php for($i = 0 ; $i < sizeof($conciertosCarrousel) ; $i++):?>
              <?php if($i == 0):?>
                <div class="carousel-item active">
                  <a href="index.php?ctl=infConcierto&concierto=<?=$conciertosCarrousel[$i]["idConcierto"];?>"><img class="imgCarrousel w-100" src="./web/imagenes/<?=$imagenes[$conciertosCarrousel[$i]['idConcierto']];?>"  alt=""></a>
                  <div class="container">

                    <div class="carousel-caption">
                      
                    </div>
                  </div>
                
                </div>
                <?php else: ?>
                  <div class="carousel-item">
                  <a href="index.php?ctl=infConcierto&concierto=<?=$conciertosCarrousel[$i]["idConcierto"];?>"><img class="imgCarrousel w-100" src="./web/imagenes/<?=$imagenes[$conciertosCarrousel[$i]['idConcierto']];?>"  alt=""></a>
                  <div class="container">

                    <div class="carousel-caption">
                      
                    </div>
                  </div>
                
                </div>
              <?php endif; ?>
            <?php endfor; ?>
          
        </div>
        <button class="carousel-control-prev" type="button" data-bs-target="#myCarousel" data-bs-slide="prev">
          <span class="carousel-control-prev-icon" aria-hidden="true"></span>
          <span class="visually-hidden">Previous</span>
        </button>
        <button class="carousel-control-next" type="button" data-bs-target="#myCarousel" data-bs-slide="next">
          <span class="carousel-control-next-icon" aria-hidden="true"></span>
          <span class="visually-hidden">Next</span>
        </button>
    </div>
  <?php endif;?>
 <?php $carrousel = ob_get_clean() ?> 
 <?php include 'base.php' ?>
