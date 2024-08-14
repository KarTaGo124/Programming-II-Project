/**
 * @file Usuario.cpp
 * Implementation of the Usuario class.
 */

#include "../../include/user/Usuario.h"

Usuario:: Usuario() {}
Usuario::Usuario(string nombre, string apellido, string genero,int edad, float peso, float peso_objetivo,
                 float altura, string dni, float masa_muscular, float masa_muscular_objetivo) {
    this->nombre = nombre;
    this->apellido = apellido;
    this->genero = genero;
    this->edad=edad;
    this->altura = altura;
    this->peso = peso;
    this->peso_inicial = peso;
    this->peso_objetivo = peso_objetivo;
    this->masa_muscular = masa_muscular;
    this->masa_muscular_objetivo = masa_muscular_objetivo;
    this->DNI = dni;

    if (genero=="Masculino")
        this->TMB = 10*(this->peso) + 6.25*(this->altura) - 5*(edad) + 5;
    if (genero=="Femenino")
        this->TMB = 10*(this->peso) + 6.25*(this->altura) - 5*(edad) - 161;
    this->FCM = 220 - edad;
}

Usuario::~Usuario() {
    cout<<"Usuario destruido"<<endl; for (auto i: ejercicios) delete i;
}


void Usuario::agregar_ejercicio(Ejercicio* ejercicio) {
    ejercicios.push_back(ejercicio);
}

float Usuario::calcular_IMC() {
    return peso / (pow(altura/100.0,2));
}

float Usuario::frecuencia_cardiaca_prom() {
    float promedio = 0;
    for (int i = 0; i < ejercicios.size(); i++) {promedio += ejercicios[i]->getFCE();}
    promedio = promedio / ejercicios.size();
    return promedio;
}

void Usuario::reporte_individual() {
    cout << "----------------------------------------" << endl << "Reporte Individual de " <<
    nombre << " " << apellido << endl;
    for (auto i: ejercicios){
        i->mostrar_informacion();
    }
    cout << "IMC inicial: " << peso_inicial/pow(altura/100,2) << endl;
    for (int i = 0; i < historial_de_IMCS.size(); i++){
        cout <<"Indice de masa corporal " << i+1 << + ": " << historial_de_IMCS[i] <<endl;
    }
    cout<<"Frecuencia cardiaca promedio: "<< frecuencia_cardiaca_prom()<<endl;
}

void Usuario::reporte_individual_exportacion() {
    ofstream archivo("../docs/ReporteGeneral.txt",ios::app);
    archivo<< "----------------------------------------" << endl << "Reporte Individual de " <<
           nombre << " " << apellido << endl;
    for (auto i: ejercicios){
        i->exportacion_informacion();
    }
    archivo << "IMC inicial: " << peso_inicial/pow(altura/100,2) << endl;
    for (int i = 0; i < historial_de_IMCS.size(); i++){
        archivo<<"Indice de masa corporal " << i+1 << + ": " << historial_de_IMCS[i] <<endl;
    }
    archivo<<"Frecuencia cardiaca promedio: "<< frecuencia_cardiaca_prom()<<endl;
    archivo.close();

}

void Usuario::meta_peso() {
    if (peso_inicial < peso_objetivo) {
        cout << "-------Su meta es subir de peso.--------" << endl;
        if (peso_objetivo - peso >0)
            cout << "-----Restante para llegar al peso objetivo " << peso_objetivo - peso << "-----" << endl;
        if (peso >= peso_objetivo) {
            cout << "-------Has alcanzado o superado tu peso objetivo, Felicitaciones.--------" << endl;
        }
    }
    else {
        cout << "-------Su meta es bajar de peso.--------" << endl;
        if (peso - peso_objetivo > 0)
            cout << "-----Restante para llegar al peso objetivo " << peso - peso_objetivo << "-----" << endl;
        if (peso <= peso_objetivo) {
            cout << "-------Has alcanzado o superado tu peso objetivo, Felicitaciones.--------" << endl;
        }
    }


}
void Usuario::meta_masa_muscular(){
    if (masa_muscular <= masa_muscular_objetivo)
        cout << "-----Restante para llegar a la masa muscular objetivo " << abs(masa_muscular - masa_muscular_objetivo) << "-----" << endl;
    if (masa_muscular_objetivo <= masa_muscular) {
        cout << "-------Has alcanzado o superado tu masa muscular objetivo, Felicitaciones.--------" << endl;
    }
}


void Usuario::calorias_quemadas_rango(double c, int n) {
    for (int i = 0; i < n - 1; i++){
        double variacion = (rand() % 21 + 90) / 100.0;
        historial_calorias_quemadas.push_back(c * variacion);
    }
}

void Usuario::actulizaciones_imcs(int n) {
    double imc;
    for (int i = n; i > 0 ; i--) {
        peso -= historial_calorias_quemadas[historial_calorias_quemadas.size()-n] / 15000.0;
        imc = peso/pow(altura/100.0,2);
        historial_de_IMCS.push_back(imc);
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

vector<double> &Usuario::getHistorialCaloriasQuemadas() {
    return historial_calorias_quemadas;
}

vector<Ejercicio *>& Usuario::getEjercicios()  {
    return ejercicios;
}

double Usuario::getTmb()  {
    return TMB;
}

int Usuario::getFcm()  {
    return FCM;
}

float Usuario::getMasaMuscular() const {
    return masa_muscular;
}

void Usuario::setMasaMuscular(float masaMuscular) {
    masa_muscular += masaMuscular;
}

float Usuario::getPesoObjetivo() const {
    return peso_objetivo;
}

void Usuario::setPesoObjetivo(float pesoObjetivo) {
    peso_objetivo = pesoObjetivo;
}

float Usuario::getPeso() const {
    return peso;
}

void Usuario::setPeso(float peso) {
    Usuario::peso = peso;
}



