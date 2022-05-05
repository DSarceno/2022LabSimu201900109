//	jue 21 abr 2022 18:28:43 CST
//	problema4.c
//	Diego Sarceno (dsarceno68@gmail.com)

//	Resumen

//	Codificado del texto: UTF8
//	Compiladores probados: GNU gcc (Ubuntu 20.04 Linux) 9.3.0
//	Instruciones de Compilacion: no requiere nada mas
//	gcc -Wall -pedantic -std=c11 -c -o problema4.o problema4.c
//	gcc -o problema4.x problema4.o -lm

//	Librerias
#include <stdio.h>
#include <math.h>

// 0. prototipado de funciones (m filas y n columnas)
#define fila 3
#define col 3
void prod_escalar(float array[][col], int m, int n, float result[][col], float c);
void suma(float array1[][col], float array2[][col], int m, int n, float result[][col]);
void resta(float array1[][col], float array2[][col], int m, int n, float result[][col]);
void prod_matrices(float array1[][col], float array2[][col], int m, int n, float result[][col]);
//
float determinante(float array[][col]);
//float cofactor(float array[][col], int n, int file, int column);
//
void transpuesta(float array[][col], int m, int n, float result[][col]);
void mCofactores(float array[][col], float result[][col]);

// 1. main
int main(){
  // 2. definiendo las variables a utilizar
  float matA[fila][col], matB[fila][col], result[fila][col], aux[fila][col];
  float c;

  // 3. ingreso de las matrices y la constante
  puts("Ingrese la primera matriz por filas en el siguiente formato: x,y,z");
  for (int i = 0; i < fila; i++){ scanf("%f,%f,%f", &matA[i][0], &matA[i][1], &matA[i][2]); }
  puts("Ingrese la primera matriz por filas en el siguiente formato: x,y,z");
  for (int j = 0; j < fila; j++){ scanf("%f,%f,%f", &matB[j][0], &matB[j][1], &matB[j][2]); }
  puts("Ingrese el valor de la constante.");
  scanf("%f",&c);
  puts("");
  // 4. calculo de los respectvos incisos
  // a)
  prod_escalar(matA, fila, col, result, c);
  puts("a) Matriz por una constante.");
  for (int i = 0; i < fila; i++){ printf("%f,%f,%f\n", result[i][0], result[i][1], result[i][2]); }
  puts("");

  // b)
  suma(matA, matB, fila, col, result);
  puts("b) matA + matB.");
  for (int i = 0; i < fila; i++){ printf("%f,%f,%f\n", result[i][0], result[i][1], result[i][2]); }
  puts("");

  // c)
  resta(matA, matB, fila, col, result);
  puts("c) matA - matB.");
  for (int i = 0; i < fila; i++){ printf("%f,%f,%f\n", result[i][0], result[i][1], result[i][2]); }
  puts("");

  // d)
  prod_matrices(matA, matB, fila, col, result);
  puts("d) matA * matB.");
  for (int i = 0; i < fila; i++){ printf("%f,%f,%f\n", result[i][0], result[i][1], result[i][2]); }
  puts("");

  // e)
  puts("e) det(matA).");
  printf("%f\n", determinante(matA));
  puts("");

  // f)
  transpuesta(matB, fila, col, result);
  puts("f) transpuesta de matB.");
  for (int i = 0; i < fila; i++){ printf("%f,%f,%f\n", result[i][0], result[i][1], result[i][2]); }
  puts("");

  // g)
  mCofactores(matA, result);
  transpuesta(result, fila, col, aux);
  prod_escalar(aux, fila, col, result, 1/determinante(matA));
  puts("g) inversa de matA.");
  for (int i = 0; i < fila; i++){ printf("%f,%f,%f\n", result[i][0], result[i][1], result[i][2]); }
  puts("");

  // h)

  // i)



  return 0;
} // END MAIN


/*
                            FUNCIONES
*/


void prod_escalar(float array[][col], int m, int n, float result[][col], float c){
  for (int i = 0; i < m; i++){
    for (int j = 0; j < n; j++){
      result[i][j] = c*array[i][j];
    } // END FOR
  } // END FOR
} // END prod_escalar


void suma(float array1[][col], float array2[][col], int m, int n, float result[][col]){
  for (int i = 0; i < m; i++){
    for (int j = 0; j < n; j++){
      result[i][j] = array1[i][j] + array2[i][j];
    } // END FOR
  } // END FOR
} // END suma


void resta(float array1[][col], float array2[][col], int m, int n, float result[][col]){
  for (int i = 0; i < m; i++){
    for (int j = 0; j < n; j++){
      result[i][j] = array1[i][j] - array2[i][j];
    } // END FOR
  } // END FOR
} // END suma


void prod_matrices(float array1[][col], float array2[][col], int m, int n, float result[][col]){
  for (int i = 0; i < m; i++){
    for (int j = 0; j < n; j++){
      result[i][j] = 0;
    } // END FOR
  } // END FOR

  for (int i = 0; i < m; i++){
    for (int j = 0; j < n; j++){
      for (int k = 0; k < n; k++){
        result[i][j] += array1[i][k] * array2[k][j];
      } // END FOR
    } // END FOR
  } // END FOR
} // END prod_matrices

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

// REGLA DE SARRUS
float determinante(float array[][col]){
  float det = 0;
  det = (array[0][0]*array[1][1]*array[2][2] + array[0][1]*array[1][2]*array[2][0] +
    array[0][2]*array[1][0]*array[2][1]) - (array[2][0]*array[1][1]*array[0][2]
      + array[2][1]*array[1][2]*array[0][0] + array[2][2]*array[0][1]*array[1][0]);
  return det;
} // END determinante


void transpuesta(float array[][col], int m, int n, float result[][col]){
  for (int i = 0; i < m; i++){
    for (int j = 0; j < n; j++){
      result[j][i] = array[i][j];
    } // END FOR
  } // END FOR
} // END transpuesta


void mCofactores(float array[][col], float result[][col]){
  // manualmente
  result[0][0] = array[1][1]*array[2][2] - array[1][2]*array[2][1];
  result[0][1] = -(array[1][0]*array[2][2] - array[1][2]*array[2][0]);
  result[0][2] = array[1][0]*array[2][1] - array[1][1]*array[2][0];
  result[1][0] = -(array[0][1]*array[2][2] - array[0][2]*array[2][1]);
  result[1][1] = array[0][0]*array[2][2] - array[0][2]*array[2][0];
  result[1][2] = -(array[0][0]*array[2][1] - array[0][1]*array[2][0]);
  result[2][0] = array[0][1]*array[1][2] - array[0][2]*array[1][1];
  result[2][1] = -(array[0][0]*array[1][2] - array[0][2]*array[1][0]);
  result[2][2] = array[0][0]*array[1][1] - array[0][1]*array[1][0];
} // END inversa




















// END PROGRAM
