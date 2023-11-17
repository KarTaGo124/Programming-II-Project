//
// Created by Guillermo Galvez on 15/11/2023.
//

#ifndef PROYECTO_CARDIO_H
#define PROYECTO_CARDIO_H

#include "Ejercicio.h"
class Cardio : public Ejercicio{
private:
    // atributos
    int duracion; // minutos
    int velocidad; // metros por segundo
public:
    // constructor
    Cardio();
    // destructor
    ~Cardio();
    // metodos redefinidos
    void hallar_CQ_FC() override;
};


#endif //PROYECTO_CARDIO_H
