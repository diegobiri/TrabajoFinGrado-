<?php ob_start() ?>
<div class="row">
    <div class="col-md-12 col-lg-8 offset-lg-2 py-2">
        <form action="" method="post" enctype="multipart/form-data">
            <div class="mb-3 mx-3">
                <label for="nombre" class="form-label align-items-center">Nombre</label>
                <input type="text" class="form-control" id="nombre" name="nombre" value="<?=isset($datosArtista[0]['nombre'])?$datosArtista[0]['nombre']:''?>">
                <div class="error text-center mt-2">
                    <?=isset($errores["nombre"])?$errores["nombre"]:''?>
                </div>
            </div>
            <div class="mb-3 mx-3">
                <label for="generoMusical" class="form-label">Género Musical</label>
                <input type="text" class="form-control" id="generoMusical" name="generoMusical" value="<?=isset($datosArtista[0]['generoMusical'])?$datosArtista[0]['generoMusical']:''?>">
                <div class="error text-center mt-2">
                    <?=isset($errores["generoMusical"])?$errores["generoMusical"]:''?>
                </div>
            </div>
            <div class="mb-3 mx-3">
                <label for="pais" class="form-label">País</label>
                <input type="text" class="form-control" id="pais" name="pais" value="<?=isset($datosArtista[0]['pais'])?$datosArtista[0]['pais']:''?>">
                <div class="error text-center mt-2">
                    <?=isset($errores["pais"])?$errores["pais"]:''?>
                </div>
            </div>
            <div class="mb-3 mx-3">
                <label for="descripcion" class="form-label">Descripción</label>
                <input type="text" class="form-control" id="descripcion" name="descripcion" value="<?=isset($datosArtista[0]['descripcion'])?$datosArtista[0]['descripcion']:''?>">
                <div class="error text-center mt-2">
                    <?=isset($errores["descripcion"])?$errores["descripcion"]:''?>
                </div>
            </div>
            
          
            <div class="mb-3 mx-3">
                <label for="imagenes" class="form-label">Imágenes</label>
                <input class="form-control" type="file" id="imagenes" name="imagenes[]">
                <div class="error text-center mt-2">
                    <?=isset($erroresImagenes["imagenes"])?$erroresImagenes["imagenes"]:''?>
                </div>
            </div>

            <div class="mb-3 mx-3">
                <img src="<?='./web/imagenes/imagenArtista/' . $datosArtista[0]["imagenArtista"];?>" alt="" class="img">
            </div>

            <input type="hidden" name="codArtista" value="<?=$idArtista?>">
            <input type="hidden" name="imgArtista" value="<?=$datosArtista[0]["imagenArtista"];?>">

            <div class="mb-3 mx-3">
                <input type="submit" value="Enviar" name="Enviar" class="btn btn-primary mb-3 mx-auto">
            </div>
                <div class="mb-3 error text-center mt-2">
                    <?=isset($errores["artistaCorrecto"])?$errores["artistaCorrecto"]:''?>
                </div>
        </form>
    </div>
</div>
  <?php $contenido = ob_get_clean() ?> 

<?php include 'base.php' ?>