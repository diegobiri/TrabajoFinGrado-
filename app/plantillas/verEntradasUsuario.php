<?php ob_start();?>
    <?php if(sizeof($entradas) == 0):?>
        <p> No hay entradas compradas</p>
        <?php else:?>
    
    <table class="table">

        <thead>
            <tr>
                <th scope="col">Nombre Concierto</th>
                <th scope="col">Fecha</th>
                <th scope="col">Hora</th>
                <th scope="col">Nombre Artista</th>
                <th scope="col">Tipo Entrada</th>
                <th scope="col">Precio</th>
                <th scope="col">Ver entrada</th>
            </tr>
        </thead>

        <tbody>
            
                <?php foreach($entradas as $clave => $value):?>
                    <tr>
                        <td><?=$value['nombreConcierto'];?></td>
                        <td><?=substr($value["fecha"], 8,2) . '-'.substr($value["fecha"], 5,2) . '-' . substr($value["fecha"], 0,4);?></td>
                        <td><?=substr($value["fecha"], 11,5);?></td>
                        <td><?=$value['nombreArtista'];?></td>
                        <td><?=$value['tipoEntrada'];?></td>
                        <td><?=number_format($value['precio'],2);?></td>
                        <td><a href="index.php?ctl=verEntrada&idEntrada=<?=$value['idEntrada']?>" class="nav-link px-2 text-secondary"><img class="bi"  width="24" height="24" src="web/resources/eye.svg"></img></a></td>
                    </tr>
                <?php endforeach; ?>
           
        </tbody>
        </table>
    <?php endif;?>
<?php $contenido = ob_get_clean();?>
<?php include 'base.php';?>