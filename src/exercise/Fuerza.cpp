#include "../../include/exercise/Fuerza.h"

Fuerza::Fuerza() {}
Fuerza::Fuerza(string nombre) {this -> nombre = nombre;}

Fuerza::~Fuerza() {cout<<"Ejercicio de Fuerza destruido"<<endl;}

void Fuerza:: ingresar_datos() {
    int repeticiones;
    int series;
    float peso;
    string frecuencia;

    do {
        cout << "Ingrese el número de repeticiones: ";
        cin >> repeticiones;
    } while (repeticiones<=0);

    do {
        cout << "Ingrese el número de series: ";
        cin >> series;
    } while (series<=0);

    do{
        cout << "Ingrese el peso que usa para el ejercicio (kg): ";
        cin >> peso;
    } while (peso<=0);

    do {
        cout << "Ingrese la frecuencia (diaria/interdiaria/semanal): ";
        cin >> frecuencia;
        if (frecuencia != "diaria" and frecuencia != "interdiaria" and frecuencia!= "semanal")
            cout << "La frecuencia tiene que ser diaria, interdiaria o semanal. Ingrésela nuevamente. "<<endl;
    } while(frecuencia != "diaria" and frecuencia != "interdiaria" and frecuencia!= "semanal");

    // Set the attributes with the validated user input
    this->repeticiones=repeticiones;
    this->series=series;
    this->peso=peso;
    this->frecuencia=frecuencia;
}

void Fuerza::mostrar_informacion() {
    cout << "Realiza " << repeticiones << " repeticiones de " << nombre << " en " << series << " series con un peso de "
         << peso << " Kg " << frecuencia << "mente" << endl;
    cout <<"Calorias quemadas : "<<CQE<<endl;
}

void Fuerza::exportacion_informacion() {
    ofstream archivo("../docs/ReporteGeneral.txt",ios::app);
    archivo<< "Realiza " << repeticiones << " repeticiones de " << nombre << " en " << series << " series con un peso de " << peso << " Kg " << frecuencia << "mente" << endl;
    archivo<<"Calorias quemadas : "<<CQE<<endl;
    archivo.close();
}

void Fuerza::hallar_CQ_FC(double TBM, int FCM) {

    if (nombre == "Press Banca") {
        FA = 0.9;
        CQE = 0.01 * peso * repeticiones * series * FA * TBM;
        FCE = 0.5 * FCM;
    }
    else if (nombre == "Peso Muerto"){
        FA = 1.1;
        CQE = 0.01 * peso * repeticiones * series * FA * TBM;
        FCE = 0.55 * FCM;
    }
    else if (nombre == "Sentadillas"){
        FA = 1.2;
        CQE = 0.03 * peso * repeticiones * series * FA * TBM;
        FCE = 0.45 * FCM;
    }
    else if (nombre == "Dominadas"){
        FA = 0.95;
        CQE = 0.05 * peso * repeticiones * series * FA * TBM;
        FCE = 0.6 * FCM;
    }
    else if (nombre == "Flexiones"){
        FA = 0.8;
        CQE = 0.04 * peso * repeticiones * series * FA * TBM;
        FCE = 0.55 * FCM;
    }
    CQE = -CQE;
    if (frecuencia == "diaria")
        CQE *= 7;
    else if (frecuencia == "interdiaria")
        CQE *= 3.5;
    else if (frecuencia == "semanal")
        CQE *= 1;
}


