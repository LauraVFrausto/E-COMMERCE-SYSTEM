#include "Almacen.h"
#include <iostream>

using namespace std;

Almacen::Almacen(){
    this->size=0;
}

string Almacen::getName(int posicion){
    return productos[posicion].getNombre();
}

double Almacen::getPrize(int posicion){
    return productos[posicion].getPrecio();
}

int Almacen::getPosicion(string id){
    for (int i=0; i<this->size; i++){
        if (this->productos[i].getId() == id){
                return i;
        }
    }
    return -1;
}

int Almacen::getExist(int posicion){
    return this->productos[posicion].getExistencia();
}

void Almacen::setExist(int existencia, int posicion){
    this->productos[posicion].setExistencia(existencia);
}

void Almacen::agregarProducto(ProductoAlmacen producto){
    this->productos[this->size]=producto;
    this->size+=1;
}

int Almacen::revisarAlmacen(string id, int cantidad){
    for (int i=0; i<this->size; i++){
        if (this->productos[i].getId() == id){
            if (this->productos[i].getExistencia() >= cantidad){
                int cant=this->productos[i].getExistencia()-cantidad;
                this->productos[i].setExistencia(cant);
                return i;
            }
        }
    }
    return -1;
}