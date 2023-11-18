//
// Created by Guillermo Galvez on 15/11/2023.
//

#include "Flexibilidad.h"
Flexibilidad:: Flexibilidad(){}

Flexibilidad::  Flexibilidad(string nombre){
    this->nombre = nombre;
}

Flexibilidad::~Flexibilidad() {cout<<"Ejercicio de Flexibilidad destruido"<<endl;}

void Flexibilidad::ingresar_datos() {
    int duracion;
    string dificultad,frecuencia;
    do{
        cout<<"Ingrese la duración (minutos): ";cin>>duracion;
    } while (duracion<0);
    do{
        cout<<"Dificultad (fácil/media/díficil): "; cin>>dificultad;
        if (dificultad != "fácil" and dificultad != "media" and dificultad!= "díficil")
            cout << "La dificultad tiene que ser fácil, media o díficil. Ingrésela nuevamente. " <<endl;
    } while (dificultad!="fácil" and dificultad !="media" and dificultad !="díficil");

    do {
        cout << "Ingrese la frecuencia (diaria/interdiaria/semanal): "; cin >> frecuencia;
        if (frecuencia != "diaria" and frecuencia != "interdiaria" and frecuencia!= "semanal")
            cout << "La frecuencia tiene que ser diaria, interdiaria o semanal. Ingrésela nuevamente. "<<endl;
    } while(frecuencia != "diaria" and frecuencia != "interdiaria" and frecuencia!= "semanal");

    this->duracion=duracion;
    this->dificultad=dificultad;
    this ->frecuencia=frecuencia;

}

void Flexibilidad::mostrar_informacion() {
    cout << nombre << " durante " << duracion << " con una dificultad " << dificultad << " " <<frecuencia << "mente" << endl;
}
void Flexibilidad::hallar_CQ_FC() {
    if (nombre == "Yoga"){
        CQE = 0;
        FCE = 0;
    }
    else if (nombre == "Danza"){
        CQE = 0;
        FCE = 0;
    }
    else if (nombre == "Arte Marcial"){
        CQE = 0;
        FCE = 0;
    }
    else if (nombre == "Estiramientos"){
        CQE = 0;
        FCE = 0;
    }
}