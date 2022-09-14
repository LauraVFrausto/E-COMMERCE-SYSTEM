#include "ProductoCarrito.h"

ProductoCarrito::ProductoCarrito(){
    this->id="L00";
    this->nombre="Producto no existente";
    this->precio=0.00;
    this->cantidad=0;
}

string ProductoCarrito::getId(){
    return this->id;
}

int ProductoCarrito::getCantidad(){
    return this->cantidad;
}

double ProductoCarrito::getPrix(){
    return this->precio;
}

void ProductoCarrito::setCantidad(int cantidad){
    this->cantidad=cantidad;
}

ProductoCarrito::ProductoCarrito(string id, string nombre, double precio, int cantidad){
    this->id=id;
    this->nombre=nombre;
    this->precio=precio;
    this->cantidad=cantidad;
}

string ProductoCarrito::imprimir(){
    return this->id+","+this->nombre+","+to_string(this->precio)+","+to_string(this->cantidad);
}