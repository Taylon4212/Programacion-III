#include <iostream>
#include "History.hpp"



//Construccion de la Historia

Historia::Historia(){

    Lineal.push_back(new Escena("Una vez en el yermo, la caminata de nuestro aventurero comienza su larga aventura, con las pocas provisiones que logro obtener durante su vida del bunker, nuestro personaje, siguiendose de un mapa roto, que le fue entregado por su madre, sabe que debe viajar a el norte, por lo que avanza con cautela a través de las calles abandonadas y peligrosas de el yermo de lo que alguna  vez fue mérida."));
    std::string TextoEscena = R"(Nuestro superviviente luego de caminar un rato, y observar lo destruido que se encuentra todo, se nota a si mismo extraño, como fuera de lugar, el no pertenece aquí, y teme por que alguien mas se de cuenta de ello.

	Después de pasar un poco de paranoia, nuestro superviviente escucha un ruido ensordecedor, ¿que puede ser?¿Un disparo?, ¿una explosion?, lleno de miedo, se refugia en un edificio que tiene a su lado

    ¿que debería de hacer?.)";
    Lineal.push_back(new Escena(TextoEscena));

    Escena* Decision = Lineal.back();

    Escena* Opcion1 = new Escena("Al salir e investigar un poco, nuestro personaje se da cuenta de que simplemente se desprende un pedazo de terraza de un edificio, la caída provoco ese sonido tan ensordecedor. te alivias por un instante, luego te das cuenta de que es muy probable de que en algún momento te pueda caer un pedazo de edificio encima.\n"
    "Supongo que debo tener vigilado el cielo…");
    Escena* Opcion2 = new Escena("Al investigar un poco el edificio, escuchas unos chillidos como de puertas no engrasadas, decides entrar al pasillo oscuro y te encuentras.\n"
	"¿Una… cucaracha?...\n"
	"En el bunker vi muchas, pero no de el TAMAÑO DE UNA PERSONA!!!. De sus piezas bucales gotea un líquido verde y viscoso que sisea al tocar el suelo, dejando un pequeño hoyo humeante. No es solo espantosa... es una fábrica ambulante de veneno radiactivo\n"
    "La criatura detiene su deambular. Sus antenas se erizan y se giran hacia ti con una velocidad sobrenatural. No hay tiempo para correr. ¡Es una batalla!\n");
    Enemigo* z = new Enemigo(Enem::Cucaracha);
    Opcion2->setEnemi(z);


    Decision->setOpcion(Opcion1, "Salir y investigar que sucedió ");
    Decision->setOpcion(Opcion2, "Quedarse e investigar el lugar");
    //Recordar Utilizar En Funcion Escenario un booleano para saber si tiene opciones
    Lineal.push_back(new Escena(" prueba cap 2"));
    Lineal.push_back(new Escena(" prueba cap 3"));
    
}

Historia::~Historia() {
    for (Escena* escena : Lineal) {
        if (escena != nullptr) {
            delete escena; 
        }
    }
}

const std::vector<Escena*>& Historia::GetEscena() const {
    return Lineal;
}