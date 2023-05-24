<?php ob_start() ?>
<h2 class="text-center mt-5">Crear Hilos</h2>
<form action="" method="post" class="form-width text-center">
    <div class="mb-3">
        <label for="" class="form-label">Título</label>
        <input type="text" class="form-control" name="titulo" id="titulo" value="<?= isset($_POST["titulo"])?$_POST['titulo']:''?>">
    </div>
    <div class="mb-3">
        <label for="" class="form-label">Descripción</label>
        <textarea class="form-control"  name="descripcion" id="descripcion"  value="<?=isset($_POST["descripcion"])?$_POST['descripcion']:''?>"></textarea>
        <div class="error text-center mt-2">
                    <?=isset($errores["hilo"])?$errores["hilo"]:''?>
                </div>
    </div>
    <?php if(isset($_GET['codHilo'])):?>
        <input type="hidden" name="codHilo" value="<?=$_GET['codHilo']?>">
    <?php endif;?>
    <div class="text-center">
        <input type="submit" class="btn btn-primary mb-3 mx-auto w-25" value="crear" name="crear">
    </div>
</form>
<?php $contenido = ob_get_clean() ?> 

<?php include 'base.php' ?>


