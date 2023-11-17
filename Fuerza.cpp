//
// Created by Guillermo Galvez on 15/11/2023.
//

#include "Fuerza.h"
Fuerza::Fuerza() {}
Fuerza::~Fuerza() noexcept {}

void Fuerza::hallar_CQ_FC() {
    if (nombre == "Press Banca"){
        CQE = 0;
        FCE = 0;
    }
    else if (nombre == "Peso Muerto"){
        CQE = 0;
        FCE = 0;
    }
    else if (nombre == "Sentadillas"){
        CQE = 0;
        FCE = 0;
    }
    else if (nombre == "Dominadas"){
        CQE = 0;
        FCE = 0;
    }
    else if (nombre == "Flexiones"){
        CQE = 0;
        FCE = 0;
    }
}