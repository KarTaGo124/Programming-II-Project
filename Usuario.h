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



    string genero;

    float peso, peso_objetivo,altura, masa_muscular;

    vector<Ejercicio*> actividades;

    vector<float> historial_de_pesos;

    vector<float> historial_calorias_quemadas;

    vector<float> historial_masa_muscular;

public:
    // constructores
    Usuario();
    Usuario(string _n);
    Usuario(string n,string g,string a,int al,float macular, float p, float p_o);

    void validar_usuario();

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
