#!/bin/bash

: << 'header'
Autor:			Diego SarceÃo
Fecha:			01-03-2022
Tipo Archivo:		Script Bash
EjecuciÃn:		./ejercicio2.sh
Resumen:		Archivo que automatiza la creaciÃn de archivos para programar en "c".
header

# Solicitud del nombre del archivo .c
echo Ingrese el nombre del archiv sin extencion
read name

# escritura del header del archivo
fecha=$(date)
echo -e "/* \nAutor:		Diego Sarceno \nCompilador:	GNU gcc (Ubuntu 20.04 Linux) 9.3.0 \nCompilado:	gcc -Wall -pedantic -std=c11 -c -o $name.o $name.c \n		gcc -o $name.x $name.o \nFecha: 	$fecha \nLibrerias: 	stdio, (otras) \nResumen:	(ingrese) \nEntrada: 	(ingrese) \nSalida: 	(Ingrese) \n*/ \n\n// Librerias \n#include <stdio.h>" > $name.c


