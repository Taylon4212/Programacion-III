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

    Heroe j = m.MostrarMenu(window);


    Personaje pj(j);
    Historia h;
    Juego game(window);
    game.Iniciar(pj, h);

    return 0;
}