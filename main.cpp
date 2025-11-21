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
    Historia h; 
    Personaje p1(Heroe::Negro);
    Juego game;
    game.Iniciar(p1, h);

    Menu m;
    while(m.MostrarMenu()){
        
    }
    
    return 0;
}