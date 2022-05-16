//	lun 16 may 2022 07:55:08 CST
//	problema1.c
//	Diego Sarceno (dsarceno68@gmail.com)

//	Simulación de diversos cohetes.

//	Codificado del texto: UTF8
//	Compiladores probados: GNU gcc (Ubuntu 20.04 Linux) 9.3.0
//	Instruciones de Compilacion: no requiere nada mas
//	gcc -Wall -pedantic -std=c11 -c -o problema1.o problema1.c
//	gcc -o problema1.x problema1.o -lm

//	Librerias
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// 0.1. Definicion de constantes generales
#define G 6.693E-11
#define Rt 6.378E6
#define Mt 5.9736E24
#define R 287.06 // constante del gas ideal
#define L 6.5E-3 // constante termica de la atm
#define g 9.81
#define To 288.15
#define Po 101325

// 0.2. Prototipado de funciones
float masa_cohete(float m0, float tsfc, float Eo, float mfo, float t);
float masa_f(float tsfc, float Eo, float mfo, float t);
float gravedad(float y);
float fuerza_a(float y, float cd, float a, float v);
float densidad(float y);
float empuje(float mf, float Eo);
float ed(float y, float v, float t, float m0, float tsfc, float Eo, float mfo, float cd, float a); // funcion de la ecuacion diferencial
void euler(float h, float m0, float tsfc, float Eo, float mfo, float cd, float a, float *tc, float *tf, float *hm);



// 1. main
int main(){
  /*
    Se hara una declaración de las mismas variables para cada cohete.
  */

  // 2. declaracion de variables
  float Eo, tsfc, cd, a, m0, mfo, tc, tf, hm;

  /*
        AH MUN
  */
  // 3. constantes
  Eo = 3E7;
  tsfc = 3.248E-4;
  cd = 61.27;
  a = 201.06;
  m0 = 1.1E5;
  mfo = 1.5E6;

  // valuamos el metodo de euler
  euler(0.1, m0, tsfc, Eo, mfo, cd, a, &tc, &tf, &hm);

  // impresion de los datos solicitados

  puts("Cohete Ah Mun");
  printf("Empuje: %f\nTSFC: %.6f\nCD: %f\nSeccion Transversal: %f\nMasa del Propulsor: %f\nMasa inicial del Combulstible: %f\n", Eo, tsfc, cd, a, m0, mfo);
  printf("La altura maxima alcanzada es h_max = %f m\n", hm);
  printf("El combustible se agota en t = %f min\n", tc/60);
  printf("El cohete cae al suelo en t = %f min\n", tf/60);

  // generamos las graficas
  system("gnuplot ahmun.gp");


  /*
        AHAU KIN
  */
  // 3. constantes
  Eo = 2.7E7;
  tsfc = 2.248E-4;
  cd = 61.27;
  a = 201.06;
  m0 = 1.1E5;
  mfo = 1.5E6;

  // valuamos el metodo de euler
  euler(0.1, m0, tsfc, Eo, mfo, cd, a, &tc, &tf, &hm);

  // impresion de los datos solicitados
  puts("");
  puts("Cohete Ahau Kin");
  printf("Empuje: %f\nTSFC: %.6f\nCD: %f\nSeccion Transversal: %f\nMasa del Propulsor: %f\nMasa inicial del Combulstible: %f\n", Eo, tsfc, cd, a, m0, mfo);
  printf("La altura maxima alcanzada es h_max = %f m\n", hm);
  printf("El combustible se agota en t = %f min\n", tc/60);
  printf("El cohete cae al suelo en t = %f min\n", tf/60);

  // generamos las graficas
  system("gnuplot ahaukin.gp");




  /*
        CHAC
  */
  // 3. constantes
  Eo = 2.5E7;
  tsfc = 2.248E-4;
  cd = 70.25;
  a = 215.00;
  m0 = 1.8E5;
  mfo = 2.1E6;

  // valuamos el metodo de euler
  euler(0.1, m0, tsfc, Eo, mfo, cd, a, &tc, &tf, &hm);

  // impresion de los datos solicitados

  puts("");
  puts("Cohete Chac");
  printf("Empuje: %f\nTSFC: %.6f\nCD: %f\nSeccion Transversal: %f\nMasa del Propulsor: %f\nMasa inicial del Combulstible: %f\n", Eo, tsfc, cd, a, m0, mfo);
  printf("La altura maxima alcanzada es h_max = %f m\n", hm);
  printf("El combustible se agota en t = %f min\n", tc/60);
  printf("El cohete cae al suelo en t = %f min\n", tf/60);

  // generamos las graficas
  system("gnuplot chac.gp");

  return 0;
} // END main





