//
//

#ifndef PROYECTO_USUARIO_H
#define PROYECTO_USUARIO_H

#include "Ejercicio.h"
/**
 * @file Usuario.h
 * Declaration of the Usuario class.
 */


/**
 * The Usuario class represents a user with attributes such as name, gender, weight, and exercise history.
 */
class Usuario {
private:
    string nombre;                       ///< The name of the user.
    string apellido;                     ///< The last name of the user.
    int edad;                            ///< The age of the user.
    string DNI;                          ///< The DNI (Documento Nacional de Identidad) of the user.
    string genero;                       ///< The gender of the user.
    float peso, peso_objetivo,peso_inicial;           ///< The weight and weight goal of the user.
    float altura;                        ///< The height of the user.
    float masa_muscular;                 ///< The muscular mass of the user.
    float grasa_coporal;                 ///< The body fat percentage of the user.
    vector<Ejercicio*> ejercicios;       ///< List of exercises performed by the user.
    vector<float> historial_de_IMCS;    ///< Historical weight records of the user.
    vector<float> historial_calorias_quemadas = {100.2, 200.5,500,300};  ///< Historical calorie-burning records of the user.
    vector<float> historial_masa_muscular;     ///< Historical muscular mass records of the user.

public:
    /**
     * Default constructor for the Usuario class.
     */
    Usuario();

    /**
     * Parameterized constructor for the Usuario class.
     * Initializes the Usuario object with provided attributes.
     * @param nombre          The name of the user.
     * @param apellido        The last name of the user.
     * @param genero          The gender of the user.
     * @param peso            The weight of the user.
     * @param peso_objetivo   The weight goal of the user.
     * @param altura          The height of the user.
     * @param dni             The DNI (Documento Nacional de Identidad) of the user.
     * @param masa_muscular   The muscular mass of the user.
     * @param grasa_coporal   The body fat percentage of the user.
     */
    Usuario(string nombre, string apellido, string genero, float peso, float peso_objetivo,
            float altura, string dni, float masa_muscular, float grasa_coporal);

    // Destructor
    /**
     * Destructor for the Usuario class.
     * Displays a message when an instance of the Usuario class is destroyed.
     */
    ~Usuario();

    // Methods

    /**
     * Adds an exercise to the user's exercise list.
     * @param ejercicio A pointer to the Ejercicio object to be added.
     */
    void agregar_ejercicio(Ejercicio* ejercicio);

    /**
     * Calculates the Body Mass Index (BMI) of the user.
     * @return The calculated BMI value.
     */
    float calcular_IMC();

    /**
     * Calculates the average heart rate during exercises.
     * @return The average heart rate.
     */
    float frecuencia_cardiaca_prom();

    /**
     * Generates an individual report for the user, displaying information about each exercise.
     */
    void reporte_individual();

    void reporte_individual_exportacion();

    void peso_ideal();

    void calorias_quemadas_rango(float c, int n);

    string to_string_historial_calorias();

    /**
     * Getter function for the DNI attribute.
     * @return A constant reference to the DNI attribute.
     */
    string const& getDNI() const;

    /**
     * Getter function for the nombre attribute.
     * @return A constant reference to the nombre attribute.
     */
    const string &getNombre() const;

    /**
     * Getter function for the apellido attribute.
     * @return A constant reference to the apellido attribute.
     */
    const string &getApellido() const;

    vector<float> &getHistorialCaloriasQuemadas();

    vector<Ejercicio *> &getEjercicios();
};




#endif //PROYECTO_USUARIO_H
