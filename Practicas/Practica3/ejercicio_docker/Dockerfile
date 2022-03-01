FROM ubuntu:lastest
RUN apt-get update
RUN apt-get -y upgrade
RUN apt-get install -y build-essential
RUN apt-get -y git htop man vim
RUN apt clean
WORKDIR /home/ejercicio1
ADD . /home/ejercicio1
COPY . /home/ejercicio1/
CMD ["bash"]