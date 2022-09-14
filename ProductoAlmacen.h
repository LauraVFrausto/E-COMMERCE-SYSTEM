#ifndef PRODUCTOALMACEN_H
#define PRODUCTOALMACEN_H
#include <string>

using namespace std;

class ProductoAlmacen{
    private:
        string id,
               nombre;
        double precio;
        int existencia;

    public:
        ProductoAlmacen(int noProducto);
        ProductoAlmacen();
        string getId();
        string getNombre();
        double getPrecio();
        int getExistencia();
        void setExistencia(int cantidad);
};

#endif