<?php ob_start() ?>
<div class="container-fluid p-5">
  <div class="row mt-5">
    <h1 class="text-center">Información sobre el concierto</h1>
      <div class="col col-lg-12 col-xl-7 col-12">
      <?php if(isset($imagenesCarrusel) && sizeof($imagenesCarrusel) != 0):?>
      <div id="myCarousel" class="carousel slide text-center infConcierto" data-bs-ride="carousel">
          <div class="carousel-indicators">
            <?php for($i = 0 ; $i < sizeof($imagenesCarrusel) ; $i++):?>
              <?php if($i == 0):?>
                <button type="button" data-bs-target="#myCarousel" data-bs-slide-to="<?= $i; ?>" class="active" aria-current="true" aria-label="Slide 1"></button>
              <?php else: ?>
                <button type="button" data-bs-target="#myCarousel" data-bs-slide-to="<?= $i; ?>" aria-label="Slide 1"></button>
              <?php endif; ?>
            <?php endfor;?>
          </div>
          <div class="carousel-inner">
            
              <?php for($i = 0 ; $i < sizeof($imagenesCarrusel) ; $i++):?>
                <?php if($i == 0):?>
                  <div class="carousel-item active">
                  <img class="imgCarrousel" src="./web/imagenes/<?=$imagenesCarrusel[$i]['ruta'];?>"  alt="">
                    <div class="container">

                      <div class="carousel-caption">
                        
                      </div>
                    </div>
                  
                  </div>
                  <?php else: ?>
                    <div class="carousel-item">
                    <img class="imgCarrousel" src="./web/imagenes/<?=$imagenesCarrusel[$i]['ruta'];?>"  alt="">
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
      </div>
        
      <div class="col-lg-12 col-xl-5 col-12 infConciertoP">
        <div class="row">
          <div class="col-lg-6 col-xl-12 col-12 infConciertoP">
            <h1 class=""><?=$conciertos[0]["nombre"]?></h1><br>
            <p>Fecha: <?=substr($conciertos[0]["fecha"], 8,2) . '-'.substr($conciertos[0]["fecha"], 5,2) . '-' . substr($conciertos[0]["fecha"], 0,4);?></p>
            <p>Hora: <?=substr($conciertos[0]["fecha"], 11,5);?></p>
            <p>Lugar del Concierto: <?=$conciertos[0]["lugar"]?></p>
            <p>Artista: <?=$conciertos[0]["nombreArtista"]?></p>
            <br>
          </div>
          <div class="col-lg-6 col-xl-12 col-12 infConciertoP">          
            <h4 class="infConciertoP">COMPRAR</h4><br>
              <form action="index.php?ctl=addEntradaCarrito&codConcierto=<?=$idConcierto;?>" method="post">
                  <label for="" class="mb-3 ">Tipo de Entradas</label><select name="tipoEntrada" id="">
                      <option value="normal">Normal - <?= round($conciertos[0]["precioEntradasNormales"],2)?>€</option>
                      <option value="vip">VIP - <?= round($conciertos[0]["precioEntradasVip"],2)?>€</option>
                  </select><br>
                  <label for="" class="mb-3 ">¿Cuántas entradas quieres?</label>
                  <input type="number" min="1" name="numEntradas">
                  <input type="hidden" name="codConcierto" value="<?=$idConcierto?>">
                  <?php if($conciertos[0]["numEntradasNormales"] >= 0):?>
                      <p>Quedan <?=$conciertos[0]["numEntradasNormales"];?>Normales</p>
                  <?php else:?>
                      <p style="error color:red;">No quedan entradas normales</p>
                  <?php endif;?>
                  <?php if($conciertos[0]["numEntradasVip"] >= 0):?>
                      <p>Quedan <?=$conciertos[0]["numEntradasVip"];?>VIP</p>
                  <?php else:?>
                      <p style="color:red;">No quedan entradas VIP</p>
                  <?php endif;?>
                  <p class="mt-auto"><input type="submit" value="Añadir al Carrito" name="Comprar" class="btn btn-primary"></p>
                  <p class="error"><?= isset($errorNumEntradas)?$errorNumEntradas:'';?></p>
              </form>
          </div>
         
        </div>
      </div>
  </div>

  <div class="row d-flex justify-content-center align-items-center">
  <h1 class="text-center">Ubicación</h1>
      <div class="col-md-12 col-xl-12 col-12">
          <div id="map"></div>
      </div>
  </div>
</div>

<?php $contenido = ob_get_clean();?>
<?php include 'base.php';?>
<?php
    if(!empty($conciertos[0]["longitud"]) && !empty($conciertos[0]["latitud"]))
    {
        echo "<script type='text/javascript'>var updateLng = " .$conciertos[0]['longitud']." ;var updateLat = " . $conciertos[0]['latitud'] . ";</script>"; 
        echo '<script type="text/javascript" src="web/js/updateMap.js"></script>';
    }      
?>