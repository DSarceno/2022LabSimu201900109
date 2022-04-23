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
float determinante(float array[][col], int n);
float cofactor(float array[][col], int n, int file, int column);
//
void transpuesta(float array[][col], int m, int n, float result[][col]);

// 1. main
int main(){
  // 2. definiendo las variables a utilizar
  float matA[fila][col], matB[fila][col], result[fila][col];
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
  printf("%f\n", determinante(matA, fila));
  puts("");

  // f)
  transpuesta(matB, fila, col, result);
  puts("f) transpuesta de matB.");
  for (int i = 0; i < fila; i++){ printf("%f,%f,%f\n", result[i][0], result[i][1], result[i][2]); }
  puts("");

  // g)

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


float determinante(float array[][col], int n){
  float det = 0;

  for (int i = 0; i < n; i++){
    det += array[0][i]*cofactor(array, n, 0, i);
  } // END FOR

  return det;
} // END determinante



float cofactor(float array[][col], int n, int file, int column){
  float subarray[n][n];
  int t = n - 1;
  int x = 0, y = 0;

  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (i != file && j != column){
        subarray[x][y] = array[i][j];
        y++;
        if (y >= t){
          x++;
          y = 0;
        } // END IF
      } // END IF
    } // END FOR
  } // END FOR
  // pow(-1, file + column)*
  return determinante(subarray, t);
} // END cofactor


void transpuesta(float array[][col], int m, int n, float result[][col]){
  for (int i = 0; i < m; i++){
    for (int j = 0; j < n; j++){
      result[j][i] = array[i][j];
    } // END FOR
  } // END FOR
} // END transpuesta























// END PROGRAM
