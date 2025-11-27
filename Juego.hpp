#include <iostream>
#include "Personaje.hpp"
#include "History.hpp"
#include "escenarios.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#pragma once


class Juego{
    private:
        sf::RenderWindow& window;
        sf::Texture fondo;
        sf::Font font;           
        sf::Text textoVisible;   
        sf::Clock clock;         
        sf::Text textoAtributos;
        sf::Text textoVida;
        sf::Text Continuar;
        sf::FloatRect BoxContinuar;
        std::vector<sf::Text> opcionesTextoSFML;
        std::vector<sf::FloatRect> BoxOpciones;
        std::vector<sf::Text> TextObjetos;
        std::vector<sf::Sprite> ObjetosPerso;
        std::vector<sf::FloatRect> BoxObjetos;
        sf::Text Inventario;

        sf::RectangleShape CuadroTexto;
        std::vector<sf::Text> Textito;

        
        
        
        std::string textoCompletoActual;
        size_t caracteresMostrados;
        bool paginaTerminada;
        const sf::Time TIEMPO_POR_CARACTER = sf::milliseconds(40);
        const float ANCHO_MAXIMO_TEXTO = 700.0f;

        bool Pelear(sf::RenderWindow& window, Personaje& pj, Enemigo& enem);
        void ResetearNarrativa(const std::string& nuevoTexto);
        void ActualizarInfoPersonaje(const Personaje& pj);
        void RenderizarOpciones(const Escena* escenaActual);
        void ActualizarInventario(Escena* h);
        void InventarioPersonaje(const Personaje& pj);
        void InfoObjeto(const Personaje& pj);
        
    public:
        void Iniciar(Personaje& pj, Historia& h);
        Juego(sf::RenderWindow& Window);
};