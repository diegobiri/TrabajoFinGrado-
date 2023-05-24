<?php ob_start() ?>
    <table class="table">

    <thead>
        <tr>
            <th scope="col">Nombre</th>
            <th scope="col">Primer Apellido</th>
            <th scope="col">Segundo Apellido</th>
            <th scope="col">Documento de Identidad</th>
            <th scope="col">Fecha Nacimiento</th>
            <th scope="col">Telefono Movil</th>
            <th scope="col">Genero</th>
            <th scope="col">Generos musicales que te gusten</th>
            <th scope="col">Eliminar</th>
        </tr>
    </thead>

    <tbody>
        <?php if(sizeof($usuarios) == 0):?>
            <tr>
                <td colspan="8">No hay usuarios registrados en la web</td>
            </tr>
        <?php else:?>
            <?php foreach($usuarios as $clave => $value):?>
                <tr>
                    <th scope="row"><?=$value['idUsuario'];?></th>
                    <td><?=$value['nombre'];?></td>
                    <td><?=substr($value["fechaNacimiento"], 8,2) . '-'.substr($value["fechaNacimiento"], 5,2) . '-' . substr($value["fechaNacimiento"], 0,4);?></td>
                    <td><?=$value['primerApellido'];?></td>
                    <td><?=$value['segundoApellido'];?></td>
                    <td><?=$value['docIdentificacion'];?></td>
                    <td><?=$value['telefonoMovil'];?></td>
                    <td><?=$value['genero'];?></td>
                    <td><?=$value['gustosMusicales[]'];?></td>
                    <td><a href="index.php?ctl=deleteUsuario&idUsuario=<?=$value['idUsuario']?>" class="nav-link px-2 text-secondary"><img class="bi"  width="24" height="24" src="web/resources/trash.svg"></img></a></td>
                </tr>
            <?php endforeach; ?>
        <?php endif; ?>
    </tbody>
    </table>
<?php $contenido = ob_get_clean();?>
<?php include 'base.php';?>