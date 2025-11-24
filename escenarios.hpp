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

        int reqVida = 0;
        int reqFuerza = 0;
        int reqInteligencia = 0;
        int reqSuerte = 0;

    public:
        Escena(std::string tex);
        ~Escena();
        
        void MostrarOp();
        
        bool vivoenemi();
        bool OpVacio();
        Escena* GetEscena(int n);
        Enemigo* GetEnemigo();
        std::string GetTexto();
        std::vector<std::string> GetTextop() const;
        
        void setEnemi(Enemigo* enen);
        void setOpcion(Escena* es, std::string opci);
        void setRequi(int v, int f, int in, int su);
        bool Cumplerequi(Personaje& pj);
    
};