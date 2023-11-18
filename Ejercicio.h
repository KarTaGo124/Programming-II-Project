//
// Created by Guillermo Galvez on 15/11/2023.
//

#ifndef PROYECTO_EJERCICIO_H
#define PROYECTO_EJERCICIO_H

#include "Librerias.h"

class Ejercicio {
protected:
    // atributos
    string nombre; // nombre del tipo de ejercicio
    int FCE; // frecuencia cardiaca por ejercicio
    int CQE; // calorias quemadas por ejercicio
    string frecuencia; // frecuencia en la que realizamos el ejercicio (cada dia, semana, etc)
public:
    // destructor
    virtual ~Ejercicio() {cout<<"Ejercicio destruido"<<endl;}
    // metodo virtual puro
    virtual void hallar_CQ_FC() = 0;
    virtual void ingresar_datos() = 0;
    virtual void mostrar_informacion() = 0;


    int getFCE(){return FCE;}

};


#endif //PROYECTO_EJERCICIO_H
