<?php ob_start() ?>
    <div>
        <?=isset($errores['conciertoArtista'])?$errores['conciertoArtista']:'';?>
    </div>
    
    <table class="table">

    <thead>
        <tr>
            <th scope="col">Id</th>
            <th scope="col">Nombre</th>
            <th scope="col">Género Musical</th>
            <th scope="col">País</th>
            <th scope="col">Descripción</th>
            <th scope="col">Editar</th>
            <th scope="col">Eliminar</th>
        </tr>
    </thead>

    <tbody>
        <?php if(sizeof($artistas) == 0):?>
            <tr>
                <td colspan="8">No hay artistas disponibles</td>
            </tr>
        <?php else:?>
            <?php foreach($artistas as $clave => $value):?>
                <tr>
                    <th scope="row"><?=$value['idArtista'];?></th>
                    <td><?=$value['nombre'];?></td>
                    <td><?=$value['generoMusical'];?></td>
                    <td><?=$value['pais'];?></td>
                    <td><?=$value['descripcion'];?></td>
                    <td><a href="index.php?ctl=updateArtista&idArtista=<?=$value['idArtista']?>" class="nav-link px-2 text-secondary"><img class="bi"  width="24" height="24" src="web/resources/tools.svg"></img></a></td>
                    <td><a href="index.php?ctl=deleteArtista&idArtista=<?=$value['idArtista']?>" class="nav-link px-2 text-secondary"><img class="bi"  width="24" height="24" src="web/resources/trash.svg"></img></a></td>
                </tr>
            <?php endforeach; ?>
        <?php endif; ?>
    </tbody>
    </table>
<?php $contenido = ob_get_clean();?>
<?php include 'base.php';?>
