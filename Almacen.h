#ifndef ALMACEN_H
#define ALMACEN_H
#include "ProductoAlmacen.h"

using namespace std;

class Almacen{
    private:
        ProductoAlmacen productos[20];
        int size;
    public:
        Almacen();
        string getName(int posicion);
        double getPrize(int posicion);
        int getPosicion(string id);
        int getExist(int posicion);
        void setExist(int existencia, int posicion);
        void agregarProducto(ProductoAlmacen producto);
        int revisarAlmacen(string id, int cantidad);
};

#endif