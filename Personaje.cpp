#include <iostream>
#include "Personaje.hpp"
#include "Armas.hpp"

Personaje::Personaje(Heroe nom) {
    tipo = nom;
    vivo = true;
    std::get<0>(arm) = Arma::Ninguna;
    std::get<1>(arm) = 0;

    switch (nom) {
        case Heroe::Sifrino:
            vida = 3;
            suerte = 13;
            inteligencia = 6;
            fuerza = 5;
            break;
        case Heroe::Otaku:
            vida = 5;
            suerte = 15;
            inteligencia = 3;
            fuerza = 6;
            break;
        case Heroe::Negro:
            vida = 7;
            suerte = 2;
            inteligencia = 12;
            fuerza = 8;
            break;   
        case Heroe::Fifas:
            vida = 5;
            inteligencia = 3;
            suerte = 6;
            fuerza = 13;
            break;
    }
}
void Personaje::ImprimirStats()const{
    std::cout<<" Vida: " <<vida << "Inteligencia, Fuerza: " <<inteligencia << " " <<fuerza;

}
bool Personaje::getVivo() const{
    return vivo;
}
int Personaje::getVida() const{
    return vida;
}
Heroe Personaje::getTipo() const{
    return tipo;
}
void Personaje::RecogerArma(Arma a, int b){
    std::get<0>(arm) = a;
    std::get<1>(arm) = b;
}
std::string Personaje::TipotoString()const{
    switch(tipo){
        case Heroe::Sifrino :
            return "Sifrino";
        
        case Heroe::Otaku :
            return "Otaku";
        
        case Heroe::Negro : 
            return "Negro";

        case Heroe::Fifas :
            return "Fifas";
    }
    return "";
}

void Personaje::Curar(int v){
    vida += v;
    if(vida > 10){
        vida = 10;
    }

}
void Personaje::RecibirDanio(int d){
    vida -= d;
    if(vida <= 0){
        vivo = false;
    }
}
int Personaje::getFuerza() const{
    return fuerza;
}
int Personaje::getInteligencia() const{
    return inteligencia;
}
int Personaje::getSuerte() const{
    return suerte;
}


// PASANDO A FUNCIONES DE ENEMIGOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
Enemigo::Enemigo(Enem x ){
    tipo = x;
    vivo = true;
    switch(tipo){
        case Enem::Rata :
            vida = 8;
            std::get<0>(arm) = ArmEne::Garras;
            std::get<1>(arm) = 2;
            break;
        
        case Enem::Cucaracha :
            vida = 5;
            std::get<0>(arm) = ArmEne::Mordida;
            std::get<1>(arm) = 3;
            break;
        
        case Enem::Saqueador :
            vida = 10;
            std::get<0>(arm) = ArmEne::Pistola;
            std::get<1>(arm) = 5;
            break;
        
        case Enem::Perro : 
            vida = 12;
            std::get<0>(arm) = ArmEne::Mordida;
            std::get<1>(arm) = 2;
            break;
    }

}

bool Enemigo::getVivo() const{
    return vivo;
}
int Enemigo::getVida() const{
    return vida;
}
std::string Enemigo::getNombre() const{
    switch(tipo){
        case Enem::Rata :
            return "Rata";
        
        case Enem::Cucaracha :
            return "Cucaracha";
        
        case Enem::Saqueador :
            return "Saqueador";
        
        case Enem::Perro : 
            return "Perro";
    }
    return "";
}

