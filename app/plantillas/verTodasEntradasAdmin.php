<?php ob_start();?>
<table class="table">

    <thead>
        <tr>
            <th scope="col">Id Entrada</th>
            <th scope="col">Id Usuario</th>
            <th scope="col">Nombre Concierto</th>
            <th scope="col">Fecha</th>
            <th scope="col">Hora</th>
            <th scope="col">Nombre Artista</th>
            <th scope="col">Tipo Entrada</th>
            <th scope="col">Precio</th>
            <th scope="col">Devolver Entrada</th>
        </tr>
    </thead>

    <tbody>
        <?php if(sizeof($entradas) == 0):?>
            <tr>
                <td colspan="8">No hay entradas compradas</td>
            </tr>
        <?php else:?>
            <?php foreach($entradas as $clave => $value):?>
                <tr>
                    <td><?=$value['idEntrada'];?></td>
                    <td><?=$value['idUsuario'];?></td>
                    <td><?=$value['nombreConcierto'];?></td>
                    <td><?=substr($value["fecha"], 8,2) . '-'.substr($value["fecha"], 5,2) . '-' . substr($value["fecha"], 0,4);?></td>
                    <td><?=substr($value["fecha"], 11,5);?></td>
                    <td><?=$value['nombreArtista'];?></td>
                    <td><?=$value['tipoEntrada'];?></td>
                    <td><?=number_format($value['precio'],2);?></td>
                    <td><a href="index.php?ctl=deleteEntradaUsuario&idEntrada=<?=$value['idEntrada']?>" class="nav-link px-2 text-secondary"><img class="bi"  width="24" height="24" src="web/resources/trash.svg"></img></a></td>
                </tr>
            <?php endforeach; ?>
        <?php endif; ?>
    </tbody>
    </table>
<?php $contenido = ob_get_clean();?>
<?php include 'base.php';?>