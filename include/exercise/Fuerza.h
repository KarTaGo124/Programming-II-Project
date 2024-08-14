#ifndef PROYECTO_FUERZA_H
#define PROYECTO_FUERZA_H
#include "Ejercicio.h"

/**
 * @file Fuerza.h
 * Declaration of the Fuerza class, derived from the Ejercicio class.
 */

/**
 * The Fuerza class represents a strength exercise, inheriting from the Ejercicio class.
 */
class Fuerza : public Ejercicio {
private:
    // atributos
    int repeticiones; // numero de repeticiones en una seria
    int series; // numero de series
    float peso; // peso (kg) que usa en el ejercicio
public:
    // constructores
    Fuerza();
    Fuerza(string nombre);
    // destructor
    virtual ~Fuerza();
    // metodos redefinidos
    void ingresar_datos() override;
    void mostrar_informacion() override;
    void exportacion_informacion() override;
    void hallar_CQ_FC(double TBM, int FCM) override;


};

#endif //PROYECTO_FUERZA_H
