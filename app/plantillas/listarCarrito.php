
<?php ob_start() ?>
<?php if(isset($conciertos) && !empty($conciertos)):?>
    <?php $sumaTotal = 0;?>
    <h2 class="text-center my-5">Mis entradas del carrito</h2>
      <?php foreach ($conciertos as $clave => $value):?>
        <div class="row rounded border border-secondary">
          <div class="col-md-6 col-lg-4 col-xl-4 offset-lg-2 py-2">
            <p>Nombre del Concierto: <?= $value[0]["nombre"];?></p>
            <p>Lugar del concierto: <?= $value[0]["lugar"];?></p>
            <p>Fecha: <?= $value[0]["fecha"];?></p>
            <?php if($value["vip"] == 0): ?>
                <p>Número de entradas: <?= $entradaCarrito[$value[0]["idConcierto"]];?></p>
                <p>Precio de cada entrada: <?= substr($value[0]["precioEntradasNormales"],0,5);?>€</p>
                <p>Precio total de las entradas: <?= round($entradaCarrito[$value[0]["idConcierto"]] * (float)substr($value[0]["precioEntradasNormales"],0,5),2)?>€ </p>
                <?php $sumaTotal += (float)round($entradaCarrito[$value[0]["idConcierto"]] * (float)substr($value[0]["precioEntradasNormales"],0,5),2);?>
                <?php else: ?>
                <p>Número de entradas: <?= $entradaCarritoVip[$value[0]["idConcierto"]];?></p>
                <p>Precio de cada entrada:<?= substr($value[0]["precioEntradasVip"],0,5);?>€</p>
                <p>Precio total de las entradas: <?= round($entradaCarritoVip[$value[0]["idConcierto"]] * (float)substr($value[0]["precioEntradasVip"],0,5),2)?>€ </p>
                <?php $sumaTotal += (float)round($entradaCarritoVip[$value[0]["idConcierto"]] * (float)substr($value[0]["precioEntradasVip"],0,5),2);?>
            <?php endif; ?>
          </div>
            <div class="col-md-6 col-lg-4 col-xl-4 offset-lg-2 py-2">
              <div id="qrcode"></div>
                <img src="./web/imagenes/<?=$value[0]["ruta"];?>" class="tamaImg" alt="">
              </div>
            </div>
        </div>
      <?php endforeach; ?>
      <div class="text-center mt-2">
        <p>Suma Total:<?=$sumaTotal;?>€</p>
        <p><a href="index.php?ctl=comprarEntradas"><button type="button" class="btn btn-primary">Comprar</button></a></p>
      </div>
      <?php else: ?>
        <p class="text-center error mt-2">No hay entradas añadidas al carrito</p>
        <?php endif; ?>
<?php $contenido = ob_get_clean() ?> 

<?php include 'base.php' ?>


        
