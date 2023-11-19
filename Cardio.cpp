//
//

#include "Cardio.h"
Cardio::Cardio() {}
Cardio::~Cardio() {cout<<"Ejercicio de Cardio destruido"<<endl;}
Cardio:: Cardio(string nombre){
    this->nombre = nombre;
}

void Cardio::ingresar_datos() {
    float velocidad,duracion;
    string frecuencia;
    do {
        cout << "Ingrese la velocidad (metros por segundo): "; cin >> velocidad;
        if (velocidad<0)
            cout << "La velocidad no puede ser negativa. Ingrésela nuevamente. ";
    } while(velocidad<0);

    do {
        cout << "Ingrese la duración (minutos): "; cin >> duracion;
        if (duracion<0)
            cout << "La duracion no puede ser negativa. Ingrésela nuevamente. ";
    } while(duracion<0);

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
    cout << nombre << " durante " << duracion << " minutos a " << velocidad << " m/s " << frecuencia << "mente" << endl;
    cout <<"Calorias quemadas : "<<CQE<<endl;
}

void Cardio::exportacion_informacion() {
    ofstream archivo("C:\\Users\\PC\\OneDrive\\Escritorio\\UTEC\\CLionProjects\\ProyectoProgra2Laboratorio\\ReporteGeneral.txt",ios::app);
    archivo<< nombre << " durante " << duracion << " minutos a " << velocidad << " m/s " << frecuencia << "mente" << endl;
    archivo<<"Calorias quemadas : "<<CQE<<endl;
    archivo.close();
}
void Cardio::hallar_CQ_FC() {
    if (nombre == "Correr") {
        CQE = 0;
        FCE = rand();
    }
    else if (nombre == "Ciclismo"){
        CQE = 0;
        FCE = 0;
    }
    else if (nombre == "Nadar"){
        CQE = 0;
        FCE = 0;
    }
    else if (nombre == "Saltar Cuerda"){
        CQE = 0;
        FCE = 0;
    }
}

