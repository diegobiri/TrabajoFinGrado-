<?php ob_start() ?>
<div class="row">
    <div class="col-md-12 col-lg-8 offset-lg-2 py-2">
        <form action="" method="post" enctype="multipart/form-data">
            <legend class="text-center my-3 title">Detalles Personales</legend>
                <div class="row mx-5">
                    <div class="mb-3 col-md-4 col-12">
                        <label for="nombre" class="form-label">Nombre</label>
                        <input type="text" class="form-control" id="" name="nombre" value="<?=isset($datosUsuario[0]['nombre'])?$datosUsuario[0]['nombre'] : ''?>">
                    
                        <div class="error">
                            <?=isset($errores["nombre"])?$errores["nombre"]:''?>
                        </div>
                    </div>
                    <div class="mb-3 col-md-4 col-12">
                        <label for="primerApellido" class="form-label">Primer Apellido</label>
                        <input type="text" class="form-control" id="" name="primerApellido" value="<?=isset($datosUsuario[0]['primerApellido'])?$datosUsuario[0]['primerApellido'] : ''?>">
                
                        <div class="error">
                            <?=isset($errores["primerApellido"])?$errores["primerApellido"]:''?>
                        </div>
                    </div>
                    <div class="mb-3 col-md-4 col-12">
                        <label for="segundoApellido" class="form-label">Segundo Apellido</label>
                        <input type="text" class="form-control" id="" name="segundoApellido" value="<?=isset($datosUsuario[0]['segundoApellido'])?$datosUsuario[0]['segundoApellido'] : ''?>">
                    
                        <div class="error">
                            <?=isset($errores["segundoApellido"])?$errores["segundoApellido"]:''?>
                        </div>
                    </div>
                </div>
                <div class="row mx-5">
                    <div class="mb-3 col-md-6 col-12">
                        <label for="docIdentificacion" class="form-label">Documento de Identidad </label>
                        <input type="text" class="form-control" id="" name="docIdentificacion" value="<?=isset($datosUsuario[0]['docIdentificacion'])?$datosUsuario[0]['docIdentificacion'] : ''?>">
                    
                        <div class="error">
                            <?=isset($errores["docIdentificacion"])?$errores["docIdentificacion"]:''?>
                        </div>
                    </div>
                    <div class="mb-3 col-md-6 col-12">
                        <label for="fechaNacimiento" class="form-label">Fecha Nacimiento </label>
                        <input type="date" class="form-control" id="" name="fechaNacimiento" value="<?=isset($datosUsuario[0]['fechaNacimiento'])?$datosUsuario[0]['fechaNacimiento'] : ''?>">
                        <div class="error">
                            <?=isset($errores["fechaNacimiento"])?$errores["fechaNacimiento"]:''?>
                        </div>
                    </div>
                </div>
                <div class="row mx-5">
                    <div class="mb-3 col-md-6 col-12">
                        <label for="telefonoMovil" class="form-label">Teléfono Móvil </label>
                        <input type="text" class="form-control" id="" name="telefonoMovil" value="<?=isset($datosUsuario[0]['telefonoMovil'])?$datosUsuario[0]['telefonoMovil'] : ''?>">
                    
                        <div class="error">
                            <?=isset($errores["telefonoMovil"])?$errores["telefonoMovil"]:''?>
                        </div>
                    </div>
                    <div class="mb-3 col-md-6 col-12">
                        <label for="genero-hombre" class="form-label">Género</label><br>
                        <input type="radio" name="genero" value="Masculino" id="genero-hombre" checked>
                        <label for="" class="radio">Hombre</label>
                        <input type="radio" name="genero" value="Femenino" id="genero-mujer">
                        <label for="" class="radio">Mujer</label>
                        <div class="error">
                            <?=isset($errores["genero"])?$errores["genero"]:''?>
                        </div>   
                    </div>
                    <input type="submit" class="btn btn-primary mb-3 mx-auto" value="actualizar" name="actualizar">
                    <div class="error">
                            <?=isset($errores['usuarioActualizado'])?$errores['usuarioActualizado']:''?>
                    </div>
                </div>           
                
        </form>
        
        <form action=""  method="post" enctype="multipart/form-data">
            <legend class="text-center my-3 title">Cambiar Contraseña</legend>
            <div class="row mx-5">
                <div class="mb-3">
                    <label for="password" class="form-label">Nueva Contraseña:</label>
                    <input type="password" class="form-control" id="password" name="newPass" value="<?=isset($_POST['newPass']) ? $_POST['newPass'] : ''?>">
                </div>
                <div class="mb-3">
                    <label for="password" class="form-label">Confirmar Contraseña:</label>
                    <input type="password" class="form-control" id="password" name="newPass2" value="">
                </div>
                <div class="error mb-2 text-center">
                                <?=isset($errores['passwordError'])?$errores['passwordError']:''?>
                        </div>
                <input type="submit" class="btn btn-primary mb-3 mx-auto" value="cambiar" name="cambiar">
            </div>
            
        </form>
    </div>
</div>
<?php $contenido = ob_get_clean() ?> 

<?php include 'base.php' ?>