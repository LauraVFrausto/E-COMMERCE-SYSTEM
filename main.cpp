/*Equipo:
    A01639729-Erik Ernesto Ocegueda Sambrano
    A01641790-Laura Merarí Valdivia Frausto
*/
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "ProductoAlmacen.cpp"
#include "Almacen.cpp"
#include "ProductoCarrito.cpp"
#include "Carrito.cpp"

using namespace std;

void leer(){
    //Leer el archivo producto.txt
    ifstream lector("producto.txt");
    string linea;
    while (!lector.eof()){
        getline(lector,linea);
        cout<<linea<<endl;
        stringstream ss(linea);
    }
    lector.close();
}

int main(){
    ProductoAlmacen p1(0),
                    p2(1),
                    p3(2),
                    p4(3),
                    p5(4),
                    p6(5),
                    p7(6),
                    p8(7),
                    p9(8),
                    p10(9),
                    p11(10),
                    p12(11),
                    p13(12),
                    p14(13),
                    p15(14);
    Almacen prod;
    prod.agregarProducto(p1);
    prod.agregarProducto(p2);
    prod.agregarProducto(p3);
    prod.agregarProducto(p4);
    prod.agregarProducto(p5);
    prod.agregarProducto(p6);
    prod.agregarProducto(p7);
    prod.agregarProducto(p8);
    prod.agregarProducto(p9);
    prod.agregarProducto(p10);
    prod.agregarProducto(p11);
    prod.agregarProducto(p12);
    prod.agregarProducto(p13);
    prod.agregarProducto(p14);
    prod.agregarProducto(p15);

    string cliente;
    cout<<"Nombre: ";
    cin>>cliente;
    Carrito carrito(cliente);
    //Variables para el menú
    int opcion;
    bool seguir=true;
    //Variables para el submenú comprar
    string id, 
           op;
    int cantidad;
    bool ingreso=true;
    //Varibales menú Editar
    string identificador, 
           op_;
    int cantidadNueva;
    bool editar=true;
    do{
        cout<<"1) Ver productos"<<endl<<
        "2) Comprar"<<endl<<
        "3) Ver carrito"<<endl<< 
        "4) Editar"<<endl<< 
        "5) Pagar"<<endl<< 
        "6) Salir "<<endl;
        cout<<"Quiero... ";
        cin>>opcion;
        cout<<"";

        switch (opcion){
            case 1:
                cout<<endl<<"PRODUCTOS"<<endl;
                leer();
                cout<<""<<endl;
                break;

            case 2:
                cout<<endl<<"COMPRAR"<<endl;
                do{
                    cout<<"id: ";
                    cin>>id;
                    cout<<"Cantidad: ";
                    cin>>cantidad;
                    cout<<"Datos correctos (s/n): ";
                    cin>>op;
                    if (op=="s"){
                        int revisarAlmacen=prod.revisarAlmacen(id, cantidad);
                        if (revisarAlmacen>=0){
                            ProductoCarrito producto(id, prod.getName(revisarAlmacen), prod.getPrize(revisarAlmacen), cantidad);  
                            if (carrito.agregarCarrito(producto)==true){
                                cout<<"Agregado con exito"<<endl;
                                ingreso=false;
                            }else{
                                cout<<"Carrito lleno!!!"<<endl;
                                ingreso=false;
                            }
                        }
                        else if(revisarAlmacen<0){
                            cout<<"Dato incorrecto o cantidad no suficiente, intente otra vez"<<endl;
                            ingreso=true;
                        }
                    }
                    else if(op=="n"){
                        ingreso=true;
                    }
                    else{
                        cout<<"Opcion no valida"<<endl;
                        ingreso=true;
                    }
                    
                }while(ingreso);
                cout<<""<<endl;
                break;

            case 3:
                cout<<endl<<"Carrito de compras de "<<cliente<<endl;
                cout<<endl<<"\tid, nombre, precio unitario, cantidad"<<endl;
                carrito.mostrarCarrito();
                cout<<"Total: $"<<carrito.total()<<endl<<endl;
                break;
            
            case 4:
                cout<<endl<<"EDITAR"<<endl;
                do{
                    cout<<"id: ";
                    cin>>identificador;
                    cout<<"Cantidad: ";
                    cin>>cantidadNueva;
                    cout<<"Datos correctos (s/n): ";
                    cin>>op_;
                    int posicion=prod.getPosicion(identificador);
                    if (posicion>=0){
                        if (op_=="s"){
                            int existencia=prod.getExist(posicion)+carrito.getQuantity(identificador);
                            if (carrito.editarCarrito(identificador,cantidadNueva,existencia)){
                                carrito.editarCarrito(identificador,cantidadNueva,existencia);
                                prod.setExist(existencia-cantidadNueva, posicion);
                                editar=false;
                            }
                            else{
                                cout<<"No se encontro el id"<<endl;
                                editar=true;
                            }
                        }
                        else if(op_=="n"){
                            editar=true;
                        }
                    }
                    else{
                        cout<<"Id no encontrado"<<endl;
                        editar=false;
                    }
                        
                    
                }while(editar);
                cout<<""<<endl;
                break;
                
            case 5:
                cout<<endl<<"PAGAR"<<endl;
                cout<<"El total a pagar es de $"<<carrito.total()<<endl;
                carrito.vaciarCarrito();
                break;
            
            case 6:
                if (carrito.total()>0){
                    cout<<endl<<"No compraste nada :(...Saliendo del programa"<<endl;
                    seguir=false;
                }
                else{
                    cout<<endl<<"Saliendo del programa..."<<endl;
                    seguir=false;
                }
                
                break;

            default:
                cout<<endl<<"Opcion no encontrada, intente otra vez"<<endl<<endl;
                break;
        }
    }while(seguir);
}