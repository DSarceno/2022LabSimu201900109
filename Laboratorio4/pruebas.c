//	vie 22 abr 2022 17:12:18 CST
//	pruebas.c
//	Diego Sarceno (dsarceno68@gmail.com)

//	Resumen

//	Codificado del texto: UTF8
//	Compiladores probados: GNU gcc (Ubuntu 20.04 Linux) 9.3.0
//	Instruciones de Compilacion: no requiere nada mas
//	gcc -Wall -pedantic -std=c11 -c -o pruebas.o pruebas.c
//	gcc -o pruebas.x pruebas.o


//Librerias
#include <stdio.h>
#include <math.h>
/* POR METODO DE COFACTORES
float determinante(float array[][col], int orden){
  float det = 0;

  for (int i = 0; i < orden; i++){
    det += array[0][i]*cofactor(array, orden, 0, i);
  } // END FOR

  return det;
} // END determinante



float cofactor(float array[][col], int orden, int file, int column){
  int nuevo_orden = orden - 1;
  float subarray[nuevo_orden][nuevo_orden];
  int x = 0, y = 0;

  for (int i = 0; i < orden; i++){
    for (int j = 0; j < orden; j++){
      if (i != file && j != column){
        subarray[x][y] = array[i][j];
        y++;
      } // END IF
    } // END FOR
    x++;
  } // END FOR
  // pow(-1, file + column)*
  return pow(-1, file + column)*determinante(subarray, nuevo_orden);
} // END cofactor
*/
