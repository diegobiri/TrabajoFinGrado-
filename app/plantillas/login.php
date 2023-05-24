
<?php ob_start();?>
<fieldset id="iniSesion">
    <legend class="text-center">Iniciar sesión</legend>
    <form action="" method="post">
            <div class="mb-3 ">
                <label for="email" class="form-label">Correo Electrónico:</label>
                <input type="email" class="form-control" id="email" name="email" value="<?=isset(($_POST['email']))?$_POST['email']:''?>">
            </div>
            <div>
                <?=isset($errores["email"])?$errores["email"]:''?>
            </div>

            <div class="mb-3">
                <label for="password" class="form-label">Contraseña:</label>
                <input type="password" class="form-control" id="password" name="pass" value="">
            </div>
            <div>
                <?=isset($error)?'<p class="error">Usuario o contraseña incorrectos</p>':'';?>
            </div>
            <div class="w-100 text-center">
                <input type="submit" class="btn btn-primary mb-3 mx-auto" name="ok" value="Ingresar">
            </div>
        <input type="hidden" name="codConcierto" value="<?= isset($_GET["concierto"])?$_GET["concierto"]:''?>">
        <p>
            <a href="index.php?ctl=registroUsuario">No tiene una cuenta. Registrarse.</a>
        </p>
        <p>
            <a href="index.php?ctl=recuperarContraseña">Recuperar contraseña</a>
        </p>
        
        <?=isset($errorCompra)?$errorCompra:'';?>
    </form>
</fieldset>


<?php $contenido = ob_get_clean();?>
<?php include 'base.php';?>



