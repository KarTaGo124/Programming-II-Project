//
// Created by Guillermo Galvez on 15/11/2023.
//

#include "Fuerza.h"
Fuerza::Fuerza() {}
Fuerza:: Fuerza(string nombre){
    this-> nombre = nombre;
}


Fuerza::~Fuerza() {cout<<"Ejercicio de Fuerza destruido"<<endl;}

void Fuerza:: ingresar_datos(){
    int repeticiones;
    int series;
    float peso;
    string frecuencia;
    do{
        cout<<"Ingrese el número de repeticiones: ";cin>>repeticiones;

    } while (repeticiones<0);

    do{
        cout<<"Ingrese el número de series: ";cin>>series;
    } while (series<0);

    do{
        cout<<"Ingrese el peso que usa para el ejercicio (kg): ";cin>>peso;
    } while (peso<0);

    do {
        cout << "Ingrese la frecuencia (diaria/interdiaria/semanal): "; cin >> frecuencia;
        if (frecuencia != "diaria" and frecuencia != "interdiaria" and frecuencia!= "semanal")
            cout << "La frecuencia tiene que ser diaria, interdiaria o semanal. Ingrésela nuevamente. "<<endl;
    } while(frecuencia != "diaria" and frecuencia != "interdiaria" and frecuencia!= "semanal");


    this ->repeticiones=repeticiones;
    this ->series=series;
    this ->peso=peso;
    this ->frecuencia=frecuencia;

}
void Fuerza:: mostrar_informacion(){
    cout <<"Realiza " << repeticiones << " repeticiones de " << nombre << " en " << series << " series con un peso de "<<peso<<" Kg "<< frecuencia << "mente" << endl;
}

void Fuerza::hallar_CQ_FC() {
    if (nombre == "Press Banca"){
        CQE = 0;
        FCE = 0;
    }
    else if (nombre == "Peso Muerto"){
        CQE = 0;
        FCE = 0;
    }
    else if (nombre == "Sentadillas"){
        CQE = 0;
        FCE = 0;
    }
    else if (nombre == "Dominadas"){
        CQE = 0;
        FCE = 0;
    }
    else if (nombre == "Flexiones"){
        CQE = 0;
        FCE = 0;
    }
}