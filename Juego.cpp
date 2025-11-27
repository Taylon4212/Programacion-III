#include <iostream>
#include <sstream>
#include "Juego.hpp"



Juego::Juego(sf::RenderWindow& Window) : window(Window){

    if (!font.loadFromFile("Textos/leadcoat.ttf")){
        std::cerr<<"Error al cargar la fuente"<<std::endl;
    }
    fondo.loadFromFile("Imagenes/FondoJuego.png");

    Continuar.setFont(font);
    Continuar.setString("Continuar");
    Continuar.setCharacterSize(22);
    Continuar.setFillColor(sf::Color::Blue);
    Continuar.setPosition(400.f, 600.f);
    BoxContinuar = Continuar.getGlobalBounds();


    textoVisible.setFont(font);
    textoVisible.setCharacterSize(22);
    textoVisible.setFillColor(sf::Color::White);
    textoVisible.setPosition(50.f, 150.f);

    textoAtributos.setFont(font);
    textoAtributos.setCharacterSize(20);
    textoAtributos.setFillColor(sf::Color::Cyan); 
    textoAtributos.setPosition(900.f, 260.f); 

    textoVida.setFont(font);
    textoVida.setCharacterSize(20);
    textoVida.setFillColor(sf::Color::Green);
    textoVida.setPosition(950.f, 220.f);

    Inventario.setString("Inventario: ");
    Inventario.setFont(font);
    Inventario.setCharacterSize(25);
    Inventario.setFillColor(sf::Color::White);
    Inventario.setPosition(950.f, 300.f);
    
    caracteresMostrados = 0;
    paginaTerminada = false;

    CuadroTexto.setFillColor(sf::Color(30, 28, 70, 200)); 
    CuadroTexto.setOutlineColor(sf::Color::White);
    CuadroTexto.setOutlineThickness(1.0f);
    CuadroTexto.setSize({230.f, 80.f});
    CuadroTexto.setPosition(650.f, 700.f);

    

}

void Juego::ResetearNarrativa(const std::string& text ){
    std::string textoProcesado = "";
    std::string lineaActual = "";
    
    std::stringstream ss(text);
    std::string palabra;
    
    while (ss >> palabra) {
        
        std::string intentoNuevaLinea = lineaActual;
        if (!lineaActual.empty()) {
            intentoNuevaLinea += " "; 
        }
        intentoNuevaLinea += palabra;
        sf::Text medidor(intentoNuevaLinea, font, textoVisible.getCharacterSize());
        if (medidor.getGlobalBounds().width > ANCHO_MAXIMO_TEXTO) {
            textoProcesado += lineaActual + "\n";
            lineaActual = palabra; 
        } else {
            lineaActual = intentoNuevaLinea;
        }
    }
    textoProcesado += lineaActual;
    textoCompletoActual = textoProcesado; 

    caracteresMostrados = 0;
    paginaTerminada = false;
    clock.restart();
    opcionesTextoSFML.clear();
}

void Juego::ActualizarInfoPersonaje(const Personaje& pj) {
    std::string atributos = "Fuerza: " + std::to_string(pj.getFuerza()) + " | Intel: " + std::to_string(pj.getInteligencia()) + " | Suerte: " + std::to_string(pj.getSuerte());
    textoAtributos.setString(atributos);
    std::string vida = "VIDA: " + std::to_string(pj.getVida()) + "/10";
    textoVida.setString(vida);

}

void Juego::InventarioPersonaje(const Personaje& pj){

    sf::Sprite sprite;
    sf::Texture texture;
    int j = 0.f;
    int i = 0.f;
    ObjetosPerso.clear();
    BoxObjetos.clear();

    for(auto x : pj.getInventario()){

        sprite = x->getSprite();
        sprite.setScale(0.08f, 0.08f );
        sprite.setPosition(880 + j * 110, 350 + i * 100);
        
        ObjetosPerso.push_back(sprite);
        BoxObjetos.push_back(sprite.getGlobalBounds());
        j++;

        if(j % 2 == 0){
            j = 0;
            i++;
        }


    }

}

