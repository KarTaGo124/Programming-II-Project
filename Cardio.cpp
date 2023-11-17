//
// Created by Guillermo Galvez on 15/11/2023.
//

#include "Cardio.h"
Cardio::Cardio() {}
Cardio::~Cardio() noexcept {}

void Cardio::hallar_CQ_FC() {
    if (nombre == "Correr"){
        CQE = 0;
        FCE = 0;
    }
    else if (nombre == "Ciclismo"){
        CQE = 0;
        FCE = 0;
    }
    else if (nombre == "Nadar"){
        CQE = 0;
        FCE = 0;
    }
    else if (nombre == "Saltar Cuerda"){
        CQE = 0;
        FCE = 0;
    }
}