#ifndef PROYECTO_FLEXIBILIDAD_H
#define PROYECTO_FLEXIBILIDAD_H

#include "Ejercicio.h"

/**
 * @file Flexibilidad.h
 * Declaration of the Flexibilidad class, derived from the Ejercicio class.
 */

/**
 * The Flexibilidad class represents a flexibility exercise, inheriting from the Ejercicio class.
 */
class Flexibilidad : public Ejercicio{
private:
    int duracion;       ///< The duration of the flexibility exercise.
    string dificultad;  ///< The difficulty level of the flexibility exercise.


public:
    // Constructors
    /**
     * Default constructor for the Flexibilidad class.
     */
    Flexibilidad();

    /**
     * Parameterized constructor for the Flexibilidad class.
     * Initializes the Flexibilidad object with the given name.
     * @param nombre The name of the flexibility exercise.
     */
    Flexibilidad(string nombre);

    /**
     * Virtual destructor for the Flexibilidad class.
     * Provides a base class type to allow proper destruction of derived class objects.
     */
    virtual ~Flexibilidad() ;

    // Overridden methods
    /**
     * Calculates and sets the Calorias Quemadas (CQ) and Frecuencia Cardiaca (FC) for the flexibility exercise.
     * Overrides the corresponding method in the base class (Ejercicio).
     */
    void hallar_CQ_FC() override;

    /**
     * Takes user input to set the attributes of the Flexibilidad object.
     * Overrides the corresponding method in the base class (Ejercicio).
     */
    void ingresar_datos() override;

    /**
     * Displays information about the Flexibilidad exercise.
     * Overrides the corresponding method in the base class (Ejercicio).
     */
    void mostrar_informacion() override;
};

#endif //PROYECTO_FLEXIBILIDAD_H
