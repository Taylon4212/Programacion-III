//#include <SFML/Graphics>
//#include <SFML/Audio>

#include "Personaje.hpp"
#pragma once



class Escena{
    private:
        std::string texto;
        std::vector<std::string> Textop;
        std::vector<Escena*> Opciones; 
        Enemigo* enemigo;
    public:
        Escena(std::string tex);
        void ImprimirTexto();
        void MostrarOp();
        
        bool vivoenemi();
        Escena* GetEscena(int n);
        Enemigo* GetEnemigo();
        
        void setEnemi(Enemigo* enen);
        void setOpcion(Escena* es, std::string opci);
        

};