void Juego::ActualizarInventario(Escena* h){

    if(h->tieneobj()){
        int j = 0;
        sf::Text mientras("", font, 20);
        for(auto x: h->getObjetos()){
            j++;
            std::string h = std::to_string(x->getCantidad());
            mientras.setString(x->getNombre() + "s, Cantidad: " + h);
            mientras.setPosition(300.f, 400.f + j * 30.f);
            TextObjetos.push_back(mientras);
        }
    }
    else{
        TextObjetos.clear();
    }
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


void Juego::InfoObjeto(const Personaje& pj) {

    Textito.clear();
    sf::Text mientras("", font, 20);
    std::string info;
    auto x = pj.getInventario();

    for(size_t j = 0; j < x.size(); j++){

        info = x[j]->getNombre() + "\n";
        info += "Uso: " + x[j]->getUso() + "\n";
        info += "Cantidad: " + std::to_string( x[j]->getCantidad());
        mientras.setPosition(650.f, 700.f);

        mientras.setString(info);
        Textito.push_back(mientras);
    }

}




bool Juego::Pelear(sf::RenderWindow& window, Personaje& pj, Enemigo& enem){
    sf::Texture fondopelea;
    fondopelea.loadFromFile("Imagenes/FondoPelea.png");
    sf::Sprite FondoPelea(fondopelea);
    FondoPelea.setScale(800.f / fondopelea.getSize().x , 800.f / fondopelea.getSize().y);
    FondoPelea.setPosition(1, 1);
    

    sf::Clock clock;
    const sf::Time TIEMPO_ESPERA = sf::seconds(1.5f);

    sf::Text Danopj(std::to_string(-(pj.getdano())), font, 50);
    sf::Text Danoen(std::to_string(-(enem.getdano())), font, 50);
    Danoen.setFillColor(sf::Color::Red);
    Danopj.setFillColor(sf::Color::Red);
    //sf::Text Vidapj("Vida: " + std::to_string(pj.getVida()), font, 50);
    sf::Text Vidaen("    " + enem.getNombre() + "\n Vida: " + std::to_string(enem.getVida()), font, 37);

    Danopj.setPosition(330, 250);
    Danoen.setPosition(290, 460);
    //Vidapj.setPosition(300, 300);
    Vidaen.setPosition(420, 420);


    bool Endpj = false;
    bool Enden = false;

    sf::Text victoria("Victoria", font, 100);
    victoria.setPosition(150, 150);
    sf::Text derrota("Derrota", font, 100);
    derrota.setPosition(150,150);


    while(window.isOpen()){
        sf::Event event;
        sf::Vector2f mousepos = (sf::Vector2f)sf::Mouse::getPosition(window);
        
        while (window.pollEvent(event)){

            if (event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::MouseButtonReleased)
            {

                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2f clickPos((float)event.mouseButton.x, (float)event.mouseButton.y);

                    if(!ObjetosPerso.empty()){

                        for(size_t x = 0; x < BoxObjetos.size() ; x++){

                            if(BoxObjetos[x].contains(clickPos)){

                                pj.usarObjetoEnRanura(x);
                                ActualizarInfoPersonaje(pj);
                                InventarioPersonaje(pj);
                                //Vidapj.setString("Vida: " + std::to_string(pj.getVida()));

                            }

                        }

                    }
                }
                
            }
                    

        }

        
        if(!Endpj){
            if(clock.getElapsedTime() >= TIEMPO_ESPERA){
                enem.CambiarVida(-(pj.getdano()));
                Vidaen.setString("    " + enem.getNombre() + "\n Vida: " + std::to_string(enem.getVida()));
                Endpj = true;
                clock.restart();
            }
        }
        
        if (!enem.getVivo()) {
            
            if (clock.getElapsedTime() >= TIEMPO_ESPERA) {

                return true;
            }
        }
        
        if(Endpj && !Enden){
            if(clock.getElapsedTime() >= TIEMPO_ESPERA){
                pj.RecibirDanio(enem.getdano());
                ActualizarInfoPersonaje(pj);
                //Vidapj.setString("Vida: " + std::to_string(pj.getVida()));
                clock.restart();
                Enden = true;
            }
            

        }

        if (pj.getVivo() && Enden) {
            if (clock.getElapsedTime() >= TIEMPO_ESPERA) {
                Endpj = false;
                Enden = false;
            }
        }

        else if (Enden && !pj.getVivo()){
            if (clock.getElapsedTime() >= TIEMPO_ESPERA) {
                return false;
            }
        }


        if(!ObjetosPerso.empty()){
            for(size_t x = 0; x < BoxObjetos.size() ; x++){
                if(BoxObjetos[x].contains(mousepos)){
                    ObjetosPerso[x].setColor(sf::Color::Red);
                }
                else{
                    ObjetosPerso[x].setColor(sf::Color::White);
                }
            }
        }

        window.clear();
        window.draw(FondoPelea);
                
        

        if(Enden){
            window.draw(Danoen);
           
        }else if(Endpj){
            window.draw(Danopj);
            
        }
        
        //window.draw(Vidapj);
        window.draw(Vidaen);

        if(pj.getVivo() && !enem.getVivo()){
            window.draw(victoria);
        }
        else if(!pj.getVivo() && enem.getVivo()){
            window.draw(derrota);
        }
        if(!ObjetosPerso.empty()){
            for(auto f : ObjetosPerso){
                window.draw(f);
            }
        }
        
        window.draw(textoAtributos);
        window.draw(textoVida);
        window.draw(Inventario);
        window.draw(pj.getSprite());
        window.draw(pj.getFoto());
        window.display();
    }
    return pj.getVivo();
}








