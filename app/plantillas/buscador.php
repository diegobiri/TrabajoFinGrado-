<?php ob_start();?>
<div><h3 class="text-center my-3">Buscador</h3></div>
    <form action="" method="post">
        <div class="row">
            <div class="col-lg-4 col-12 text-center ">
                <label for="">Fecha del Concierto</label>
                <input type="date" name="fecha" id="" value="">
            </div>
            <div class="col-lg-4 col-12 text-center ">
                <label for="">Precio</label>
                <input type="number" name="precio" id="" value="">
            </div>
            <div class="col-lg-4 col-12 text-center ">
                <label for="">Busqueda por genero Musical</label>
                <select name="generoMusical" id="">
                    <option value="">Todos</option>
                    <?php foreach($gustosMusicales as $clave => $value):?>
                        <option value="<?=$value["generoMusical"];?>"><?=$value["generoMusical"];?></option>
                    <?php endforeach;?>
                </select>
            </div>
            <div class="my-5 fit-content">
                <input type="submit" value="Buscar" class="btn btn-primary" name="Buscar">
            </div>
        </div>
    </form>
    <?php if(isset($cargarConciertos) && !empty($cargarConciertos)): ?>
        <div class="row">
        <div><h3 class="text-center my-5">Conciertos</h3></div>
        <?php foreach($cargarConciertos as $clave => $value): ?>
          <div class="col-lg-4 col-12 text-center ">
            <div class="card shadow-sm text-center">
            <img class="bd-placeholder-img imgPortada" width="300" height="300" src="./web/imagenes/<?=$imagenes[$value['idConcierto']];?>">
              <div class="card-body">
                <p class="card-text"><?= $value["nombre"];?></p>
                <p class="card-text"><?= $value["lugar"];?></p>
                <p class="card-text"><?= $value["aforo"];?></p>
                <p class="card-text">Fecha del Concierto:<?= substr($value["fecha"],8,2). '-'.substr($value["fecha"],5,2). '-'.substr($value["fecha"],0,4);?></p>
                <p class="card-text">Inicio del Concierto:<?= substr($value["fecha"],11,5);?></p>
                <div class="text-end">
                  <div class="btn-group text-end">
                    <a href="index.php?ctl=infConcierto&concierto=<?=$value["idConcierto"];?>"><button type="button" class="btn btn-sm btn-outline-secondary ">Mas informacion</button></a>
                  </div>
                  
                </div>
              </div>
            </div>
          </div>
        <?php endforeach; ?>
      </div>
    <?php endif; ?>
    <div class="error text-center mt-2">
                    <?=isset($error)?$error:''?>
                </div>
<?php $contenido = ob_get_clean();?>
<?php include 'base.php';?>