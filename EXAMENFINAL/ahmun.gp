#    2022-05-16
#    ahmun.gp
#    Diego Sarceño (dsarceno68@gmail.com)

#    Gráficas Cohete Ah Mun

#    Codificación del texto: UTF8
#    Compiladores probados: GNUPLOT (Ubuntu 20.04 Linux) 5.2
#    Instrucciones de compilación: no requere nada mas
#    gnuplot ahmun.gp

# PROGRAM
# Idioma
set encoding utf8
# terminal
unset label
clear
set terminal png
set output "./img/Ahmun_th_tv.png"
set grid
set title "Grafica Tiempo-Altura y Tiempo-Velocidad Cohete Ah Mun"
set ytics nomirror # para desligar los 2 ejes y
set y2tics # 2 ejes y
set xlabel "Tiempo"
set ylabel "Altura"
set y2label "Velocidad"
set key left top box


# se plotean los dos conjuntos de datos en una sola grafica, pero con ejes
# y's independientes.
plot "data.dat" u 1:2 axis x1y1 w lp t "Altura", "data.dat" u 1:3 axis x1y2 w lp t "Velocidad"


unset label
clear
set terminal png
set output "./img/Ahmun_hv.png"
set grid
set title "Grafica Altura-Velocidad Cohete Ah Mun"
set xlabel "Altura"
set ylabel "Velocidad"
set key left top box

plot "data.dat" u 2:3 w lp t "y-v"
