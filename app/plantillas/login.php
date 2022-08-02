<?php ob_start();?>

<fieldset id="iniSesion">
    <legend>Iniciar sesión</legend>
    <form action="" method="post">
        <p>
            <label>Correo Electrónico:<br><input type="text" name="usu" value="" required></label>
        </p>
        <p>
            <label>Contraseña:<br><input type="password" name="pass" value=""  pattern="(?=.*[A-Z])(?=.*[a-z])(?=.*[0-9])(?=.*\W).{8,16}" required></label>
        </p>
        <input type="submit" name="ok" value="Ingresar">
        <p>
            <a href="index.php?ctl=registroUsuario">No tiene una cuenta. Registrarse.</a>
        </p>
        <?=isset($error)?'<p class="error">Usuario o contraseña incorrectos</p>':'';?>
    </form>
</fieldset>

<?php $contenido = ob_get_clean();?>
<?php include 'base.php';?>