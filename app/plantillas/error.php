<?php ob_start() ?>
<h1><?= $error;?></h1>
<?php $contenido = ob_get_clean() ?> 

<?php include 'base.php' ?>