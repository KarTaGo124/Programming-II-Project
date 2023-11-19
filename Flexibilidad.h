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
    int duracion{};       ///< The duration of the flexibility exercise.
    string dificultad;  ///< The difficulty level of the flexibility exercise.
public:
    Flexibilidad();
    Flexibilidad(string nombre);
    virtual ~Flexibilidad();

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

    void exportacion_informacion() override;

    void hallar_CQ_FC() override;
};

#endif //PROYECTO_FLEXIBILIDAD_H
