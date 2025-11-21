#include <iostream>
#include "Personaje.hpp"
#include "History.hpp"
#include "escenarios.hpp"
#pragma once


class Juego{
    private:
        bool Pelear(Personaje& pj, Enemigo& enem);
        
    public:
        void Iniciar(Personaje& pj, Historia& h);
};