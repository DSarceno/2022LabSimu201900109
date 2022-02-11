# Práctica 1

## Descarga e Instalación de la Máquina Virtual
Se inició la práctica descargando e instalando Debian como MV, dado que mi idea era realizar pequeñas grabaciones de la terminal mostrando el uso de cada uno de los comandos utilizando _asciinema_, se tuvo problemas al intentar ejecutar dicha instrucción. Con lo que, mejor descargue Ubuntu 20.04, y realizar todas las grabaciones y pruebas desde ahí, esto porque dado que mi sistema operativo es el mismo, era más familiar y sencillo instalarlo como MV y utilizarlo.

<center>
  <figure>
    <img src="img/Sistema.png" alt="my alt text"/>
    <figcaption>Se utilizaron 3GB de memoria RAM ya que cubre perfectamente la ejecución del entorno de GNOME; asímismo, para el espacio de disco, se destinaron únicamente 15GB, para no desperdiciar espacio.</figcaption>
  </figure>  
</center>
<br></br>

Dicho esto, se procede a mostrar el uso de los comandos en terminal.


## Comandos en terminal
### Atajos de Teclado
Eliminación de Carácteres (el clásico _BackSpace_), Palabras (_Ctrl+w_) y Línea (_Ctrl+u_). Utilizando la terminal tengo cierta experiencia, pero el hecho de que existan atajos de teclado (como en cualquier otra aplicación) es muy interesante y útil. También es importante saber que los atajos de copiado y pegado son distintos, en concreto: Copiar -> Ctrl + Shift + C y Pegar -> Ctrl + Shift + V.

[![asciicast](https://asciinema.org/a/467704.svg)](https://asciinema.org/a/467704)

### Ayuda en la Terminal
De las formas de pedir ayuda, me gusta más la forma de desplegarse de _man_, la siento más intuitiva y simple. Tanto _--help_ como _info_ las considero como 2das opciones.

[![asciicast](https://asciinema.org/a/467706.svg)](https://asciinema.org/a/467706)

### Instrucciones Básicas
Las instrucciones básicas, son sumamente necesarias, no importa en que sistema operativo se esté trabajando; personalmente, entre dichas instrucciones incluiría la navegación entre ficheros, pero esto es un tema posterior. En específico, hay que tomar en cuenta que el cambio de contraseña debe cumplir con los requerimientos tradicionales (longitud y no puede ser igual a la contraseña antigua).

[![asciicast](https://asciinema.org/a/467708.svg)](https://asciinema.org/a/467708)

###  Instrucciones de Manejo de Directorios y Archivos
#### Navegación por Directorios
Los comandos <code>cd</code> y <code>ls</code> son de los comandos más utilizados y más útiles en la terminal. El comando <code>pwd</code>, es algo más situacional, en casos cuando necesitas realizar una copia de un archivo/directorio en algún otro directorio, utilizar ese comando para obtener la ruta completa es bastante útil. (Realizaré más pruebas con <code>ls</code> más adelante)

[![asciicast](https://asciinema.org/a/468405.svg)](https://asciinema.org/a/468405)

#### Manejo de Directorios
El manejo de directorios desde la terminal parece no muy útil, puesto que generalmente se tiene la interfaz gráfica del directorio. Sin embargo, al estar trabajando desde terminal aveces es mucho más rápido el crear o renombrar un archivo desde ahí. La creación es bastante clara (<code>mkdir</code>), mientras que la elimnación de un directorio tiene dos formas <code>rmdir</code> para directorios vacíos y <code>rm -rf</code> para forzar el borrado. (No se probó la instrucción <code>rm</code> porque se me olvidó xd, pero es simplemente para eliminar archivos y/o directorios.). La instrucción <code>mv</code> funciona tanto para mover algo a otro directorio, como para renombrar.

[![asciicast](https://asciinema.org/a/468407.svg)](https://asciinema.org/a/468407)

#### Manejo de Archivos
Luego de la navegación por la terminal, los comandos más útiles son los de manejo de archivos. Creación con <code>touch</code>, visualización simple con <code>less</code> y <code>cat</code> (<code>more</code>), o visualización personalizada con <code>head</code> y <code>tail</code> con las cuales se puede escoger el número de líneas a visualizar (-n <número de líneas>). Además se tiene el comando <code>file</code> al cual no le he encontrado una gran utilidad hasta ahora.

[![asciicast](https://asciinema.org/a/468410.svg)](https://asciinema.org/a/468410)

#### Comandos Extras
