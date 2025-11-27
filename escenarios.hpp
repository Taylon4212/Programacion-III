#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Personaje.hpp"
#include "Inventario.hpp"
#pragma once



class Escena{
    private:
        std::string texto;
        std::vector<std::string> Textop;
        std::vector<Escena*> Opciones; 
        Enemigo* enemigo;

        int reqFuerza = 0;
        int reqInteligencia = 0;
        int reqSuerte = 0;

        std::string m_nombreLlaveRequerida = "";
        std::vector<Objeto*> objetosEnEscena;

        sf::Texture fondoes;

    public:
        Escena(const std::string& tex, const std::string& rutafondo);
        ~Escena();
        
        
        bool vivoenemi();
        bool OpVacio();
        Escena* GetEscena(int n);
        Enemigo* GetEnemigo();
        std::string GetTexto();
        std::vector<std::string> GetTextop() const;
        sf::Sprite GetSprite();
        
        void setEnemi(Enemigo* enen);
        void setOpcion(Escena* es, std::string opci);
        void setRequi(int f, int in, int su);
        bool Cumplerequi(Personaje& pj);


        void setLlaveRequerida(const std::string& nombreLlave);
        const std::string& getLlaveRequerida() const;
        bool necesitallave();
        bool tieneobj();
        
        int cantObjetos();
        const std::vector<Objeto*>& getObjetos() const;
        void anadirObjEs(Objeto* obj);
        void removerObjEs(Objeto* obj);
        void Vaciar();
        
};
