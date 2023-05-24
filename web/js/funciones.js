function mostrarFormulario(){
    var formulario = document.getElementById("formComentario");
    var btn = document.getElementById("btn");
    if(formulario.classList.contains("mostrar"))
    {   
        btn.value = "Agregar Comentario";
        formulario.classList.remove("mostrar");
        formulario.classList.add("ocultar");
    }else{
        btn.value = "Ocultar Comentario";
        formulario.classList.remove("ocultar");
        formulario.classList.add("mostrar");
    }

}

