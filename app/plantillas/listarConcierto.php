<?php ob_start() ?>
    <table class="table table-striped">

    <thead>
        <tr>
            <th scope="col">Id</th>
            <th scope="col">Nombre</th>
            <th scope="col">Fecha</th>
            <th scope="col">Hora</th>
            <th scope="col">Aforo</th>
            <th scope="col">Nombre Artista</th>
            <th scope="col">Precio Entradas Normales</th>
            <th scope="col">Editar</th>
            <th scope="col">Eliminar</th>
            <th scope="col">Editar Imagenes Concierto</th>
        </tr>
    </thead>

    <tbody>
        <?php if(sizeof($conciertos) == 0):?>
            <tr>
                <td colspan="8">No hay conciertos disponibles</td>
            </tr>
        <?php else:?>
            <?php foreach($conciertos as $clave => $value):?>
                <tr>
                    <th scope="row"><?=$value['idConcierto'];?></th>
                    <td><?=$value['nombre'];?></td>
                    <td><?=substr($value["fecha"], 8,2) . '-'.substr($value["fecha"], 5,2) . '-' . substr($value["fecha"], 0,4);?></td>
                    <td><?=substr($value["fecha"], 11,5);?></td>
                    <td><?=$value['aforo'];?></td>
                    <td><?=$value['nombreArtista'];?></td>
                    <td><?=number_format($value['precioEntradasNormales'],2);?>€</td>
                    <td><a href="index.php?ctl=updateConcierto&idConcierto=<?=$value['idConcierto']?>" class="nav-link px-2 text-secondary"><img class="bi"  width="24" height="24" src="web/resources/tools.svg"></img></a></td>
                    <td><a href="index.php?ctl=deleteConcierto&idConcierto=<?=$value['idConcierto']?>" class="nav-link px-2 text-secondary"><img class="bi"  width="24" height="24" src="web/resources/trash.svg"></img></a></td>
                    <td><a href="index.php?ctl=verImagenesConcierto&idConcierto=<?=$value['idConcierto']?>" class="nav-link px-2 text-secondary"><img class="bi"  width="24" height="24" src="web/resources/tools.svg"></img></a></td>
                </tr>
            <?php endforeach; ?>
        <?php endif; ?>
    </tbody>
    </table>
<?php $contenido = ob_get_clean();?>
<?php include 'base.php';?>

