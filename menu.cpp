#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "menu.hpp"

Menu::Menu(){
    font.loadFromFile("Textos/leadcoat.ttf");

    //Imagen de Fondo Creditos
    back.loadFromFile("Imagenes/Menus2.png");
    backs.setTexture(back);

    float escalaX = 1220.f / back.getSize().x;
    float escalaY = 800.f / back.getSize().y;

    backs.setScale(escalaX, escalaY);








}
void Menu::MostrarCreditos(sf::RenderWindow& window){

    //Texto de Programacion
    sf::Text all("Proyecto de Programacion 3: \n\n Dickson Labrador", font,35);
    all.setPosition(40, 100);

    //Boton de atras
    sf::Text Atras("Atras", font, 50);
    Atras.setPosition(40, 480);
    sf::FloatRect hitBoxAtras = Atras.getGlobalBounds();

    bool Estado = true;

    while (Estado && window.isOpen())
    {
        sf::Event event;
        sf::Vector2f mousepos = (sf::Vector2f)sf::Mouse::getPosition(window);
        

            
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::MouseButtonReleased){

                if(event.mouseButton.button == sf::Mouse::Left){

                    sf::Vector2f clickPos((float)event.mouseButton.x, (float)event.mouseButton.y);

                    if(hitBoxAtras.contains(clickPos)){
                        Estado = false;
                    }
                }
            }
        }

        if(hitBoxAtras.contains(mousepos)){
            Atras.setFillColor(sf::Color::Red);
        }
        else{
            Atras.setFillColor(sf::Color::White);
        }


        window.clear();
        window.draw(backs);
        window.draw(Atras);
        window.draw(all);
        window.display();
    }
}

Heroe Menu::MostrarMenu(sf::RenderWindow& window){

    // Cargar los sonidos del menu

        MusicMenu.openFromFile("Sonidos/Menus.mp3");
        MusicMenu.setVolume(40.f);
        
        sf::SoundBuffer buffer2;
        buffer2.loadFromFile("Sonidos/Sonidos1.wav");
        sf::Sound sound(buffer2);



        SelecNegro.loadFromFile("Sonidos/Negro2.mp3");
        SeleccionNegro.setBuffer(SelecNegro);

        

        //SelecSifrino.loadFromFile("");
        //SeleccionSifrino.setBuffer();

        //SelecOtaku.loadFromFile("");
        //SeleccionOtaku.setBuffer();

        SelecFifas.loadFromFile("Sonidos/Fifas1.mp3");
        SeleccionFifas.setBuffer(SelecFifas);


        //Cargar las Imagenes 

        
        sf::Texture fondo;
        fondo.loadFromFile("Imagenes/Menus.jpg");
        sf::Sprite fondos(fondo);




        //Ajustando el fondo a la ventana
        float ventanaAncho = static_cast<float>(window.getSize().x);
        float ventanaAlto = static_cast<float>(window.getSize().y);
        float escalaX = ventanaAncho / fondo.getSize().x;
        float escalaY = ventanaAlto / fondo.getSize().y;
        fondos.setScale(escalaX, escalaY);


        //Reproducioendo la musica
        //MusicMenu.play();
        //SeleccionNegro.play();


        //Botones de iniciar partida
        sf::Text nuevoJuego("Nuevo juego", font, 50);
        nuevoJuego.setPosition(40, 130);
        //Boton de salir
        sf::Text Salir("Salir", font, 50);
        Salir.setPosition(40, 330);
        //boton de Creditos
        sf::Text Creditos("Creditos", font, 50);
        Creditos.setPosition(40, 230);


        //Guardando el hitBox de cada Texto
        sf::FloatRect hitBoxNuevo = nuevoJuego.getGlobalBounds();
        sf::FloatRect hitBoxSalir = Salir.getGlobalBounds();
        sf::FloatRect hitBoxCreditos = Creditos.getGlobalBounds();


        while (window.isOpen())
        {
            sf::Event event;
            sf::Vector2f mousepos = (sf::Vector2f)sf::Mouse::getPosition(window);

            
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();

                if(event.type == sf::Event::MouseButtonReleased){

                    if(event.mouseButton.button == sf::Mouse::Left){

                        sf::Vector2f clickPos((float)event.mouseButton.x, (float)event.mouseButton.y);

                        if(hitBoxNuevo.contains(clickPos)){
                            return elegirPersonaje(window);
                        }
                        else if(hitBoxCreditos.contains(clickPos)){
                            MostrarCreditos(window);

                        }
                        else if(hitBoxSalir.contains(clickPos)){
                            window.close();
                        }
                    }
                }
                
            }
            
            if(hitBoxNuevo.contains(mousepos)){
                nuevoJuego.setFillColor(sf::Color::Red);
            }
            else{
                nuevoJuego.setFillColor(sf::Color::White);
            }
            if(hitBoxSalir.contains(mousepos)){
                Salir.setFillColor(sf::Color::Red);
            }else{
                Salir.setFillColor(sf::Color::White);
            }
            if(hitBoxCreditos.contains(mousepos)){
                Creditos.setFillColor(sf::Color::Red);
            }else{
                Creditos.setFillColor(sf::Color::White);
            }

            window.clear();
            window.draw(fondos);
            window.draw(nuevoJuego);
            window.draw(Creditos);
            window.draw(Salir);
            window.display();
        }
        return Heroe::Negro;
    }

