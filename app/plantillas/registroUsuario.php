<?php ob_start();?>
        <form action="" method="post" class="form-width registro">
        <legend class="text-center my-3">Cuenta</legend>
        <div class="row mx-3">
            <div class="mb-3 col-md-6 col-12 text-center">
                    <label for="email" class="form-label">Correo Electrónico:</label>
                    <input type="email" class="form-control" id="email" name="email" value="<?=isset(($_POST['email']))?$_POST['email']:''?>">
                
                <div class="error text-center mt-2">
                    <?=isset($errores["email"])?$errores["email"]:''?>
                </div>
            </div>

                <div class="mb-3 col-md-6 col-12 text-center">
                    <label for="password" class="form-label ">Contraseña:</label>
                    <input type="password" class="form-control" id="password" name="pass" value="">
                
                    <div class="error text-center mt-2">
                        <?=isset($errores["pass"])?$errores["pass"]:''?>
                    </div>
                </div>
        </div>
            
        <legend class="text-center my-3">Detalles Personales</legend>
        <div class="row mx-3">
            <div class="mb-3 col-md-4 col-12 text-center">
                <label for="nombre" class="form-label">Nombre</label>
                <input type="text" class="form-control" id="" name="nombre" value="<?=isset($datosUsuario[0]['nombre'])?$datosUsuario[0]['nombre'] : ''?>">
            
                <div class="error text-center mt-2">
                    <?=isset($errores["nombre"])?$errores["nombre"]:''?>
                </div>
            </div>
            <div class="mb-3 col-md-4 col-12 text-center">
                <label for="primerApellido" class="form-label">Primer Apellido</label>
                <input type="text" class="form-control" id="" name="primerApellido" value="<?=isset($datosUsuario[0]['primerApellido'])?$datosUsuario[0]['primerApellido'] : ''?>">
           
                <div class="error text-center mt-2">
                    <?=isset($errores["primerApellido"])?$errores["primerApellido"]:''?>
                </div>
            </div>
            <div class="mb-3 col-md-4 col-12 text-center">
                <label for="segundoApellido" class="form-label">Segundo Apellido</label>
                <input type="text" class="form-control" id="" name="segundoApellido" value="<?=isset($datosUsuario[0]['segundoApellido'])?$datosUsuario[0]['segundoApellido'] : ''?>">
            
                <div class="error text-center mt-2">
                    <?=isset($errores["segundoApellido"])?$errores["segundoApellido"]:''?>
                </div>
            </div>
        </div>
        <div class="row mx-3">
            <div class="mb-3 col-md-6 col-12 text-center">
                <label for="docIdentificacion" class="form-label">Documento de Identidad </label>
                <input type="text" class="form-control" id="" name="docIdentificacion" value="<?=isset($datosUsuario[0]['docIdentificacion'])?$datosUsuario[0]['docIdentificacion'] : ''?>">
            
                <div class="error text-center mt-2">
                    <?=isset($errores["docIdentificacion"])?$errores["docIdentificacion"]:''?>
                </div>
            </div>
            <div class="mb-3 col-md-6 col-12 text-center">
                <label for="fechaNacimiento" class="form-label">Fecha Nacimiento </label>
                <input type="date" class="form-control" id="" name="fechaNacimiento" value="<?=isset($datosUsuario[0]['fechaNacimiento'])?$datosUsuario[0]['fechaNacimiento'] : ''?>">
                <div class="error text-center mt-2">
                    <?=isset($errores["fechaNacimiento"])?$errores["fechaNacimiento"]:''?>
                </div>
            </div>
        </div>
        <div class="row mx-3">
            <div class="mb-3 col-md-6 col-12 text-center">
                <label for="telefonoMovil" class="form-label">Telefono Movil </label>
                <input type="text" class="form-control" id="" name="telefonoMovil" value="<?=isset($datosUsuario[0]['telefonoMovil'])?$datosUsuario[0]['telefonoMovil'] : ''?>">
            
                <div class="error text-center mt-2">
                    <?=isset($errores["telefonoMovil"])?$errores["telefonoMovil"]:''?>
                </div>
            </div>
            <div class="mb-3 col-md-6 col-12 mx-3">
                <label for="genero-hombre" class="form-label">Genero</label><br>
                <input type="radio" name="genero" value="Masculino" id="genero-hombre" checked>
                <label for="" class="radio">Hombre</label>
                <input type="radio" name="genero" value="Femenino" id="genero-mujer">
                <label for="" class="radio">Mujer</label>
                <div class="error text-center mt-2">
                    <?=isset($errores["genero"])?$errores["genero"]:''?>
                </div>   
            </div>
        </div>  
        <div class="mb-3 mx-3">
            <input type="submit" class="btn btn-primary mb-3" value="Registro" name="Registro">
        </div>        
        <div class="mb-3 error">
                    <?=isset($errores["usuarioCorrecto"])?$errores["usuarioCorrecto"]:''?>
        </div>
    </form>
<?php $contenido = ob_get_clean();?>
<?php include 'base.php';?>