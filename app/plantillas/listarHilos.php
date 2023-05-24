<?php ob_start() ?>
    <?php if(sizeof($hilos) == 0):?>
            <p>No hay hilos disponibles</p>
    <?php else:?>
    <table class="table">

        <thead>
            <tr>
                <th scope="col"></th>
                <th scope="col">Titulo</th>
                <th scope="col">Descripcion</th>
                <th scope="col">Ver Tema</th>
            </tr>
        </thead>

        <tbody>
                <?php foreach($hilos as $clave => $value):?>
                    <tr>
                        <th scope="row"><img class="bi"  width="24" height="24" src="web/resources/chat.svg"></img></th>
                        <td><?=$value['titulo'];?></td>
                        <td><?=$value['descripcion'];?></td>
                        <td><a href="index.php?ctl=verTema&idHilo=<?=$value['idHilo']?>" class="nav-link px-2 text-secondary"><img class="bi"  width="24" height="24" src="web/resources/eye.svg"></img></a></td>
                    </tr>
                <?php endforeach; ?>
            <?php endif; ?>
        </tbody>
    </table>
<?php $contenido = ob_get_clean();?>
<?php include 'base.php';?>