void Juego::Iniciar(Personaje& pj, Historia& h){
    pj.RecogerArma(Arma::pistola, 2);
    ActualizarInfoPersonaje(pj);
    sf::Sprite fondoSprite(fondo);
    float xventana = static_cast<float>(window.getSize().x);
    float yventana = static_cast<float>(window.getSize().y);
    float escalaX = xventana / fondo.getSize().x;
    float escalaY = yventana / fondo.getSize().y;
    fondoSprite.setScale(escalaX,escalaY);


    auto allescenes = h.GetEscena();

    if (allescenes.empty()) {
        std::cerr << "Error: No hay escenas en la historia." << std::endl;
        return; 
    }
    size_t i = 0;
    size_t f = allescenes.size();
    auto z = allescenes[i];
    ResetearNarrativa(z->GetTexto());

    while(window.isOpen() && pj.getVivo() && i < f){

        sf::Event event;
        sf::Vector2f mousepos = (sf::Vector2f)sf::Mouse::getPosition(window);
        while (window.pollEvent(event)){
            

            
            
            if (event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::MouseButtonReleased)
            {

                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2f clickPos((float)event.mouseButton.x, (float)event.mouseButton.y);

                    if(paginaTerminada){

                        RenderizarOpciones(z);
                        if(z->OpVacio()){
                
                            if(BoxContinuar.contains(clickPos)){
                                ActualizarInventario(z);
                                if(z->vivoenemi()){
                                    Pelear(window, pj, *z->GetEnemigo());
                                    ActualizarInfoPersonaje(pj);
                                }

                                i++;
                                if (i < f){
                                    z = allescenes[i];
                                    ResetearNarrativa(z->GetTexto());
                                }
                                else{
                                    std::cout<<"Historia Terminada";
                                    //Funcion Game Over
                                }
                            }
                            
                            

                        }
                        else{
                            for(size_t j = 0; j < BoxOpciones.size(); j++)
                            {

                                if(BoxOpciones[j].contains(clickPos))
                                {
                                    ActualizarInventario(z);
                                    z = z->GetEscena(j);
                                    ResetearNarrativa(z->GetTexto());
                                }

                            }
                        
                        }
                    }else{
                        if(event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
                        {
                            caracteresMostrados = textoCompletoActual.length();
                            textoVisible.setString(textoCompletoActual);
                            paginaTerminada = true;
                        }
                    }
                    if(!ObjetosPerso.empty()){

                        for(size_t x = 0; x < BoxObjetos.size() ; x++){

                            if(BoxObjetos[x].contains(clickPos)){

                                pj.usarObjetoEnRanura(x);
                                ActualizarInfoPersonaje(pj);
                                InventarioPersonaje(pj);
                                InfoObjeto(pj);

                            }

                        }

                    }
                
                }     
            }
        }
            
            if(z->tieneobj()){
                for(auto x : z->getObjetos()){

                    Objeto* copia(x);
                    pj.anadirObjeto(copia);

                }
                ActualizarInventario(z);
                z->Vaciar();
                InventarioPersonaje(pj);
                InfoObjeto(pj);
            }
            
        if (!paginaTerminada) {
            RenderizarOpciones(z);
            if (clock.getElapsedTime() >= TIEMPO_POR_CARACTER) {
                if (caracteresMostrados < textoCompletoActual.length()) {
                    caracteresMostrados++;
                    textoVisible.setString(textoCompletoActual.substr(0, caracteresMostrados));
                    clock.restart();
                } else {
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
        if(z->OpVacio() && paginaTerminada ){
            if(BoxContinuar.contains(mousepos)){
                Continuar.setFillColor(sf::Color::Red);
            }
            else{
                Continuar.setFillColor(sf::Color::Blue);
            }
        }

        if(!ObjetosPerso.empty()){
            for(size_t x = 0; x < BoxObjetos.size() ; x++){
                if(BoxObjetos[x].contains(mousepos)){
                    ObjetosPerso[x].setColor(sf::Color::Red);
                }
                else{
                    ObjetosPerso[x].setColor(sf::Color::White);
                }
            }
        }
       
        //Escritura en pantalla
        

        window.clear();
        window.draw(fondoSprite);
        if (paginaTerminada && !z->OpVacio()) {
            for(const auto& opcion : opcionesTextoSFML) {
                window.draw(opcion);
            }
        }

        if(paginaTerminada && z->OpVacio()){
            window.draw(Continuar);
        }

        window.draw(textoVisible);
        window.draw(textoVida);
        window.draw(textoAtributos);
        window.draw(Inventario);

        if(!ObjetosPerso.empty()){
            for(auto f : ObjetosPerso){
                window.draw(f);
            }
        }

        if(paginaTerminada && !TextObjetos.empty()){
            for(auto f : TextObjetos){
                window.draw(f);
            }
        }

        if(!ObjetosPerso.empty()){

            for(size_t x = 0; x < BoxObjetos.size() ; x++){

                if(ObjetosPerso[x].getColor() == sf::Color::Red){
                    window.draw(CuadroTexto);
                    window.draw(Textito[x]);
                }

            }

        }

        window.draw(pj.getFoto());
        window.display();
    }

}

