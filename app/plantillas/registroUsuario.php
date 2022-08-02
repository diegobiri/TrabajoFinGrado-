<?php ob_start();?>
<fieldset>
    <div>
        <legend>Cuenta</legend>
        <form action="" method="post">
            <label for="">Email <input type="email" name="email" id="" value=""></label><br>
            <label for="">Contraseña <input type="password" name="password" id="" value=""  pattern="(?=.*[A-Z])(?=.*[a-z])(?=.*[0-9])(?=.*\W).{8,16}" required></label><br>
            <label for="">Confirmar Contraseña <input type="password" name="passwordConfirm" id="" value=""></label>
        </form>
    </div>
</fieldset>
<fieldset>
    <div>
        <legend>Detalles Personales</legend>
        <form action="" method="post">
            <label for="">Nombre <input type="text" name="nombre" id="" value=""></label>
            <label for="">Primer Apellido <input type="text" name="apellido" id="" value=""></label>
            <label for="">Segundo Apellido <input type="text" name="segundoApellido" id="" value=""></label><br>
            <label for="">Calle <input type="text" name="calle" maxlength="40" id="" value=""></label>
            <label for="">Numero <input type="number" name="numPortal"  id="" value=""></label>
            <label for="">Piso <input type="text" name="piso" maxlength="40" id="" value=""></label><br>
            <label for="">Codigo Postal <input type="text" name="numPortal" autocomplete="codigoPostal"></label>
            <label for="">Ciudad <input type="text" name="ciudad" maxlength="40" id="" value=""></label></label>
            <label for="">Edad <input type="number" name="edad" id="" min="18" maxlength=""></label>
            <label for="">Telefono Movil <input type="text" name="telefonoMovil" maxlength="9" id="" value=""></label>
        </form>
    </div>
    <div>
        <legend>Genero</legend>
        <input type="radio" name="genero" value="" id="genero-hombre">
        <label for="" class="radio">Hombre</label>
        <input type="radio" name="genero" value="" id="genero-mujer">
        <label for="" class="radio">Mujer</label>
    </div>
    <div>
        <legend>Generos musicales que te gusten</legend>
        <ul>
            <li>
                <input type="checkbox" name="gustosMusicales" id="" class="" value=""><label for="">Electronica</label>
            </li>
            <li>
                <input type="checkbox" name="gustosMusicales" id="" class="" value=""><label for="">Rock</label>
            </li>
            <li>
                <input type="checkbox" name="gustosMusicales" id="" class="" value=""><label for="">Pop</label>
            </li>
            <li>
                <input type="checkbox" name="gustosMusicales" id="" class="" value=""><label for="">Reggaeton </label>
            </li>
        </ul>
    </div>
</fieldset>
<?php $contenido = ob_get_clean();?>
<?php include 'base.php';?>