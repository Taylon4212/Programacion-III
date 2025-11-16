#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Heroe.hpp"
#include "Armas.hpp"
#include "Inventario.hpp"
#include <tuple>
#include <vector>

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
    Personaje(Heroe nom);
    bool getVivo() const;
    int getVida() const;
    Heroe getTipo() const;
    void ImprimirStats() const;
    void RecogerArma(Arma a, int b);
    std::string TipotoString()const;
    void Curar(int v);
    void RecibirDanio(int d);
    int getFuerza() const;
    int getInteligencia() const;
    int getSuerte() const;

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