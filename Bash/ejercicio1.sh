#!/bin/bash

: << 'header'
Autor:			Diego SarceÃo
Fecha: 			01-03-2022
Tipo Archivo:		Script Bash
EjecuciÃn:		./ejercicio1.sh
Resumen:		CreaciÃn de archivo con informaciÃn del clima.
header

# InformaciÃn del clima y archivo de almacenaje.
curl -o clima_guatemala.txt wttr.in/Guatemala

# Lectura de las primeras 7 lineas
leer=$(head -n7 clima_guatemala.txt)

# Mostrar lo leÃdo
echo Se muestran las primeras 7 lÃneas del archivo. Se muestran en fila, no en columna.
echo $leer

# Borrado del archivo "clima_guatemala.txt"
rm clima_guatemala.txt
