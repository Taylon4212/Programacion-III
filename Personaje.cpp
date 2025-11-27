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
            PosesPersonaje.loadFromFile("Imagenes/SifrinoPos1.png");
            FotoPer.loadFromFile("Imagenes/Sifrinos.png");
            break;
        case Heroe::Otaku:
            vida = 5;
            suerte = 15;
            inteligencia = 3;
            fuerza = 6;
            PosesPersonaje.loadFromFile("Imagenes/OtakuPos1.png");
            FotoPer.loadFromFile("Imagenes/Otaku.png");
            break;
        case Heroe::Negro:
            vida = 7;
            suerte = 2;
            inteligencia = 12;
            fuerza = 8;
            PosesPersonaje.loadFromFile("Imagenes/NegroPos1.png");
            FotoPer.loadFromFile("Imagenes/Negro.png");
            break;   
        case Heroe::Fifas:
            vida = 5;
            inteligencia = 3;
            suerte = 6;
            fuerza = 13;
            PosesPersonaje.loadFromFile("Imagenes/FifasPos1.png");
            FotoPer.loadFromFile("Imagenes/Fifas.png");
            break;
    }

    PosesPersonajes.setTexture(PosesPersonaje);
    PosesPersonajes.setScale(0.7f, 0.7f);
    PosesPersonajes.setPosition(260,500);
    FotoPers.setTexture(FotoPer);
    FotoPers.setScale(0.2f, 0.15f);
    FotoPers.setPosition(920.f , 40.f);

}
Personaje::~Personaje(){

    for (Objeto* obj : inventario) {
        delete obj;
    }
    inventario.clear();

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
int Personaje::getdano(){
    return std::get<1>(arm);
}
void Personaje::anadirObjeto(Objeto* obj){
    bool encontradoYAgregado = false;
    for (auto it = inventario.begin(); it != inventario.end(); ++it) {
        Objeto* objExistente = *it; 
    
        if (objExistente && obj) {

            if (objExistente->getNombre() == obj->getNombre()) {
                objExistente->sumarCantidad(obj->getCantidad()); 
                encontradoYAgregado = true;
                delete obj;
                obj = nullptr;
                break;
            }
        }
    }
    if (!encontradoYAgregado && obj) { 
        inventario.push_back(obj);
    }
}


bool Personaje::usarObjetoEnRanura(int indiceRanura){
    
    Objeto* objetoACambiar = inventario[indiceRanura];
    if (!objetoACambiar) {
        std::cerr << "Error: La ranura de inventario " << indiceRanura << " contiene un puntero nulo." << std::endl;
        return false;
    }

    bool AunHay = objetoACambiar->usarObjeto(*this); 
    if (AunHay) {
        return true;
    }
    else{
        delete objetoACambiar;
        inventario.erase(inventario.begin() + indiceRanura); 
        return true;
    }

}

const std::vector<Objeto*>& Personaje::getInventario() const{

    return inventario;

}


bool Personaje::tieneLlave(const std::string& nombreLlave) const{

    for(auto x : inventario){
        if(x && x->getNombre() == nombreLlave){
            return true;
        }
    }
    return false;

}
void Personaje::consumirLlave(const std::string& nombreLlave){
    for (auto it = inventario.begin(); it != inventario.end(); ++it) {
        Objeto* obj = *it;
        if (obj && obj->getTipo() == TipoObjeto::Llave && obj->getNombre() == nombreLlave) {
            delete obj; 
            inventario.erase(it); 
            return; 
        }
    }

}
sf::Texture& Personaje::getTexture(){
    return PosesPersonaje;
}
sf::Sprite& Personaje::getSprite(){
    return PosesPersonajes;
}
sf::Sprite& Personaje::getFoto(){
    return FotoPers;
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

std::string Enemigo::getArma() const{

    switch(std::get<0>(arm)){
        case ArmEne::Ninguna :
            return "Ninguna";
        
        case ArmEne::Garras :
            return "Garras";
        
        case ArmEne::Mordida :
            return "Mordida";
        
        case ArmEne::Pistola :
            return "Pistola";
    }
    return "";
}

void Enemigo::CambiarVida(int i){
    vida = vida + i;
    if(vida <= 0){
        vivo = false;
    }
}
int Enemigo::getdano(){
    return std::get<1>(arm);
}

