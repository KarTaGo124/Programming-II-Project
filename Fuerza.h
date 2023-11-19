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
    int repeticiones;  ///< The number of repetitions for the strength exercise.
    int series;        ///< The number of series for the strength exercise.
    float peso;        ///< The weight used for the strength exercise.

public:
    // Constructors
    /**
     * Parameterized constructor for the Fuerza class.
     * Initializes the Fuerza object with the given name.
     * @param nombre The name of the strength exercise.
     */
    Fuerza(string nombre);

    /**
     * Default constructor for the Fuerza class.
     */
    Fuerza();

    Fuerza(string nombre);

    /**
     * Takes user input to set the attributes of the Fuerza object.
     * Overrides the corresponding method in the base class (Ejercicio).
     */
    void ingresar_datos() override;

    void exportacion_informacion() override;

    void hallar_CQ_FC() override;

    /**
     * Virtual destructor for the Fuerza class.
     * Provides a base class type to allow proper destruction of derived class objects.
     */
    virtual ~Fuerza();

};

#endif //PROYECTO_FUERZA_H
