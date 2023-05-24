<?php
namespace ConciertosProyecto\app\Modelo;

use ConciertosProyecto\app\Modelo\ConciertoException;

class Concierto
{ 
    private string $nombre;
    private \DateTime $fecha;
    private string $lugar;
    private int $aforo;
    private int $idConcierto; 
    private int $idArtista;
    private int $numEntradasNormales;
    private float $precioEntradasNormales;
    private int $numEntradasVip;
    private float $precioEntradasVip;
    private float $latitud;
    private float $longitud;

    public function __construct(array $datosConcierto){
        if(!$this->setNombre(htmlspecialchars(stripslashes(trim($datosConcierto['nombre'])))))
        {
            $errores['nombre'] = 'Nombre Incorrecto';
        }

        if(!$this->setLugar(htmlspecialchars(stripslashes(trim($datosConcierto['lugar'])))))
        {
            $errores['lugar'] = 'Lugar Incorrecto';
        }

        if(!$this->setAforo($datosConcierto['aforo']))
        {
            $errores['aforo'] = 'Aforo Incorrecto';
        }

        if(!$this->setFecha($datosConcierto['fecha']))
        {
            $errores['fecha'] = 'Fecha Incorrecto';
        }

        if(isset($datosConcierto['idConcierto']))
        {
            if(!$this->setCodConcierto($datosConcierto['idConcierto']))
            {
                $errores['idConcierto'] = 'Codigo Incorrecto';
            }
            
        }
        if(!$this->setCodArtista($datosConcierto['idArtista']))
        {
            $errores['idArtista'] = 'Seleccione un artista';
        }

        if(!$this->setNumEntradasNormal($datosConcierto['numEntradasNormales']))
        {
            $errores['numEntradasNormales'] = 'Numero de entradas incorrecto';
        }

        if(!$this->setNumEntradasVip($datosConcierto['numEntradasVip']))
        {
            $errores['numEntradasVip'] = 'Numero de entradas incorrecto';
        }

        if(!$this->setPrecioEntradasNormales($datosConcierto['precioEntradasNormales']))
        {
            $errores['precioEntradasNormales'] = 'Precio Incorrecto';
        }

        if(!$this->setPrecioEntradasVip($datosConcierto['precioEntradasVip']))
        {
            $errores['precioEntradasVip'] = 'Precio Incorrecto';
        }

        if(!$this->setLatitud($datosConcierto['latitud']))
        {
            $errores['errorCordenadas'] = 'Coordenadas Incorrectas';
        }

        if(!$this->setLongitud($datosConcierto['longitud']))
        {
            $errores['errorCordenadas'] = 'Coordenadas Incorrectas';
        }

        

        if(($datosConcierto['numEntradasNormales'] + $datosConcierto['numEntradasVip']) > $datosConcierto['aforo'])
        {
            $errores['numEntradasTotal'] = 'No puedes crear mas entradas que el aforo';
        }

       

        if(isset($errores))
        {
            throw new ConciertoException($errores);
        }
    }

    public function setNombre(string $nombre):bool
    {
        if(empty($nombre))
        {
            return false;
        }else if(strlen($nombre)>30)
        {
            return false;
        }
        $this->nombre=$nombre;
        return true;
    }

    public function setLugar(string $lugar):bool
    {
        $expReg = '/^[A-Z]{1}[a-zñáéíóú]*$/';
        if(empty($lugar))
        {
            return false;
        }else if(!preg_match($expReg,$lugar))
        {
            return false;
        }
        $this->lugar=$lugar;
        return true;
    }

    public function setAforo(int $aforo):bool
    {
        if($aforo <= 0)
        {
            return false;
        }

        $this->aforo=$aforo;
        return true;
    }

    public function setCodConcierto(int $idConcierto):bool
    {
        if($idConcierto <= 0)
        {
            return false;
        }

        $this->idConcierto=$idConcierto;
        return true;
    }

    public function setCodArtista(int $idArtista):bool
    {
        if($idArtista <= 0)
        {
            return false;
        }

        $this->idArtista=$idArtista;
        return true;
    }

    public function setFecha(\DateTime $fecha):bool
    {
        $date1 = new \DateTime("now");
        $date2 = $fecha;
        if($date1>$date2)
        {
            return false;
        }
        $this->fecha=$fecha;
        return true;
    }

    public function setNumEntradasNormal(int $numEntradasNormales):bool
    {
        if($numEntradasNormales < 0)
        {
            return false;
        }

        $this->numEntradasNormales=$numEntradasNormales;
        return true;
    }

    public function setNumEntradasVip(int $numEntradasVip):bool
    {
        if($numEntradasVip < -1)
        {
            return false;
        }

        $this->numEntradasVip=$numEntradasVip;
        return true;
    }

    public function setPrecioEntradasNormales(int $precioEntradasNormales):bool
    {
        if($precioEntradasNormales == 0)
        {
            return false;
        }

        $this->precioEntradasNormales=$precioEntradasNormales;
        return true;
    }

    public function setPrecioEntradasVip(int $precioEntradasVip):bool
    {
        if($precioEntradasVip == 0)
        {
            return false;
        }

        $this->precioEntradasVip=$precioEntradasVip;
        return true;
    }

    public function setLatitud(float $latitud):bool
    {
        if($latitud < -90 || $latitud > 90)
        {
            return false;
        }

        $this->latitud=$latitud;
        return true;
    }

    public function setLongitud(float $longitud):bool
    {
        if($longitud < -180 || $longitud > 180)
        {
            return false;
        }

        $this->longitud=$longitud;
        return true;
    }

    

    //GETTERS

    public function getNombre():string
    {
        return $this->nombre;
    }

    public function getLugar():string
    {
        return $this->lugar;
    }

    public function getAforo():int
    {
        return $this->aforo;
    }

    public function getFecha():\DateTime
    {
        return $this->fecha;
    }
    
    public function getIdConcierto():int
    {
        return $this->idConcierto;
    }

    public function getIdArtista():int
    {
        return $this->idArtista;
    }

    public function getNumEntradasNormales():int
    {
        return $this->numEntradasNormales;
    }

    public function getNumEntradasVip():int
    {
        return $this->numEntradasVip;
    }

    public function getPrecioEntradasNormales():float
    {
        return $this->precioEntradasNormales;
    }

    public function getPrecioEntradasVip():float
    {
        return $this->precioEntradasVip;
    }

    public function getLatitud():float
    {
        return $this->latitud;
    }

    public function getLongitud():float
    {
        return $this->longitud;
    }
   
}


 