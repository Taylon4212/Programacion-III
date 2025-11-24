#include <SFML/Graphics.hpp>
#include <iostream>
#include "Personaje.hpp"
#include "Armas.hpp"
#include "menu.hpp"
#include "History.hpp"
#include "Juego.hpp"
#include <SFML/Audio.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1220,800), "FArlaut RPG");

    Menu m;

    while(window.isOpen()){

        m.MostrarMenu(window);


    }

    return 0;
}