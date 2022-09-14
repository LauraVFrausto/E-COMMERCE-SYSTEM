#ifndef PRODUCTOCARRITO_H
#define PRODUCTOCARRITO_H
#include <string>

using namespace std;

class ProductoCarrito{
    private:
        string id,
               nombre;
        double precio;
        int cantidad;
    public:
    ProductoCarrito();
    ProductoCarrito(string id, string nombre, double precio, int cantidad);
    string getId();
    int getCantidad();
    double getPrix();
    void setCantidad(int cantidad);
    string imprimir();
};

#endif