//
//

#ifndef PROYECTO_USUARIO_H
#define PROYECTO_USUARIO_H

#include "../exercise/Ejercicio.h"

class Usuario {
private:
    // atributos
    string nombre;
    string apellido;
    int edad;
    string DNI;
    string genero;
    float altura;
    float peso, peso_objetivo,peso_inicial;
    float masa_muscular, masa_muscular_objetivo;
    double TMB; // tasa metabolica basal
    int FCM; // frecuencia cardiaca maxima
    vector<Ejercicio*> ejercicios;
    vector<double> historial_de_IMCS;
    vector<double> historial_calorias_quemadas;
public:
    // constructores
    Usuario();
    Usuario(string nombre, string apellido, string genero,int edad, float peso, float peso_objetivo,float altura, string dni, float masa_muscular, float masa_muscular_objetivo);
    // destructor
    ~Usuario();
    // metodos
    void agregar_ejercicio(Ejercicio* ejercicio);
    float calcular_IMC();
    float frecuencia_cardiaca_prom();
    void reporte_individual();
    void reporte_individual_exportacion();
    void meta_peso();
    void meta_masa_muscular();
    void calorias_quemadas_rango(double c, int n);
    void actulizaciones_imcs(int n);
    string to_string_historial_calorias();
    string to_string_historial_imcs();
    // getters
    string const& getDNI() const;
    const string &getNombre() const;
    const string &getApellido() const;
    vector<double> &getHistorialCaloriasQuemadas();
    vector<Ejercicio *> &getEjercicios();
    double getTmb() ;
    int getFcm() ;

    float getMasaMuscular() const;

    void setMasaMuscular(float masaMuscular);

    float getPesoObjetivo() const;

    void setPesoObjetivo(float pesoObjetivo);

    float getPeso() const;

    void setPeso(float peso);
};




#endif //PROYECTO_USUARIO_H
