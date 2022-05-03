#    2022-04-22
#    combustible.gp
#    Diego Sarceño (dsarceno68@gmail.com)

#    Programa superficies de nivel, sistema tierra luna

#    Codificación del texto: UTF8
#    Compiladores probados: GNUPLOT (Ubuntu 20.04 Linux) 5.2
#    Instrucciones de compilación: no requere nada mas
#    gnuplot combustible.gp

# PROGRAM
# Idioma
set encoding utf8
# terminal
set terminal pdf
set output "./img/combustible.pdf"
set grid
set title "Variación del Precio del Combustible en el Tiempo"
set key left top box


# función a la que se desea ajustar
f(x) = a*x + b
fit f(x) 'data.dat' using 1:2 via a,b
g(x) = 0.445515*x + 19.666668

# ploteando los datos y la funcion fit
set xrange [0:13]
set yrange [19:26]
plot f(x) lc "blue" t "Ajuste Lineal", "data.dat" using 1:2 with points lc "black" t "Datos"
plot g(x) lc "red" t "Ajuste Mínimos Cuadrados", "data.dat" using 1:2 with points lc "black" t "Datos"
