#include "Fuerza.h"

/**
 * Default constructor for the Fuerza class.
 */
Fuerza::Fuerza() {}

/**
 * Parameterized constructor for the Fuerza class.
 * Initializes the Fuerza object with the given name.
 * @param nombre The name of the strength exercise.
 */
Fuerza:: Fuerza(string nombre){
    this->nombre = nombre;
}

/**
 * Destructor for the Fuerza class.
 * Displays a message when an instance of the Fuerza class is destroyed.
 */
Fuerza::~Fuerza() {cout<<"Ejercicio de Fuerza destruido"<<endl;}

/**
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
    this->peso=peso;
    this->frecuencia=frecuencia;

}

/**
 * Displays information about the Fuerza exercise.
 * Outputs the number of repetitions, series, weight, and exercise frequency.
 */
void Fuerza::mostrar_informacion() {
    cout << "Realiza " << repeticiones << " repeticiones de " << nombre << " en " << series << " series con un peso de "
         << peso << " Kg " << frecuencia << "mente" << endl;
    cout <<"Calorias quemadas : "<<CQE<<endl;

}

/**
 * Calculates and sets the Calorias Quemadas (CQ) and Frecuencia Cardiaca (FC) for the strength exercise.
 * Overrides the corresponding method in the base class (Ejercicio).
 */
void Fuerza::hallar_CQ_FC() {
    if (nombre == "Press Banca") {
        CQE = 0;
        FCE = 0;
    }
    else if (nombre == "Peso Muerto") {
        CQE = 0;
        FCE = 0;
    }
    else if (nombre == "Sentadillas") {
        CQE = 0;
        FCE = 0;
    }
    else if (nombre == "Dominadas") {
        CQE = 0;
        FCE = 0;
    }
    else if (nombre == "Flexiones") {
        CQE = 0;
        FCE = 0;
    }
}