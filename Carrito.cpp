#include <iostream>
#include "Carrito.h"

Carrito::Carrito(string cliente){
    this->cliente=cliente;
    this->size=0;
}

int Carrito::getQuantity(string id){
    for (int i=0; i < this->size; i++){
        if (this->productos[i].getId() == id){
            return this->productos[i].getCantidad();
        }
    }
    return -1;
}

bool Carrito::agregarCarrito(ProductoCarrito producto){ 
    int cantidad=0;
    if(this->size<10){
        this->productos[this->size]=producto;
        for (int i=0; i<this->size; i++){
            if (this->productos[i].getId() == producto.getId()){
                cantidad=this->productos[i].getCantidad() + producto.getCantidad();
                this->productos[i].setCantidad(cantidad);
                this->size--;
            } 
        } 
        this->size++;
        return true;
    }
    return false;
}

double Carrito::total(){
    double total=0;
    for(int i=0; i<this->size; i++){
        total+=this->productos[i].getPrix()*this->productos[i].getCantidad();
    }
    return total;
}

void Carrito::mostrarCarrito(){
    for (int i=0; i < this->size; i++){
        cout<<"\t"<<this->productos[i].imprimir()<<endl;
    }
}

bool Carrito::editarCarrito(string id, int cantidad, int existencia){
    for (int i=0; i < this->size; i++){
        if (this->productos[i].getId() == id){
            if(cantidad>0 && cantidad<=existencia){
                this->productos[i].setCantidad(cantidad);
            }
            else if(cantidad==0){
                for(int j=i; j<this->size; j++){
                    if(j==9){
                        this->productos[j]=ProductoCarrito("L00","Producto no existente",0.00,0);
                    }else{
                        this->productos[j]=this->productos[j+1];
                    }
                }
                this->size--;
            }
            return true;
        }
    }
    return false;
}

void Carrito::vaciarCarrito(){
    for (int i=0; i < this->size; i++){
        this->productos[i]=ProductoCarrito("L00","Producto no existente",0.00,0);   
    }
    this->size=0;
}