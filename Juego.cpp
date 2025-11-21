#include <iostream>
#include "Juego.hpp"


bool Juego::Pelear(Personaje& pj, Enemigo& enem){
    while(pj.getVivo() && enem.getVivo()){
        std::cout<<"Superviviente ataca y hace: "<<pj.getdano() <<std::endl;
        enem.CambiarVida( - (pj.getdano()));
        std::cout<<"Vida de Enemigo: " <<enem.getVida()<<std::endl;
        if(enem.getVivo() == false){
            break;
        }
        std::cout<<enem.getNombre() << "Ataca con: " <<enem.getArma() <<std::endl;
        pj.RecibirDanio(enem.getdano());
        std::cout<<"Vida Restante: " <<pj.getVida()<<std::endl;
    }
    return pj.getVivo();
}

void Juego::Iniciar(Personaje& pj, Historia& h){
    //pj.RecogerArma(Arma::pala,2);
    auto x = h.GetEscena();
    size_t f = x.size();
    size_t i = 0;
    while(pj.getVivo() && i < f){
        auto z = x[i];
        z->ImprimirTexto();
        while(!z->OpVacio()){

            z->MostrarOp();
            int eleccion;
            std::cin>>eleccion;
            z = z->GetEscena(eleccion);
            z->ImprimirTexto();
            if(z->vivoenemi()){
                if(this->Pelear(pj ,*(z->GetEnemigo()))){
                    break;
                }
            }

        }
        i++;
    }
}

