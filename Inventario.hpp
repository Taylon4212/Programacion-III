#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#pragma once

class Personaje;

enum class TipoObjeto {
    Curar,
    Llave,
};

class Objeto {
    private:
        TipoObjeto tipo;
        std::string nombre;
        std::string uso;
        int cantidad;
        int efecto;
        std::string m_texturePath;
        sf::Texture textura;
        sf::Sprite sprite;
        

    public:
        Objeto(TipoObjeto t, std::string n, std::string u, int c,int f, const std::string& texturePath_param);
        ~Objeto();
        Objeto(const Objeto& otro);
        TipoObjeto getTipo() const;
        const std::string& getNombre() const;
        const std::string& getUso() const;
        int getCantidad() const;
        void sumarCantidad(int c);
        bool usarObjeto(Personaje& usuario);
        int getEfecto() const;
        sf::Texture& getTexture();
        sf::Sprite& getSprite();
        const std::string& getTexturePath() const;
};
