//	mié 20 abr 2022 15:52:22 CST
//	problema1.c
//	Diego Sarceno (dsarceno68@gmail.com)

//	Este programa crea y muestra una lista de 10 elementos de números pares
//  y solicita al usuario en que orden desea que se ordene
//  (ascendente/descendente). Para el ordenamiento se utiliza el algoritmo
//  merge-sort.

//	Codificado del texto: UTF8
//	Compiladores probados: GNU gcc (Ubuntu 20.04 Linux) 9.3.0
//	Instruciones de Compilacion: no requiere nada mas
//	gcc -Wall -pedantic -std=c11 -c -o problema1.o problema1.c
//	gcc -o problema1.x problema1.o

//	Librerias
#include <stdio.h>
#include <stdlib.h>

// 0. Prototipado de funciones


// 1. Función main

int main(){
  // 2. Se crea un arreglo de números pares del 2 al 20
  int numeros[10];
  // 2.1. se ingresan los datos en la lista
  for (int i = 0; i < 10; i++){ numeros[i] = 2*i + 2; }

  // 3. Se aleatoriza el arreglo
  int random_position, step;
  for (int k = 0; k < 10; k++){
    // Generamos una posicion random
    random_position = rand() % 10;
    // intercambiar el actual elemento con el de la poiscion aleatoria
    step = numeros[k];
    numeros[k] = numeros[random_position];
    numeros[random_position] = step;
  } // END FOR

  // 4. Interaccion con el usuario y ordenamiento del arreglo
  char input;
  int control = 0;
  while(control == 0){
    puts("Ingrese como desea ver los números.");
    puts("'A' para verlos de forma ascendente.");
    puts("'D' para verlos de forma descendente.");
    scanf("%s",&input);
    printf("%d \n",input);
    if (input == 65){
      control = 1;
      puts("WUUU FORMA ASCENDENTE");
    } else if (input == 68){
      control = 1;
      puts("WUUU FORMA DESCENDENTE");
    } else {
      puts("Ingrese un valor válido.");
    } // END IF
  } // END WHILE


  return 0;
} // END MAIN
