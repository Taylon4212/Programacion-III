#include <SFML/Graphics.hpp>
#include <iostream>
#include "Armas.hpp"
#include "Inventario.hpp"
#include <tuple>
#include <vector>
#pragma once

enum class Heroe{
    Sifrino,
    Otaku,
    Negro,
    Fifas
};

class Personaje {
private:
    int vida;
    bool vivo;
    int suerte;
    int inteligencia;
    int fuerza;
    Heroe tipo;
    std::tuple<Arma, int> arm;
    std::vector<Objeto> inventario;

public:
    //Constructor
    Personaje(Heroe nom);

    //Getters
    bool getVivo() const;
    int getVida() const;
    void ImprimirStats() const;
    Heroe getTipo() const;
    int getFuerza() const;
    int getInteligencia() const;
    int getSuerte() const;
    
    //Otros
    void RecogerArma(Arma a, int b);
    std::string TipotoString()const;
    void Curar(int v);
    void RecibirDanio(int d);

};


enum class Enem{
    Rata,
    Cucaracha,
    Saqueador,
    Perro,
};

class Enemigo{
private:
    int vida;
    bool vivo;
    std::tuple<ArmEne, int> arm;
    Enem tipo;

public:
    Enemigo(Enem x );
    bool getVivo() const;
    int getVida() const;
    std::string getNombre() const;
};