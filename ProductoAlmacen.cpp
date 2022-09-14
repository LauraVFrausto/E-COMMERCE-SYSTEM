#include "ProductoAlmacen.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

ProductoAlmacen::ProductoAlmacen(){
    this->id="L00";
    this->nombre="Producto no existente";
    this->precio=0.00;
    this->existencia=0;
}

ProductoAlmacen::ProductoAlmacen(int noProducto){
    string miProducto[4];
    
    ifstream lector("producto.txt");
    string linea,
           campo;
    for (int i=0;i<15;i++){
        getline(lector,linea);
        stringstream ss(linea);
        if (i==noProducto){
            for(int j=0;j<4;j++){
                getline(ss,campo,',');
                miProducto[j]=campo;
            }
        }
    }
    lector.close();
    this->id=miProducto[0];
    this->nombre=miProducto[1];
    this->precio=stod(miProducto[2]);
    this->existencia=stoi(miProducto[3]);
}

string ProductoAlmacen::getId(){
    return this->id;
}

string ProductoAlmacen::getNombre(){
     return this->nombre;
}

double ProductoAlmacen::getPrecio(){
    return this->precio;
}

int ProductoAlmacen::getExistencia(){
    return this->existencia;
}

void ProductoAlmacen::setExistencia(int cantidad){
    this->existencia=cantidad;
}