Heroe Menu::elegirPersonaje(sf::RenderWindow& window){
    //Image de Fondo
    sf::Text Juego("Selecciona un Personaje", font, 80);
    Juego.setPosition(280, 140);
    sf::Texture fondo;
    fondo.loadFromFile("Imagenes/Menus.jpg");
    sf::Sprite fondoSprite(fondo);

    //Ajusta a la ventana

    float xventana = static_cast<float>(window.getSize().x);
    float yventana = static_cast<float>(window.getSize().y);
    float escalaX = xventana / fondo.getSize().x;
    float escalaY = yventana / fondo.getSize().y;

    fondoSprite.setScale(escalaX,escalaY);

    
    //Negro Imagen y Titulo
    sf::Texture Negro;
    Negro.loadFromFile("Imagenes/Negro.png");
    sf::Sprite Negros(Negro);
    Negros.setScale( 150.0f / Negro.getSize().x, 150.0f / Negro.getSize().y);

    Negros.setPosition(190, 380);
    sf::Text TextoNegro("Negro" , font, 40);
    TextoNegro.setPosition(210, 520);
    


    //Sifrino Imagen y Titulo
    sf::Texture Sifrino;
    Sifrino.loadFromFile("Imagenes/Sifrinos.png");
    sf::Sprite Sifrinos(Sifrino);
    Sifrinos.setPosition(660, 380);
    sf::Text TextoSifrino("Sifrino", font, 40);
    TextoSifrino.setPosition(680,520);
    Sifrinos.setScale( 150.0f / Sifrino.getSize().x, 150.0f / Sifrino.getSize().y);


    //Otaku Imagen y Titulo
    sf::Texture Otaku;
    Otaku.loadFromFile("Imagenes/Otaku.png");
    sf::Sprite Otakus(Otaku);
    Otakus.setPosition(910, 380);
    sf::Text TextoOtaku("Otaku", font, 40);
    TextoOtaku.setPosition(920, 520);
    Otakus.setScale( 150.0f / Otaku.getSize().x, 150.0f / Otaku.getSize().y);

    //Fifas Imagen y Titulo
    
    sf::Texture Fifa;
    Fifa.loadFromFile("Imagenes/Fifas.png");
    sf::Sprite Fifas(Fifa);
    Fifas.setPosition(440, 380);
    sf::Text TextoFifa("Fifas", font, 40);
    TextoFifa.setPosition(460, 520);
    Fifas.setScale( 150.0f / Fifa.getSize().x, 150.0f / Fifa.getSize().y);
    
    //Hitbox para cada imagen y titulo
    //Imagenes
    sf::FloatRect hitBoxNegroi = Negros.getGlobalBounds();
    sf::FloatRect hitBoxFifai = Fifas.getGlobalBounds();
    sf::FloatRect hitBoxSifrinoi = Sifrinos.getGlobalBounds();
    sf::FloatRect hitBoxOtakui = Otakus.getGlobalBounds();
    //Texto
    sf::FloatRect hitBoxNegrot = TextoNegro.getGlobalBounds();
    sf::FloatRect hitBoxFifat = TextoFifa.getGlobalBounds();
    sf::FloatRect hitBoxSifrinot = TextoSifrino.getGlobalBounds();
    sf::FloatRect hitBoxOtakut = TextoOtaku.getGlobalBounds();







    while(window.isOpen()){

        sf::Event event;
        sf::Vector2f mousepos = (sf::Vector2f)sf::Mouse::getPosition(window);


        while (window.pollEvent(event))
            {
            if (event.type == sf::Event::Closed){
                window.close();

            }
                if (event.type == sf::Event::MouseButtonReleased){

                    if (event.mouseButton.button == sf::Mouse::Left)
                    {

                        sf::Vector2f ClickPos((float)event.mouseButton.x, (float)event.mouseButton.y);

                        if(hitBoxNegroi.contains(ClickPos) || hitBoxNegrot.contains(ClickPos)){
                            //SeleccionNegro.play();
                            //while(SeleccionNegro.getStatus() == sf::Sound::Playing){}
                            return Heroe::Negro;
                        }
                        if(hitBoxFifai.contains(ClickPos) || hitBoxFifat.contains(ClickPos)){
                            return Heroe::Fifas;
                        }
                        if(hitBoxSifrinoi.contains(ClickPos) || hitBoxSifrinot.contains(ClickPos)){
                            return Heroe::Sifrino;
                        }
                        if(hitBoxOtakui.contains(ClickPos) || hitBoxOtakut.contains(ClickPos)){
                            return Heroe::Otaku;
                        }
                    }
                }
            }

        if(hitBoxNegroi.contains(mousepos) || hitBoxNegrot.contains(mousepos)){
            Negros.setColor(sf::Color::Red);
            TextoNegro.setFillColor(sf::Color::Red);
        }
        else{
            Negros.setColor(sf::Color::White);
            TextoNegro.setFillColor(sf::Color::White);
        }
        if(hitBoxFifai.contains(mousepos) || hitBoxFifat.contains(mousepos)){
            Fifas.setColor(sf::Color::Red);
            TextoFifa.setFillColor(sf::Color::Red);
        }
        else{
            Fifas.setColor(sf::Color::White);
            TextoFifa.setFillColor(sf::Color::White);
        }
        if(hitBoxSifrinoi.contains(mousepos) || hitBoxSifrinot.contains(mousepos)){
            Sifrinos.setColor(sf::Color::Red);
            TextoSifrino.setFillColor(sf::Color::Red);
        }
        else{
            Sifrinos.setColor(sf::Color::White);
            TextoSifrino.setFillColor(sf::Color::White);
        }
        if(hitBoxOtakui.contains(mousepos) || hitBoxOtakut.contains(mousepos)){
            Otakus.setColor(sf::Color::Red);
            TextoOtaku.setFillColor(sf::Color::Red);
        }
        else{
            Otakus.setColor(sf::Color::White);
            TextoOtaku.setFillColor(sf::Color::White);
        }

        window.clear();
        window.draw(fondoSprite);
        window.draw(Juego);
        window.draw(Negros);
        window.draw(TextoNegro);
        window.draw(Sifrinos);
        window.draw(TextoSifrino);
        window.draw(Otakus);
        window.draw(TextoOtaku);
        window.draw(Fifas);
        window.draw(TextoFifa);
        window.display();
    }
    return Heroe::Negro;
}