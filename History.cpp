#include <iostream>
#include "History.hpp"


//Construccion de la Historia

Historia::Historia(){

    /*Inicio = new Escena("Despiertas en un bosque oscuro.");
    Escena* camino = new Escena("Sigues un sendero y encuentras una cabaña.");
    Escena* dormir = new Escena("Decides dormir bajo un árbol. Algo te observa...");

    Inicio->setOpcion(camino, "Explorar el sendero");
    Inicio->setOpcion(dormir, "Dormir bajo el árbol");

    Escena* cabaña = new Escena("Dentro de la cabaña encuentras un cofre misterioso.");
    camino->setOpcion(cabaña, "Entrar a la cabaña");

    Escena* pesadilla = new Escena("Tienes una pesadilla y pierdes energía.");
    dormir->setOpcion(pesadilla, "Seguir durmiendo");*/
}
Escena* Historia::GetEscena(){
    return Inicio;
}