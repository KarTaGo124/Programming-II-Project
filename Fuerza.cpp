#include "Fuerza.h"

Fuerza::Fuerza() {}
Fuerza::Fuerza(string nombre) {
    this -> nombre = nombre;
}


/*
 * Takes user input to set the attributes of the Fuerza object.
 * Ensures that the entered data for repetitions, series, and weight is non-negative.
 * The user is also prompted to input the exercise frequency (diaria/interdiaria/semanal).
 */
void Fuerza:: ingresar_datos() {
    int repeticiones;
    int series;
    float peso;
    string frecuencia;

    do {
        cout << "Ingrese el número de repeticiones: ";
        cin >> repeticiones;
    } while (repeticiones<0);

    do {
        cout << "Ingrese el número de series: ";
        cin >> series;
    } while (series<0);

    do{
        cout << "Ingrese el peso que usa para el ejercicio (kg): ";
        cin >> peso;
    } while (peso<0);

    do {
        cout << "Ingrese la frecuencia (diaria/interdiaria/semanal): ";
        cin >> frecuencia;
        if (frecuencia != "diaria" and frecuencia != "interdiaria" and frecuencia!= "semanal")
            cout << "La frecuencia tiene que ser diaria, interdiaria o semanal. Ingrésela nuevamente. "<<endl;
    } while(frecuencia != "diaria" and frecuencia != "interdiaria" and frecuencia!= "semanal");

    // Set the attributes with the validated user input
    this->repeticiones=repeticiones;
    this->series=series;
    this->pesa=peso;
    this->frecuencia=frecuencia;

}

void Fuerza::hallar_CQ_FC() {}
/**
 * Displays information about the Fuerza exercise.
 * Outputs the number of repetitions, series, weight, and exercise frequency.
 */
void Fuerza::mostrar_informacion() {
    cout << "Realiza " << repeticiones << " repeticiones de " << nombre << " en " << series << " series con un peso de "
         << pesa << " Kg " << frecuencia << "mente" << endl;
    cout <<"Calorias quemadas : "<<CQE<<endl;

}

void Fuerza::exportacion_informacion() {

    ofstream archivo("C:\\Users\\PC\\OneDrive\\Escritorio\\UTEC\\CLionProjects\\ProyectoProgra2Laboratorio\\ReporteGeneral.txt",ios::app);
    archivo<< "Realiza " << repeticiones << " repeticiones de " << nombre << " en " << series << " series con un peso de " << pesa << " Kg " << frecuencia << "mente" << endl;
    archivo<<"Calorias quemadas : "<<CQE<<endl;
    archivo.close();

}


Fuerza::~Fuerza() {cout<<"Ejercicio de Fuerza destruido"<<endl;}
