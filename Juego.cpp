#include <iostream>
#include "Juego.hpp"



Juego::Juego(sf::RenderWindow& Window) : window(Window){

    if (!font.loadFromFile("Textos/leadcoat.ttf")){
        std::cerr<<"Error al cargar la fuente"<<std::endl;
    }

    textoVisible.setFont(font);
    textoVisible.setCharacterSize(22);
    textoVisible.setFillColor(sf::Color::White);
    textoVisible.setPosition(50.f, 150.f);

    textoAtributos.setFont(font);
    textoAtributos.setCharacterSize(18);
    textoAtributos.setFillColor(sf::Color::Cyan); 
    textoAtributos.setPosition(50.f, 50.f); 

    textoVida.setFont(font);
    textoVida.setCharacterSize(18);
    textoVida.setFillColor(sf::Color::Green);
    textoVida.setPosition(550.f, 50.f);
    
    caracteresMostrados = 0;
    paginaTerminada = false;
}

void Juego::ResetearNarrativa(const std::string& text ){
    textoCompletoActual = text;
    caracteresMostrados = 0;
    paginaTerminada = false;
    clock.restart();
    opcionesTextoSFML.clear();
}

void Juego::ActualizarInfoPersonaje(const Personaje& pj) {
    std::string atributos = "Fuerza: " + std::to_string(pj.getFuerza()) + " | Intel: " + std::to_string(pj.getInteligencia()) + " | Suerte: " + std::to_string(pj.getSuerte());
    textoAtributos.setString(atributos);
    std::string vida = "VIDA: " + std::to_string(pj.getVida()) + "/10"; // Ajusta 100 si es necesario
    textoVida.setString(vida);
}

void Juego::RenderizarOpciones(const Escena* escenaActual) {
    opcionesTextoSFML.clear();
    BoxOpciones.clear();
    const auto& opciones = escenaActual->GetTextop(); 
    for (size_t j = 0; j < opciones.size(); ++j) {
        sf::Text opcionSFML;
        opcionSFML.setFont(font);
        opcionSFML.setCharacterSize(20);
        opcionSFML.setFillColor(sf::Color::White); 
        opcionSFML.setPosition(50.f, 400.f + j * 30.f); 
        opcionSFML.setString(std::to_string(j + 1) + ". " + opciones[j]);
        opcionesTextoSFML.push_back(opcionSFML);
        BoxOpciones.push_back(opcionSFML.getGlobalBounds());
    }
}






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
    auto allescenes = h.GetEscena();
    if (allescenes.empty()) {
        std::cerr << "Error: No hay escenas en la historia." << std::endl;
        return; 
    }
    size_t i = 0;
    size_t f = allescenes.size();
    auto z = allescenes[i];
    ResetearNarrativa(z->GetTexto());

    while(window.isOpen() && pj.getVivo() && i< f){

        sf::Event event;
        sf::Vector2f mousepos = (sf::Vector2f)sf::Mouse::getPosition(window);
        while (window.pollEvent(event)){


            if (event.type == sf::Event::Closed)
                window.close();

            

            if(paginaTerminada){
                RenderizarOpciones(z);
                if(z->OpVacio()){

                    if(event.type == sf::Event::MouseButtonReleased){
                        i++;
                        z = allescenes[i];
                        if (i < f){
                            ResetearNarrativa(z->GetTexto());
                        }
                        else{
                            std::cout<<"Historia Terminada";
                            //Funcion Game Over
                        }
                    }
                }
                else{ 
                    if(event.mouseButton.button == sf::Mouse::Left){
                        sf::Vector2f clickPos((float)event.mouseButton.x, (float)event.mouseButton.y);

                        for(size_t j = 0; j < BoxOpciones.size(); j++){

                            if(BoxOpciones[j].contains(clickPos)){
                                z = z->GetEscena(j);
                                ResetearNarrativa(z->GetTexto());
                            }

                        }
                    }
                }
            }
            else{
                if(event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left){
                   caracteresMostrados = textoCompletoActual.length();
                   textoVisible.setString(textoCompletoActual);
                   paginaTerminada = true;
                }

            }

        }


        if(!z->OpVacio() && paginaTerminada){
            for(size_t k = 0; k < BoxOpciones.size(); k++){
                if(BoxOpciones[k].contains(mousepos)){
                    opcionesTextoSFML[k].setFillColor(sf::Color::Blue);
                }
                else{
                    opcionesTextoSFML[k].setFillColor(sf::Color::Yellow);
                }
            }
        }


        window.clear();
        if (paginaTerminada && !z->OpVacio()) {
            for(const auto& opcion : opcionesTextoSFML) {
                window.draw(opcion);
            }
        }
        window.draw(textoVisible);
        window.display();
    }

}

