<?php ob_start();?>
        <div class="row">
            <div class="mb-3 text-center mt-5">
                <h2><?=$hilo[0]["titulo"];?></h2><br>
            </div>
            <div class="mb-3 mt-2">
                <p><?=$hilo[0]["descripcion"];?></p>
            </div>
            <div>
                <input type="button" value="Agregar Comentario" name="Agregar Comentario" id="btn"  onclick="mostrarFormulario()" class="btn btn-primary">
            </div>
            <div class="error mt-2">
                        <?=isset($errorComentario)?$errorComentario:''?>
            </div>
        </div>
    <form action="" id="formComentario" class="ocultar" method="post">
    <div class="row mt-4">
        <input type="hidden" name="hilo" value="<?=$hilo[0]['idHilo']?>">
        <div class="mb-3">
            <label for="" class="form-label">Titulo</label>
            <input type="text" class="form-control" name="titulo" id="titulo" value="<?= isset($_POST["titulo"])?$_POST['titulo']:''?>">
            <div class="error mt-2">
                    <?=isset($errores["titulo"])?$errores["titulo"]:''?>
            </div>
        </div>
        <div class="mb-3">
            <label for="" class="form-label">Descripcion</label>
            <textarea class="form-control"  name="descripcion" id="descripcion"  value="<?=isset($_POST["descripcion"])?$_POST['descripcion']:''?>"></textarea>
            <div class="error mt-2">
                    <?=isset($errores["descripcion"])?$errores["descripcion"]:''?>
            </div>
        </div>
       
        <div class="text-center">
            <input type="submit" class="btn btn-primary mb-3 mx-auto w-25" value="Enviar" name="Enviar" class="btn btn-primary">
        </div>
    </div>
    </form>
    <div class="row">
        <?php foreach ($allComentario as $clave => $value):?>

            <div class="col-md-12 col-12">
            
                <img class="bi me-2"  width="24" height="24" src="web/resources/person-circle.svg"></img><?=$value['email'] . '-' . substr($value['fecha'],8,2) . '/' . substr($value["fecha"], 5,2) . '/' . substr($value["fecha"], 0,4) . ' ' . substr($value['fecha'],11,5)?>
                <?php if(isset($_SESSION['usuario']) && $_SESSION['usuario'] == $value["email"]):?>
                    <a href="index.php?ctl=verTema&idComentario=<?=$value['idComentario']?>&idHilo=<?=$value['idHilo']?>" class="ms-auto"><img class="bi"  width="24" height="24" src="web/resources/trash.svg"></img></a>
                <?php endif;?>
            </div>
            <div class="col-md-12 col-12">
                <h5><?=$value['titulo'];?></h5>
                <p><?=$value['descripcion'];?></p>
            </div>

           
            <hr>
        </div>
        <?php endforeach;?>
    </div>
<?php $contenido = ob_get_clean();?>
<?php include 'base.php';?>