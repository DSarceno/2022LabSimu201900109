#    2022-04-28
#    raiz.gp
#    Diego Sarceño (dsarceno68@gmail.com)

#    Programa superficies de nivel, sistema tierra luna

#    Codificación del texto: UTF8
#    Compiladores probados: GNUPLOT (Ubuntu 20.04 Linux) 5.2
#    Instrucciones de compilación: no requere nada mas
#    gnuplot raiz.gp

# PROGRAM
# Idioma
set encoding utf8
# terminal
set terminal png
set output "./img/raiz.png"
set grid
set title "Raíz Encontrada"
set key left top box


f(x) = 2 - exp(x) + cos(exp(x) - 2)

set yrange [-5:5]
set xrange [-5:5]

set arrow from -5,0 to 5,0 nohead dt 2 lc -1
plot f(x) lc "blue" t "Función", "point.dat" using 1:2 with points lc "black" t "Raíz"
