<?php
function generarContrasena():string{
        $letra = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'];
        $simbolos = ['?','!','@','/','#','|','€','%'];
        $contraseña = '';
        for ($i=0; $i < 3; $i++) { 
            $generarLetras = rand(0,sizeof($letra));
            $generarSimbolos = rand(0,sizeof($simbolos));
            $generarNumeros = rand(0,9);
            $contraseña .= $letra[$generarLetras];
            $contraseña .= $generarNumeros;
            $contraseña .= $simbolos[$generarSimbolos];
        }
        return $contraseña;
    }
