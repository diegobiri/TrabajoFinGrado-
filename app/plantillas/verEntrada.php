<?php ob_start();?>
    <div class="row">
        
        <div class="col-md-6 col-lg-4 col-xl-4 offset-lg-2 py-2">
            <p>Nombre del concierto: <?=$entradas[0]['nombreConcierto']; ?></p>
            <p>Fecha: <?=substr($entradas[0]["fecha"], 8,2) . '-'.substr($entradas[0]["fecha"], 5,2) . '-' . substr($entradas[0]["fecha"], 0,4); ?></p>
            <p>Hora: <?=substr($entradas[0]["fecha"], 11,5); ?></p>
            <p>Lugar: <?=$entradas[0]["lugar"]; ?></p>
            <p>Tipo entrada: <?=$entradas[0]["tipoEntrada"]; ?></p>
            <p>Precio: <?=$entradas[0]["precio"]; ?></p>
        </div>
        <div class="col-md-6 col-lg-4 col-xl-4 offset-lg-2 py-2">
        <div id="qrcode"></div>
            
        </div>
    </div>
   
<?php $contenido = ob_get_clean();?>
<?php include 'base.php';?>
<script type="text/javascript">
    var codEntrada = <?= $entradas[0]['idEntrada'];?>;
    var codUsuario = <?= $entradas[0]['idUsuario'];?>;
    var ruta = "http://localhost/ConciertosProyecto/TrabajoFinGrado-/index.php?ctl=comprobarEntrada&idEntrada=" + codEntrada + "&idUsuario=" + codUsuario;
                new QRCode(document.getElementById("qrcode"), ruta) ;
    </script>

