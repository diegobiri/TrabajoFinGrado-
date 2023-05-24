<?php ob_start() ?>
    <form action="" method="post">
            <label for="">Email <input type="email" name="email" id="" value="<?php isset($_POST["email"]) ? $_POST["email"] : ''?>"></label><br>
            <?=isset($errores["email"])?$errores["email"]:''?>
            <input type="submit" value="Recuperar" name="Recuperar">
    </form>
    <?php $contenido = ob_get_clean() ?> 
<?php include 'base.php' ?>