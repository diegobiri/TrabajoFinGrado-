<?php ob_start() ?>
<?php if(isset($getImagenes) && !empty($getImagenes)):?>
<table class="table">

    <thead>
        <tr>
            <th scope="col">Imagenes</th>
            <th>Eliminar</th>
        </tr>
    </thead>
    <tbody>
        <?php foreach($getImagenes as $clave => $value): ?>
        <tr scope="col">
            <td><img src="./web/imagenes/<?=$value["ruta"];?>" alt="" class="imgConciertoCambiar"></td>
            <td><a href="index.php?ctl=deleteImgConcierto&idImagen=<?=$value['idImagen']?>&idConcierto=<?=$value['idConcierto']?>" class="nav-link px-2 text-secondary"><img class="bi"  width="24" height="24" src="web/resources/trash.svg"></img></a></td>
        </tr>
        <?php endforeach;?>
    </tbody>
</table>
<?php else: ?>
        <p class="text-center error mt-2">No hay imagenes en el concierto</p>
        <?php endif; ?>
    <form action="" method="post" enctype="multipart/form-data">
        <div class="mb-3 mx-3">
                        <label for="imagenes" class="form-label">Imágenes</label>
                        <input class="form-control" type="file" id="imagenes" name="imagenes[]" multiple>
                        <div class="error text-center mt-2">
                            <?=isset($erroresImagenes["imagenes"])?$erroresImagenes["imagenes"]:''?>
                        </div>
        </div>
        <input type="hidden" name="codConcierto" value="<?=$_GET['idConcierto']?>">
        <div class="mb-3 mx-3">
                <input type="submit" value="Enviar" name="Enviar" class="btn btn-primary mb-3 mx-auto">
            </div>
    </form>
    <?php $contenido = ob_get_clean() ?> 
<?php include 'base.php' ?>