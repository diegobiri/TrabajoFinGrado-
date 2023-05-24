-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Servidor: 127.0.0.1
-- Tiempo de generación: 24-05-2023 a las 17:55:00
-- Versión del servidor: 10.4.21-MariaDB
-- Versión de PHP: 8.0.10

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de datos: `conciertoslarioja`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `conciertos`
--

CREATE TABLE `conciertos` (
  `idConcierto` int(11) NOT NULL,
  `nombre` varchar(255) NOT NULL,
  `fecha` datetime NOT NULL,
  `lugar` varchar(255) NOT NULL,
  `aforo` int(11) NOT NULL,
  `idArtista` int(11) NOT NULL,
  `numEntradasNormales` int(11) NOT NULL,
  `precioEntradasNormales` int(11) NOT NULL,
  `numEntradasVip` int(11) NOT NULL,
  `precioEntradasVip` int(11) NOT NULL,
  `latitud` float DEFAULT NULL,
  `longitud` float DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Volcado de datos para la tabla `conciertos`
--

INSERT INTO `conciertos` (`idConcierto`, `nombre`, `fecha`, `lugar`, `aforo`, `idArtista`, `numEntradasNormales`, `precioEntradasNormales`, `numEntradasVip`, `precioEntradasVip`, `latitud`, `longitud`) VALUES
(12, 'Lordi', '2023-06-21 13:37:00', 'Logroño', 300, 13, 194, 50, 97, 100, 42.4184, -2.4472),
(13, 'Bob Dylan', '2023-06-21 21:30:00', 'Logroño', 500, 14, 300, 70, 200, 100, 42.4351, -2.44165),
(14, 'Marea', '2023-09-09 22:00:00', 'Logroño', 500, 15, 300, 70, 200, 100, 42.4452, -2.41968),
(15, 'Morat', '2023-06-25 22:30:00', 'Alfaro', 400, 16, 345, 20, 50, 50, 42.1588, -1.74932),
(16, 'Diego Ramírez', '2023-07-20 20:30:00', 'Haro', 200, 17, 190, 10, 10, 50, 42.5526, -2.84277),
(17, 'Dimitri Vegas', '2023-06-23 00:00:00', 'Logroño', 500, 18, 450, 50, 50, 100, 42.4392, -2.44165);

--
-- Índices para tablas volcadas
--

--
-- Indices de la tabla `conciertos`
--
ALTER TABLE `conciertos`
  ADD PRIMARY KEY (`idConcierto`),
  ADD KEY `idArtista` (`idArtista`);

--
-- AUTO_INCREMENT de las tablas volcadas
--

--
-- AUTO_INCREMENT de la tabla `conciertos`
--
ALTER TABLE `conciertos`
  MODIFY `idConcierto` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=18;

--
-- Restricciones para tablas volcadas
--

--
-- Filtros para la tabla `conciertos`
--
ALTER TABLE `conciertos`
  ADD CONSTRAINT `conciertos_ibfk_1` FOREIGN KEY (`idArtista`) REFERENCES `artista` (`idArtista`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
