#ifndef PROYECTO_EJERCICIO_H
#define PROYECTO_EJERCICIO_H
#include "Borrador/CMET.h"
#include "Librerias.h"

/**
 * @file Ejercicio.h
 * Declaration of the Ejercicio class.
 */

/**
 * The Ejercicio class serves as the base class for different types of exercises in the project.
 */
class Ejercicio {
protected:
    string nombre; // nombre del tipo de ejercicio
    float FCE; // frecuencia cardiaca por ejercicio
    float CQE; // calorias quemadas por ejercicio
    string frecuencia; // frecuencia en la que realizamos el ejercicio (cada dia, semana, etc)
    vector<int> frecueciasCardiacas;

public:
    // Destructor
    /**
     * Virtual destructor for the Ejercicio class.
     * Provides a base class type to allow proper destruction of derived class objects.
     */
    virtual ~Ejercicio() { cout << "Ejercicio destroyed" << endl; }

    // Pure virtual methods
    /**
     * Pure virtual method to calculate and set the Calorias Quemadas (CQ) and Frecuencia Cardiaca (FC) for the exercise.
     */
    virtual void hallar_CQ_FC() = 0;

    /**
     * Pure virtual method to take user input and set the attributes of the Ejercicio object.
     */
    virtual void ingresar_datos() = 0;

    /**
     * Pure virtual method to display information about the exercise.
     */
    virtual void mostrar_informacion() = 0;

    virtual void exportacion_informacion() = 0;

    /**
     * Getter method to retrieve the FCE (Frecuencia Cardiaca por Ejercicio).
     * @return The FCE value.
     */


    float getFCE() { return FCE; }

    float getCQE()  { return CQE; }
};

#endif //PROYECTO_EJERCICIO_H
