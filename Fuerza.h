//
// Created by Guillermo Galvez on 15/11/2023.
//

#ifndef PROYECTO_FUERZA_H
#define PROYECTO_FUERZA_H

#include "Ejercicio.h"
class Fuerza : public Ejercicio{
private:
    // atributos
    int repeticiones;
    int series;
    int peso; // peso con el que realizamos el ejercicio de fuerza
public:
    // constructor
    Fuerza();
    // destructor
    ~Fuerza();
    // metodos redefinidos
    void hallar_CQ_FC() override;
};


#endif //PROYECTO_FUERZA_H
