#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Personaje.hpp"
#pragma once

class Menu{
    private:
        sf::SoundBuffer SelecNegro;
        sf::Sound SeleccionNegro;

        sf::SoundBuffer SelecSifrino;
        sf::Sound SeleccionSifrino;

        sf::SoundBuffer SelecOtaku;
        sf::Sound SeleccionOtaku;

        sf::SoundBuffer SelecFifas;
        sf::Sound SeleccionFifas;

        sf::Music MusicMenu;


    public:
        bool MostrarMenu();
        Heroe elegirPersonaje(sf::RenderWindow& window);
        void acercaDe();
        //void cargarPartida();
        void MostrarCreditos(sf::RenderWindow& window);
        
};