#include <iostream>
#include <vector>
#include "escenarios.hpp"
#pragma once

class Historia{
    private:

        std::vector<Escena*> Lineal;

    public:

        Historia();
        ~Historia();
        const std::vector<Escena*>& GetEscena() const;

};