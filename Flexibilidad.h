//
// Created by Guillermo Galvez on 15/11/2023.
//

#ifndef PROYECTO_FLEXIBILIDAD_H
#define PROYECTO_FLEXIBILIDAD_H

#include "Ejercicio.h"
class Flexibilidad : public Ejercicio{
private:
    // atributos
    int duracion;
    string dificultad;
public:
    // constructor
    Flexibilidad();
    // destructor
    virtual ~Flexibilidad() ;
    // metodos redefinidos
    void hallar_CQ_FC() override;

};


#endif //PROYECTO_FLEXIBILIDAD_H
