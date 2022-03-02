#!/bin/bash

: << 'header'
Autor:			Diego Sarce�o
Fecha: 			01-03-2022
Tipo Archivo:		Script Bash
Ejecuci�n:		./ejercicio1.sh
Resumen:		Creaci�n de archivo con informaci�n del clima.
header

# Informaci�n del clima y archivo de almacenaje.
curl -o clima_guatemala.txt wttr.in/Guatemala

# Lectura de las primeras 7 lineas
leer=$(head -n7 clima_guatemala.txt)

# Mostrar lo le�do
echo Se muestran las primeras 7 l�neas del archivo. Se muestran en fila, no en columna.
echo $leer

# Borrado del archivo "clima_guatemala.txt"
rm clima_guatemala.txt