/*
                          FUNCIONES
*/


// MASA COHETE
float masa_cohete(float m0, float tsfc, float Eo, float mfo, float t){
  float res;
  if (round(masa_f(tsfc, Eo, mfo, t)) == 0){
    return m0;
  } else{
    res = m0 + masa_f(tsfc, Eo, mfo, t);  // Incluye la variación de la masa del combustible
    return res;
  } // END IF
} // END masa_cohete


// MASA COMBISTIBLE
float masa_f(float tsfc, float Eo, float mfo, float t){
  float res;
  res = -(tsfc*Eo*t) + mfo;
  return res;
} // END masa_f


// GRAVEDAD
float gravedad(float y){
  float res;
  res = (G*Mt)/pow(Rt + y,2);
  return res;
} // END gravedad


// FUERZA A
float fuerza_a(float y, float cd, float a, float v){
  float res;
  res = 0.5*densidad(y)*cd*a*v*abs(v);
  return res;
} // END fuerza_a


// DENSIDAD
float densidad(float y){
  float res;
  if (y < To/L){
    res = (Po/(R*To))*pow(1 - (L*y)/To, g/(R*L));
    return res;
  } else{
    return 0;
  } // END IF
} // END densidad


// EMPUJE
float empuje(float mf, float Eo){
  if (round(mf) == 0){
    return 0;
  } else{
    return Eo;
  } // END IF
} // END empuje


// ECUACION DIFERENCIAL
float ed(float y, float v, float t, float m0, float tsfc, float Eo, float mfo, float cd, float a){
  // d2y/dt2 = ed(...)
  float res;
  res = (empuje(masa_f(tsfc, Eo, mfo, t), Eo) - fuerza_a(y, cd, a, v) - (masa_cohete(m0, tsfc, Eo, mfo, t)*gravedad(y)) )/masa_cohete(m0, tsfc, Eo, mfo, t);
  return res;
} // END ed

// RUNGE KUTTA
void euler(float h, float m0, float tsfc, float Eo, float mfo, float cd, float a, float *tc, float *tf, float *hm){
  // condiciones iniciales
  float y = 0.09, v = 0, t = 0; // altura inicial 201900109 -> 0.09m

  // mismo archivo para todos los cohetes, pero se formatea en cada ejecucion de esta funcion
  FILE* f;
  if ((f= fopen("data.dat","wt"))==NULL){
        puts("Error de escritura");
  } // END IF
  // iteraciones
  while (y > 0.01){
    fprintf(f,"%.2f\t%.2f\t%.2f\n",t,y,v);

    // paso
    t += h;
    // calculamos la Velocidad
    v = ed(y, v, t, m0, tsfc, Eo, mfo, cd, a)*t;
    // calculamos la altura
    y = v*t + 0.5*ed(y, v, t, m0, tsfc, Eo, mfo, cd, a)*pow(t,2);

    if (round(masa_f(tsfc, Eo, mfo, t)) == 0){
      *tc = t;
    } else if(round(v) == 0){
      *hm = y;
    } // END IF
  }
  fclose(f);
  *tf = t;
} // END rungeKutta






//
