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
    int repeticiones;
    int series;
    float tempEjercicio;
    int pesa; // peso con el que realizamos el ejercicio de fuerza
public:

    Fuerza();

    Fuerza(string nombre);

    void ingresar_datos() override;
    /**
     * Displays information about the Fuerza exercise.
     * Overrides the corresponding method in the base class (Ejercicio).
     */
    void mostrar_informacion() override;

    void exportacion_informacion() override;

    void hallar_CQ_FC() override;

    /**
     * Virtual destructor for the Fuerza class.
     * Provides a base class type to allow proper destruction of derived class objects.
     */
    virtual ~Fuerza();

};

#endif //PROYECTO_FUERZA_H
