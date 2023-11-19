//
// Created by Guillermo Galvez on 15/11/2023.
//

#ifndef PROYECTO_USUARIO_H
#define PROYECTO_USUARIO_H

#include "Ejercicio.h"

class Usuario {
private:
    string nombre;
    string apellido;
    int edad;
    string DNI;
    string genero;
    float peso, peso_objetivo,altura,masa_muscular,grasa_coporal;
    vector<Ejercicio*> ejercicios;
    vector<float> historial_de_pesos;
    vector<float> historial_calorias_quemadas;
    vector<float> historial_masa_muscular;

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

    // destructores
    ~Usuario();

    //metodos
    void validar_usuario(vector<Usuario*> &usuarios);

    void agregar_ejercicio(Ejercicio* ejercicio);

    float calcular_IMC();

    float frecuencia_cardiaca_prom();

    void reporte_individual();

    // getters

    string const& getDNI() const;

    const string &getNombre() const;

    const string &getApellido() const;



};


#endif //PROYECTO_USUARIO_H
