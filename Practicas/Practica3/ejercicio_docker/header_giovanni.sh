#!/bin/bash

: << 'header'
Autor:			Diego Sarceï¿½o
Fecha:			01-03-2022
Tipo Archivo:		Script Bash
EjecuciÃ³n:		./ejercicio2.sh
Resumen:		Archivo que automatiza la creaciï¿½n de archivos para programar en "c".
header

# Solicitud del nombre del archivo .c
echo Ingrese el nombre del archivo sin extencion
read name

# CreaciÃn del header
fecha=$(date)
echo -e "//	$fecha \n//	$name.c \n//	Diego Sarceno (dsarceno68@gmail.com) \n\n//	Resumen \n\n//	Codificado del texto: UTF8 \n//	Compiladores probados: GNU gcc (Ubuntu 20.04 Linux) 9.3.0 \n//	Instruciones de Compilacion: no requiere nada mas \n//	gcc -Wall -pedantic -std=c11 -c -o $name.o $name.c \n//	gcc -o $name.x $name.o \n\n//	Librerias \n//	#include <stdio.h>" > $name.c
