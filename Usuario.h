//
//

#ifndef PROYECTO_USUARIO_H
#define PROYECTO_USUARIO_H

#include "Ejercicio.h"

class Usuario {
private:
    // atributos
    string nombre;
    string apellido;
    int edad;
    string DNI;
    string genero;
    float peso, peso_objetivo,peso_inicial;
    float altura;
    float masa_muscular, masa_muscular_objetivo, masa_muscular_inicial;
    float grasa_coporal;
    vector<Ejercicio*> ejercicios;
    vector<float> historial_de_IMCS = {20,21,23,24,25};
    vector<float> historial_calorias_quemadas = {100.2, 200.5,500,300};

public:
    // constructores
    Usuario();
    Usuario(string nombre, string apellido, string genero, float peso, float peso_objetivo,float altura, string dni, float masa_muscular, float masa_muscular_objetivo, float grasa_coporal);
    // destructor
    ~Usuario();
    // metodos
    void agregar_ejercicio(Ejercicio* ejercicio);
    float calcular_IMC();
    float frecuencia_cardiaca_prom();
    void reporte_individual();
    void reporte_individual_exportacion();
    void meta_peso_objetivo();
    void meta_masa_muscular_objetivo();
    void calorias_quemadas_rango(float c, int n);
    string to_string_historial_calorias();
    string to_string_historial_imcs();
    // getters
    string const& getDNI() const;
    const string &getNombre() const;
    const string &getApellido() const;
    vector<float> &getHistorialCaloriasQuemadas();
    vector<Ejercicio *> &getEjercicios();
};




#endif //PROYECTO_USUARIO_H
