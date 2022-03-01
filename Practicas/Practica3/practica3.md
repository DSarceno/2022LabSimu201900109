# Práctica 3

## Docker
Comprobamos que docker esta bien instalado y corre bien, utilizando el "Hello World"

[![asciicast](https://asciinema.org/a/470883.svg)](https://asciinema.org/a/470883)

### Dockerfile
En el Dockerfile creado con los comandos dados

![dockerfile](img/dockerfile.png)

en el cual, cada línea de código, realiza lo siguiente
  - `FROM ubuntu:lastest`: Utiliza la última versión de ubuntu para la Imagen.
  - `RUN apt-get update`: Actualiza la lista de paquetes disponibles para Ubuntu.
  - `RUN apt-get -y upgrade`: Acualiza los paquetes nombrados en la lista (La instrucción `-y` le dice al sistema que se acepte todos los _prompts_, un _yes_ automático).
  - `RUN apt-get install -y build-essential`: Instala todos los paquetes necesarios para poder compilar _C_ en el sistema.
  - `RUN apt-get -y git htop man vim`: Instala la herramienta _htop_, la cual nos permite ver el uso de los recursos vitales del sistema. Además, instala _git_, _man_ (manuales de los comandos) y _vim_.
  - `RUN apt clean`: Este comando ayuda a limpiar el cache luego de una instalación, remueve los archivos y ficheros que dejaron de ser útiles para el sistema.
  - `WORKDIR /home/ejercicio1`: Define el directorio de trabajo (_working directory_) de un _Docker Container_.
  - `ADD . /home/ejercicio1`: Copia directorios y archivos en una imagen de Docker.
  - `COPY . /home/ejercicio1/`: Únicamente copia/duplica archivos y/o directorios.
  - `CMD ["bash"]`: Corre _bash_ en __CMD__.

Ya con esto dicho, creamos la imagen con el nombre __ejdocker__ desde la terminal de _vscode_.
```
$ docker build -t ejdocker:lastest .
```
