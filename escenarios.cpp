#include "escenarios.hpp"
#include <iostream>
#include <vector>


Escena::Escena(std::string tex){
    texto = tex;
    enemigo = nullptr;
}

void Escena::ImprimirTexto(){
    std::cout<<texto;

}

void Escena::MostrarOp(){
    if(!Opciones.empty()){
        std::cout<<"Seguir Adelante";
    }
    else{
        int num = 0;
        for(auto x : Opciones){
            num++;
            std::cout<<num<<"Opcion: " <<x <<std::endl;
        }
    }


}

Escena* Escena::GetEscena(int n){
    return Opciones[n - 1];
}

void Escena::setEnemi(Enemigo* enen){
    enemigo = enen;
}

void Escena::setOpcion(Escena* es, std::string opci){
    Textop.push_back(opci);
    Opciones.push_back(es);
}

bool Escena::vivoenemi(){
    if(enemigo == nullptr){
        return false;
    }
    else{
        return true;
    }
}

Enemigo* Escena::GetEnemigo(){
    return enemigo;
}
