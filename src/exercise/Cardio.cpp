//
//

#include "../../include/exercise/Cardio.h"

Cardio::Cardio() {}
Cardio:: Cardio(string nombre){this->nombre = nombre;}

Cardio::~Cardio() {cout<<"Ejercicio de Cardio destruido"<<endl;}

void Cardio::ingresar_datos() {
    float velocidad,duracion;
    string frecuencia;
    do {
        if (nombre != "Saltar Cuerda")
            cout << "Ingrese la velocidad (kilometros por hora): ";
        else
            cout << "Ingrese la velocidad (saltos por minuto): ";
        cin >> velocidad;
        if (velocidad<=0)
            cout << "La velocidad no puede ser negativa. Ingrésela nuevamente. ";
    } while(velocidad<=0);

    do {
        cout << "Ingrese la duración (minutos): "; cin >> duracion;
        if (duracion<=0)
            cout << "La duracion no puede ser negativa. Ingrésela nuevamente. ";
    } while(duracion<=0);

    do {
        cout << "Ingrese la frecuencia (diaria/interdiaria/semanal): "; cin >> frecuencia;
        if (frecuencia != "diaria" and frecuencia != "interdiaria" and frecuencia!= "semanal")
            cout << "La frecuencia tiene que ser diaria, interdiaria o semanal. Ingrésela nuevamente. "<<endl;
    } while(frecuencia != "diaria" and frecuencia != "interdiaria" and frecuencia!= "semanal");

    this->velocidad = velocidad;
    this->duracion = duracion;
    this->frecuencia = frecuencia;
}

void Cardio::mostrar_informacion() {
    if (nombre != "Saltar Cuerda") {
        cout << nombre << " durante " << duracion << " minutos a " << velocidad << " km/h " << frecuencia << "mente" << endl;
        cout <<"Calorias quemadas : "<<CQE<<endl;
    }
    else {
        cout << nombre << " durante " << duracion << " a " << velocidad << " saltos por minuto " << frecuencia << "mente" << endl;
        cout<<"Calorias quemadas : "<< CQE <<endl;
    }

}

void Cardio::exportacion_informacion() {
    ofstream archivo("../docs/ReporteGeneral.txt",ios::app);
    if (nombre != "Saltar Cuerda") {
        archivo<< nombre << " durante " << duracion << " minutos a " << velocidad << " km/h " << frecuencia << "mente" << endl;
        archivo<<"Calorias quemadas : "<<CQE<<endl;
    }
    else {
        archivo<< nombre << " durante " << duracion << " a " << velocidad << " saltos por minuto " << frecuencia << "mente" << endl;
        archivo<<"Calorias quemadas : "<<CQE<<endl;
    }

    archivo.close();
}

void Cardio::hallar_CQ_FC(double TBM, int FCM) {
    if (nombre == "Correr") {
        FA = velocidad * 0.2;
        CQE = (duracion/60) * FA * TBM ;
    }
    else if (nombre == "Ciclismo"){
        FA = velocidad / 10;
        CQE = (duracion/60) * FA * TBM ;
    }
    else if (nombre == "Nadar"){
        FA = velocidad * 0.5;
        CQE = (duracion/60) * FA * TBM;
    }
    else if (nombre == "Saltar Cuerda"){
        FA = velocidad / 15;
        CQE = (duracion/60) * FA * TBM ;
    }
    FCE = FCM*(rand()%21+60)/100.0;
    if (frecuencia == "diaria")
        CQE *= 7;
    else if (frecuencia == "interdiaria")
        CQE *= 3.5;
    else if (frecuencia == "semanal")
        CQE *= 1;

}

