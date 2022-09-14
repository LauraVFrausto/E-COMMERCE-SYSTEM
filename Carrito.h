#ifndef CARRITO_H
#define CARRITO_H
#include <string>
#include "ProductoCarrito.h"

using namespace std;

class Carrito{
    private:
        string cliente;
        ProductoCarrito productos[10];
        int size;
    public:
        Carrito(string cliente);
        int getQuantity(string id);
        bool agregarCarrito(ProductoCarrito producto);
        double total();
        void mostrarCarrito();
        bool editarCarrito(string id, int cantidad, int existencia);
        void vaciarCarrito();
};

#endif