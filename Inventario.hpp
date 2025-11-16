#include <iostream>

#pragma once

enum class TipoObjeto {
    Curar,
    SubeStats,
    Llave,
    Otorgar,
};

class Objeto {
    private:
        TipoObjeto tipo;
        std::string nombre;
        std::string uso;
        int cantidad;
    public:
        Objeto(TipoObjeto t, std::string n, std::string u, int c);
        TipoObjeto getTipo() const;
        std::string getNombre() const;
        std::string getUso() const;
        int getCantidad() const;
        void sumarCantidad(int c);
        bool usarObjeto(int c);

};
