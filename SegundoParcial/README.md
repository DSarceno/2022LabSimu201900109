# Segundo Parcial
Fichero dedicado a los problemas resuleltos del segundo parcial para carné con terminación 9.

## [Problema 1](https://github.com/DSarceno/2022LabSimu201900109/blob/main/SegundoParcial/problema1.c)
#### Enunciado
Se elabora un estudio del comportamiento de los precios del combustible tipo regular, asumiendo que
estos tiene un comportamiento lineal y en base a la tabla de datos:

| Semana | Precio (Q/galon) |
| ------ | ---------------- |
| 1 | 20.20 |
| 2 | 20.90 |
| 3 | 20.60 |
| 4 | 21.30 |
| 5 | 20.75 |
| 6 | 22.05 |
| 7 | 23.62 |
| 8 | 22.95 |
| 9 | 23.80 |
| 10 | 24.00 |

#### Metodología
Dado el conjunto de datos, para realizar un ajuste lineal se pueden realizar dos procedimientos, utilizando **_gnuplot_** o algún método, en este caso, mínimos cuadrados. El ajuste en **_gnuplot_** se realiza mediante la función a la que se desea ajustar y las constantes presentes en dicha función, i.e.
```
# Función sobre la cual se "fitean" los datos
f(x) = a*x + b # en este caso función lineal

# Comando fit para el Ajuste
fit f(x) 'data.dat' using 1:2 via a,b
```
Ahora, utilizando el método de mínimos cuadrados, se encuentra la pendiente y el intercepto de la ecuación lineal.

![mb](./img/mb.png)

Y el coeficiente de correlación.

![r](./img/r.png)

#### Variables y funciones
- `x`: Vector que almacena las coordenadas "x" de los datos.
- `y`: Vector que almacena las coordenadas "y" de los datos.
- `i`: iterador en las funciónes.
- `n`: longitud de los vectores.
- `m`: Pendiente de la recta.
- `b`: Intercepto de la recta.
- `r`: Coeficiente de correlación.
- `suma_prod(vector,vector)`: función que calcula el producto punto entre ambos vectores.
- `suma(vector)`: Función que calcula la suma de todas las coordenadas del vector.


#### Diagrama de Flujo
![problema1](./img/problema1.png)
#### Instrucciones de Complilación y Ejecución
```
$ gcc -Wall -pedantic -std=c11 -c -o problema1.o problema1.c
$ gcc -o problema1.x problema1.o -lm
$ ./problema1.x
```

#### Resultados
|  | m | b | r |
| - | - | - | - |
| Mínimos Cuadrados | 0.445515 | 19.666668 | 0.964707 |
| Ajuste Gnuplot | 0.445515 | 19.6667 | Not given. |

## [Problema 2](https://github.com/DSarceno/2022LabSimu201900109/blob/main/SegundoParcial/problema2.c)
#### Enunciado
#### Metodología
#### Variables
#### Diagrama de Flujo
#### Instrucciones de Complilación y Ejecución
#### Resultados
