//	lun 16 may 2022 11:28:19 CST
//	problema2.cpp
//	Diego Sarceno (dsarceno68@gmail.com)

//	Resumen

//	Codificado del texto: UTF8
//	Compiladores probados: GNU g++ (Ubuntu 20.04 Linux) 9.4.0
//	Instruciones de Compilacion: no requiere nada mas
//	g++ -Wall -c -o problema2.o problema2.cpp
//	g++ -o problema2.x problema2.o

//	Librerias
#include <iostream>
using namespace std;

// clase cohete
class Cohete{
public:
  // atributos.
  string name; // nombre del cohete
  double Eo, tsfc, m0, mfo; // caracteristicas del cohete
  float cd, a;
public:
  // Constringuctor
  Cohete(string nombre, double empuje, double consemp, float cforma, float area, double masa, double combustible){
    name = nombre;
    Eo = empuje;
    tsfc = consemp;
    cd = cforma;
    a = area;
    m0 = masa;
    mfo = combustible;
  } // END CONSTRUCTOR

  ~Cohete(){}; // destrictor

  // metodos, impresion de los datos
  void properties();

};
void Cohete::properties(){ // Imprime las propiedades del cohete
    cout << '\n';
    cout << "Propiedades del Cohete " << name << '\n';
    cout << "Empuje: " << Eo << '\n';
    cout << "Consumo específico del empuje: " << tsfc << '\n';
    cout << "Coeficiente de Forma: " << cd << '\n';
    cout << "Sección transversal: " << a <<'\n';
    cout << "Masa: " << m0 <<'\n';
    cout << "Masa Inicial de Combustible: " << mfo << '\n';
    cout << '\n';
} // END properties


// main
int main(){
  // definimos las caracteristicas de cada cohete
  // 1
  Cohete cohete1("Ah Mun", 3E7, 3.248E-4, 61.27, 201.06, 1.1E5, 1.5E6);
  cohete1.properties();

  // 2
  Cohete cohete2("Ah Mun", 2.7E7, 2.248E-4, 61.27, 201.06, 1.1E5, 1.5E6);
  cohete2.properties();

  // 3
  Cohete cohete3("Ah Mun", 2.5E7, 2.248E-4, 70.25, 215.00, 1.8E5, 2.1E6);
  cohete3.properties();
  return 0;
} // END main

















//
