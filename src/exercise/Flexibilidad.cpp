//
//

#include "../../include/exercise/Flexibilidad.h"
Flexibilidad:: Flexibilidad(){}
Flexibilidad::Flexibilidad(string nombre){this->nombre = nombre;}

Flexibilidad::~Flexibilidad() {cout<<"Ejercicio de Flexibilidad destruido"<<endl;}

void Flexibilidad::ingresar_datos() {
    int duracion;
    string dificultad,frecuencia;
    do{
        cout<<"Ingrese la duración (minutos): ";cin>>duracion;
    } while (duracion<=0);
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
    cout << nombre << " durante " << duracion << " minutos con una dificultad " << dificultad << " " <<frecuencia << "mente" << endl;
    cout <<"Calorias quemadas : "<<CQE<<endl;
}

void Flexibilidad::exportacion_informacion() {
    ofstream archivo("../docs/ReporteGeneral.txt",ios::app);
    archivo << nombre << " durante " << duracion << " minutos con una dificultad " << dificultad << " " <<frecuencia << "mente" << endl;
    archivo <<"Calorias quemadas : "<<CQE<<endl;
    archivo.close();
}

void Flexibilidad::hallar_CQ_FC(double TBM, int FCM) {
    if (dificultad == "fácil")
        FA = 0.2;
    else if (dificultad == "media")
        FA = 0.3;
    else
        FA = 0.5;
    if (nombre == "Yoga") {
        CQE = 0.001 * duracion * FA * TBM;
        FCE = FCM * 0.4;
    } else if (nombre == "Danza") {
        CQE = 0.03 * duracion * FA * TBM;
        FCE = FCM * (rand() % 15 + 55) / 100;
    } else if (nombre == "Arte Marcial") {
        CQE = 0.02 * duracion * FA * TBM;
        FCE = FCM * (rand() % 10 + 50) / 100;
    } else if (nombre == "Estiramientos") {
        CQE = 0.002 * duracion * FA * TBM;
        FCE = FCM * 0.3;
    }
    if (frecuencia == "diaria")
        CQE *= 7;
    else if (frecuencia == "interdiaria")
        CQE *= 3.5;
    else if (frecuencia == "semanal")
        CQE *= 1;
}

