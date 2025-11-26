#include "escenarios.hpp"
#include <iostream>
#include <vector>


Escena::Escena(const std::string& tex, const std::string& rutafondo){

    fondoes.loadFromFile(rutafondo);
    texto = tex;
    enemigo = nullptr;

}

Escena::~Escena() {
    if (enemigo != nullptr) {
        delete enemigo;
        enemigo = nullptr;
    }
    
    for(Objeto* obj : objetosEnEscena){
        if(obj != nullptr){
            delete obj;
        }
    }
    objetosEnEscena.clear();

    for (Escena* opcion : Opciones) {
        if (opcion != nullptr) {
            delete opcion;
        }
    }

    Opciones.clear();
    
}

bool Escena::vivoenemi(){
    if(enemigo == nullptr){
        return false;
    }
    else{
        return true;
    }
}
bool Escena::OpVacio(){
    if(Opciones.empty()){
        return true;
    }
    else{
        return false;
    }
}

Escena* Escena::GetEscena(int n){
    return Opciones[n];
}

Enemigo* Escena::GetEnemigo(){
    return enemigo;
}

std::string Escena::GetTexto(){
    return texto;
}


std::vector<std::string> Escena::GetTextop() const{
    return Textop;
}



void Escena::setEnemi(Enemigo* enen){
    enemigo = enen;
}

void Escena::setOpcion(Escena* es, std::string opci){
    Textop.push_back(opci);
    Opciones.push_back(es);
}



void Escena::setRequi(int f, int in, int su){
    reqFuerza = f;
    reqInteligencia = in;
    reqSuerte = su;


}

bool Escena::Cumplerequi(Personaje& pj){
    if(pj.getFuerza() >= reqFuerza && pj.getInteligencia() >= reqInteligencia && pj.getSuerte() >= reqSuerte && necesitallave()){
        if(pj.tieneLlave( m_nombreLlaveRequerida)){
            return true;
        }
        else{
            return false;
        }


    }
    else{
        return false;
    }

}

void Escena::setLlaveRequerida(const std::string& nombreLlave){
    m_nombreLlaveRequerida = nombreLlave;
}

const std::string& Escena::getLlaveRequerida()const {

    return m_nombreLlaveRequerida;

}

bool Escena::necesitallave(){

    if(m_nombreLlaveRequerida == ""){
        return false;
    }
    else{
        return true;
    }
}

void Escena::anadirObjEs(Objeto* obj){
    objetosEnEscena.push_back(obj);
}

void Escena::removerObjEs(Objeto* obj){
    for (auto it = objetosEnEscena.begin(); it != objetosEnEscena.end(); ++it) {
        if (*it == obj) {
            objetosEnEscena.erase(it);
        }
    }    

}

bool Escena::tieneobj(){
    if(objetosEnEscena.empty()){
        return false;
    }
    return true;
}

int Escena::cantObjetos(){
    return objetosEnEscena.size();
}

const std::vector<Objeto*>& Escena::getObjetos() const{
    return objetosEnEscena;
}
void Escena::Vaciar(){
    objetosEnEscena.clear();
}
