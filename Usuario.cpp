//
// Created by Guillermo Galvez on 15/11/2023.
//

#include "Usuario.h"


Usuario:: Usuario(){}

Usuario:: Usuario(string n,string g,string a,int al,float macular, float p, float p_o){

    this->nombre=n;
    this->genero=g;
    this->peso=p;
    this->peso_objetivo=p_o;
    this->apellido=a;
    this ->altura=al;
    this ->masa_muscular=macular;

}
Usuario:: Usuario(string _n):nombre(_n){}

void Usuario::validar_usuario(vector<Usuario*> &usuarios) {
    do {
        cout << "Ingrese el nombre: ";
        cin >> nombre;

        cout << "Ingrese el género (Masculino/Femenino): ";
        cin >> genero;

        cout << "Ingrese el peso: ";
        cin >> peso;

        cout << "Ingrese el peso objetivo: ";
        cin >> peso_objetivo;

        cout << "Ingrese el DNI (8 dígitos): ";
        cin >> DNI;

        if (nombre.length() == 0) {
            cout << "Error: El nombre no puede estar vacio." << endl;
            continue;
        }

        if (genero != "Masculino" && genero != "Femenino") {
            cout << "Error: El genero debe ser 'Masculino' o 'Femenino'." << endl;
            continue;
        }

        if (peso <= 0 || peso_objetivo <= 0) {
            cout << "Error: El peso y el peso objetivo deben ser valores positivos." << endl;
            continue;
        }

        if (DNI.length() != 8) {
            cout << "Error: El DNI debe tener exactamente 8 numeros." << endl;
            continue;
        }

        bool dniExistente = false;
        for (const auto &i : usuarios) {
            if (i->getDNI() == DNI) {
                dniExistente = true;
                break;
            }
        }

        if (dniExistente) {
            cout << "Error: El DNI ya existe en la base de datos." << endl;
            continue;
        }

        break;

    } while (true);

    cout << "Usuario validado correctamente." << endl;
}

void Usuario::  agregar_ejercicio(Ejercicio* ejercicio){
    ejercicios.push_back(ejercicio);
}

float Usuario:: calcular_IMC(){
    return peso/(pow(altura,2));
}

float Usuario:: frecuencia_cardiaca_prom(){
    float promedio=0;
    for (int i = 0; i < ejercicios.size() ;++i) {
            promedio+=ejercicios[i]->getFCE();
    }
    return promedio=promedio/ejercicios.size();

}

void Usuario::reporte_individual() {
    // lista de ejercicios
    cout << "Reporte Individiual de " << nombre << " " << apellido << endl << "----------------------------------------" << endl;
    for (auto i: ejercicios){
        i->mostrar_informacion();
    }
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

Usuario::~Usuario() {cout<<"Usuario destruido"<<endl;}