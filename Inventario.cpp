#include <iostream>
#include "Inventario.hpp"
#include "Personaje.hpp"

Objeto::Objeto(TipoObjeto t, std::string n, std::string u, int c,int f, const std::string& texturePath_param)
    : tipo(t), nombre(n), uso(u), cantidad(c), efecto(f), m_texturePath(texturePath_param)
{
    if (!textura.loadFromFile(texturePath_param)) {
        std::cerr << "Error al cargar la textura del objeto: " << texturePath_param << std::endl;

    }
    sprite.setTexture(textura);
    sprite.setScale(0.5f, 0.5f);
}

Objeto::~Objeto(){

}

Objeto::Objeto(const Objeto& otro) 
    : tipo(otro.tipo),
      nombre(otro.nombre),
      uso(otro.uso),
      cantidad(otro.cantidad),
      efecto(otro.efecto),
      m_texturePath(otro.m_texturePath)
{
    if (!textura.loadFromFile(m_texturePath)) {
        std::cerr << "Error al cargar la textura del objeto" << m_texturePath << std::endl;
    }
    
    sprite.setTexture(textura);
    
    sprite.setScale(otro.sprite.getScale());
    sprite.setPosition(otro.sprite.getPosition());
    sprite.setRotation(otro.sprite.getRotation());
    sprite.setOrigin(otro.sprite.getOrigin());
}


TipoObjeto Objeto::getTipo() const {
    return tipo;
}

const std::string& Objeto::getNombre() const {
    return nombre;
}
const std::string& Objeto::getUso() const {
    return uso;
}
int Objeto::getEfecto() const{
    return efecto;
}
int Objeto::getCantidad() const {
    return cantidad;
}
void Objeto::sumarCantidad(int c) {
    cantidad += c;
}
bool Objeto::usarObjeto(Personaje& pj){
    switch(tipo){
        case TipoObjeto::Curar:
            pj.Curar(efecto);
            cantidad--;
            break;
        case TipoObjeto::Llave:
            return true;
        default:
            return true;
    }

    return cantidad > 0;
}
sf::Sprite& Objeto::getSprite(){
    return sprite;
}
const std::string& Objeto::getTexturePath() const {
    return m_texturePath;
}
sf::Texture& Objeto::getTexture(){

    return textura;

}