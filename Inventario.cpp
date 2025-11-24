#include <iostream>
#include "Inventario.hpp"

Objeto::Objeto(TipoObjeto t, std::string n, std::string u, int c, const std::string& texture)
    : tipo(t), nombre(n), uso(u), cantidad(c) {
    
    if (!textura.loadFromFile(texture)) {
        std::cerr << "Error al cargar la textura del objeto: " << texturePath << std::endl;
    }
    sprite.setTexture(textura);
    sprite.setScale(0.5f, 0.5f);
}

TipoObjeto Objeto::getTipo() const {
    return tipo;
}
std::string Objeto::getNombre() const {
    return nombre;
}
std::string Objeto::getUso() const {
    return uso;
}
int Objeto::getCantidad() const {
    return cantidad;
}
void Objeto::sumarCantidad(int c) {
    cantidad += c;
}
bool Objeto::usarObjeto(int c){
    if(cantidad >= c){
        cantidad -= c;
        return true;
    }
    else{
        std::cout<<"No tienes suficientes objetos de este tipo para usar"<<std::endl;
        return false;
    }
}
sf::Sprite& Objeto::getSprite(){

    return sprite;
}