<?php ob_start() ?>
<div class="row addArtista">
    <div class="col-md-12 col-lg-8 offset-lg-2 py-2 ">
        <form action="" method="post" enctype="multipart/form-data">

            <div class="mb-3 error">
                <?=isset($mensaje)?$mensaje:''?>
            </div>

            <div class="mb-3 error text-center mt-2">
                <?=isset($errores['conciertoCorrecto'])?$errores['conciertoCorrecto']:''?>
            </div>

            <div class="mb-3 mx-3">
                <label for="nombre" class="form-label">Nombre</label>
                <input type="text" class="form-control" id="nombre" name="nombre" value="<?=isset($datosConcierto[0]['nombre'])?$datosConcierto[0]['nombre']:''?>">
                <div class="error text-center mt-2">
                    <?=isset($errores["nombre"])?$errores["nombre"]:''?>
                </div>
                
            </div>
            <div class="mb-3 mx-3">
                <label for="lugar" class="form-label">Lugar</label>
                <input type="text" class="form-control" id="lugar" name="lugar" value="<?=isset($datosConcierto[0]['lugar'])?$datosConcierto[0]['lugar']:''?>">
                <div class="error text-center mt-2 ">
                    <?=isset($errores["lugar"])?$errores["lugar"]:''?>
                </div>
            </div>
            <div class="mb-3 mx-3">
                <label for="fecha" class="form-label">Fecha</label>
                <input type="datetime-local" class="form-control" id="fecha" name="fecha" value="<?= isset($datosConcierto[0]['fecha'])?$datosConcierto[0]['fecha']:''?>">
                <div class="error text-center mt-2">
                    <?=isset($errores["fecha"])?$errores["fecha"]:''?>
                </div>
            </div>
            <div class="mb-3 mx-3">
                <label for="fecha" class="form-label">Aforo</label>
                <input type="number" class="form-control" id="aforo" name="aforo" value="<?= isset($datosConcierto[0]['aforo'])?$datosConcierto[0]['aforo']:''?>" min="0">
                <div class="error text-center mt-2">
                    <?=isset($errores["aforo"])?$errores["aforo"]:''?>
                </div>
            </div>
            <div class="mb-3 mx-3">
                <label for="artistas" class="form-label">Artistas</label>
                <select name="artistas" id="">
                    <option value="0">Seleccione un Artista</option>
                    <?php foreach ($artistas as $clave => $value):?>
                        <option <?=isset($datosConcierto[0]['idArtista']) && $datosConcierto[0]['idArtista'] == $value['idArtista']?'selected':''?> value="<?= $value["idArtista"]?>"><?=$value["nombre"];?></option>
                    <?php endforeach;?>
                </select>
                <div class="error text-center mt-2">
                    <?=isset($errores["idArtista"])?$errores["idArtista"]:''?>
                </div>
            </div>
                <div class="mb-3 mx-3">
                    <label for="imagenes" class="form-label">Imágenes</label>
                    <input class="form-control" type="file" id="imagenes" name="imagenes[]" multiple>
                    <div class="error text-center mt-2">
                        <?=isset($erroresImagenes["imagenes"])?$erroresImagenes["imagenes"]:''?>
                    </div>
                </div>
                <?php if(isset($datosConcierto[0]['ruta'])):?>
                    <div class="mb-3 mx-3">
                        <img src="<?='./web/imagenes/' . $datosConcierto[0]["ruta"];?>" alt="" class="img">
                    </div>
                <?php endif;?>
            <div class="mb-3 mx-3">
                <label  class="form-label">Num Entradas Normales</label>
                <input class="form-control" type="number" id="numEntradasNormales" min="1" name="numEntradasNormales" value="<?= isset($datosConcierto[0]['numEntradasNormales'])?$datosConcierto[0]['numEntradasNormales']:1?>">
                <div class="error text-center mt-2">
                    <?=isset($errores["numEntradasNormales"])?$errores["numEntradasNormales"]:''?>
                </div>
            </div>
            <div class="mb-3 mx-3">
                <label  class="form-label">Precio Entradas Normales</label>
                <input class="form-control" type="number" id="precioEntradasNormales" name="precioEntradasNormales" value="<?= isset($datosConcierto[0]['precioEntradasNormales'])?number_format($datosConcierto[0]['precioEntradasNormales'],2):''?>">
                <div class="error text-center mt-2">
                    <?=isset($errores["precioEntradasNormales"])?$errores["precioEntradasNormales"]:''?>
                </div>
            </div>
            <div class="mb-3 mx-3">
                <label  class="form-label">Num Entradas VIP</label>
                <input class="form-control" type="number" id="numEntradasVip" min="0" name="numEntradasVip" value="<?= isset($datosConcierto[0]['numEntradasVip'])?$datosConcierto[0]['numEntradasVip']:''?>">
                <div class="error text-center mt-2">
                    <?=isset($errores["numEntradasVip"])?$errores["numEntradasVip"]:''?>
                </div>
            </div>
            <div class="mb-3 mx-3">
                <label  class="form-label">Precio Entradas VIP</label>
                <input class="form-control" type="number" id="precioEntradasVip" name="precioEntradasVip" value="<?= isset($datosConcierto[0]['precioEntradasVip'])?number_format($datosConcierto[0]['precioEntradasVip'],2):''?>">
                <div class="error text-center mt-2">
                    <?=isset($errores["precioEntradasVip"])?$errores["precioEntradasVip"]:''?>
                    <?=isset($errores['numEntradasTotal'])?$errores['numEntradasTotal']:''?>
                </div>
                
            </div>

            <div style="height:300px;"id="map"></div>

            <div class="mb-3 mx-3">
                <label  class="form-label">Latitud</label>
                <input class="form-control" type="number" id="latitud" name="latitud" value="<?=isset($datosConcierto[0]['latitud'])?$datosConcierto[0]['latitud']:''?>" readonly step=any>
                <div class="error text-center mt-2">
                    <?=isset($errores["errorCordenadas"])?$errores["errorCordenadas"]:''?>
                </div>
                
            </div>
            <div class="mb-3 mx-3">
                <label  class="form-label">Longitud</label>
                <input class="form-control" type="number" id="longitud" name="longitud" value="<?=isset($datosConcierto[0]['longitud'])?$datosConcierto[0]['longitud']:''?>" readonly step=any>
                <div class="error text-center mt-2">
                    <?=isset($errores["errorCordenadas"])?$errores["errorCordenadas"]:''?>
                </div>
                
            </div>
            <input type="hidden" name="codConcierto" value="<?=$idConcierto?>">
                <?php if(isset($datosConcierto[0]['ruta'])):?>
                    <input type="hidden" name="imgConcierto" value="<?=$datosConcierto[0]["ruta"];?>">
                <?php endif;?>
            <div class="mb-3 mx-3">
                <input type="submit" value="Enviar" name="Enviar" class="btn btn-primary mb-3 mx-auto">
            </div>
        </form>
        
    </div>
</div>

  <?php $contenido = ob_get_clean() ?> 

<?php include 'base.php' ?>
<?php if(isset($datosConcierto[0]['longitud']) && isset($datosConcierto[0]['latitud']) && $accion == 'update'){
            echo "<script type='text/javascript'>var update = true; var updateLng = " .$datosConcierto[0]['longitud']." ;var updateLat = " . $datosConcierto[0]['latitud'] . ";</script>"; 
            echo '<script type="text/javascript" src="web/js/updateMap.js"></script>';
        }else{
            echo "<script type='text/javascript'>var update = false; </script>"; 
            echo '<script type="text/javascript" src="web/js/addMap.js"></script>';
        }?>

 



