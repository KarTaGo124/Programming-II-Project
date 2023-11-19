/**
 * @file Usuario.cpp
 * Implementation of the Usuario class.
 */

#include "Usuario.h"

Usuario:: Usuario() {}
Usuario::Usuario(string nombre, string apellido, string genero, float peso, float peso_objetivo,
                 float altura, string dni, float masa_muscular, float masa_muscular_objetivo, float grasa_coporal) {
    this->nombre = nombre;
    this->apellido = apellido;
    this->genero = genero;
    this->peso = peso;
    this->peso_inicial = peso;
    this->peso_objetivo = peso_objetivo;
    this->altura = altura;
    this->masa_muscular = masa_muscular;
    this->masa_muscular_inicial = masa_muscular;
    this->masa_muscular_objetivo = masa_muscular_objetivo;
    this->grasa_coporal = grasa_coporal;
    this->DNI = dni;
}

Usuario::~Usuario() {cout<<"Usuario destruido"<<endl;}


void Usuario::agregar_ejercicio(Ejercicio* ejercicio) {
    ejercicios.push_back(ejercicio);
}

float Usuario::calcular_IMC() {
    return peso / (pow(altura,2));
}

float Usuario::frecuencia_cardiaca_prom() {
    float promedio = 0;
    for (int i = 0; i < ejercicios.size(); i++) {
        promedio += ejercicios[i]->getFCE();
    }
    return promedio = promedio / ejercicios.size();

}

void Usuario::reporte_individual() {
    cout << "----------------------------------------" << endl << "Reporte Individual de " <<
    nombre << " " << apellido << endl;
    for (auto i: ejercicios){
        i->mostrar_informacion();
    }
    for (auto i: historial_de_IMCS){
        cout<<"Indice de masa corporal : "<<i+1<< calcular_IMC()<<endl;
    }
    cout<<"Frecuencia cardiaca promedio: "<< frecuencia_cardiaca_prom()<<endl;
}

void Usuario::reporte_individual_exportacion() {
    ofstream archivo("../ReporteGeneral.txt",ios::out);
    archivo<< "----------------------------------------" << endl << "Reporte Individual de " <<
           nombre << " " << apellido << endl;
    archivo.close();
    for (auto i: ejercicios){
        i->exportacion_informacion();
    }
    archivo.open("../ReporteGeneral.txt",ios::app);
    for (int i = 0; i < historial_de_IMCS.size(); i++){
        archivo<<"Indice de masa corporal " + to_string(i+1) + ": " +to_string(historial_de_IMCS[i]) <<endl;
    }
    archivo<<"Frecuencia cardiaca promedio: "<< to_string(frecuencia_cardiaca_prom())<<endl;
    archivo.close();

}

void Usuario::meta_peso_objetivo() {
    if (peso_inicial < peso_objetivo) {
        if (peso >= peso_objetivo)
            cout << "--------Has alcanzado tu peso objetivo, Felicitaciones.--------" << endl;
    }

    else if(peso_inicial > peso_objetivo){
        if(peso <= peso_objetivo)
            cout<<"-------Has alcanzado tu peso objetivo, Felicitaciones.--------"<<endl;
    }
}

void Usuario::meta_masa_muscular_objetivo() {
    if (masa_muscular_inicial < masa_muscular_objetivo) {
        if (masa_muscular >= peso_objetivo)
            cout << "--------Has alcanzado tu masa muscular objetivo, Felicitaciones.--------" << endl;
    }

    else if(masa_muscular_inicial > masa_muscular_objetivo){
        if(masa_muscular <= masa_muscular_objetivo)
            cout<<"-------Has alcanzado tu masa muscular objetivo, Felicitaciones.--------"<<endl;
    }
}

void Usuario::calorias_quemadas_rango(float c, int n) {
    for (int i = 0; i < n-1; i++) {
        historial_calorias_quemadas.push_back(c * ((100-(rand()%10+1))/100));
    }
}

string Usuario::to_string_historial_calorias() {
    string texto;
    for (int i = 0; i < historial_calorias_quemadas.size(); i++) {
        texto += to_string(historial_calorias_quemadas[i]) + " ";
    }
    return texto;
}

string Usuario::to_string_historial_imcs() {
    string texto;
    for (int i = 0; i < historial_de_IMCS.size(); i++) {
        texto += to_string(historial_de_IMCS[i]) + " ";
    }
    return texto;
}

string const& Usuario::getDNI() const {
    return DNI;
}

const string &Usuario::getNombre() const {
    return nombre;
}

const string &Usuario::getApellido() const {
    return apellido;
}

vector<float> &Usuario::getHistorialCaloriasQuemadas() {
    return historial_calorias_quemadas;
}

vector<Ejercicio *> &Usuario::getEjercicios()  {
    return ejercicios;
}



