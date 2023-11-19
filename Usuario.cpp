/**
 * @file Usuario.cpp
 * Implementation of the Usuario class.
 */

#include "Usuario.h"

/**
 * Default constructor for the Usuario class.
 * Example:
 * @code
 * Usuario user; // Creates a default Usuario object.
 * @endcode
 */
Usuario:: Usuario() {}
/**
 * Parameterized constructor for the Usuario class.
 * Initializes the Usuario object with provided attributes.
 * @param nombre          The name of the user.
 * @param apellido        The last name of the user.
 * @param genero          The gender of the user (either "Masculino" or "Femenino").
 * @param peso            The weight of the user.
 * @param peso_objetivo   The weight goal of the user.
 * @param altura          The height of the user.
 * @param dni             The DNI (Documento Nacional de Identidad) of the user.
 * @param masa_muscular   The muscular mass of the user.
 * @param grasa_coporal   The body fat percentage of the user.
 */
Usuario::Usuario(string nombre, string apellido, string genero, float peso, float peso_objetivo,
                 float altura, string dni, float masa_muscular, float grasa_coporal) {
    this->nombre = nombre;
    this->apellido = apellido;
    this->genero = genero;
    this->peso = peso;
    this->peso_inicial = peso;
    this->peso_objetivo = peso_objetivo;
    this->altura = altura;
    this->masa_muscular = masa_muscular;
    this->grasa_coporal = grasa_coporal;
    this->DNI = dni;

}

/**
 * Destructor for the Usuario class.
 * Displays a message when an instance of the Usuario class is destroyed.
 */
Usuario::~Usuario() {cout<<"Usuario destruido"<<endl;}


/**
 * Adds an exercise to the user's exercise list.
 * @param ejercicio A pointer to the Ejercicio object to be added.
 * Example:
 * @code
 * Usuario user("John", "Doe", "Masculino", 70, 75, 175, "12345678", 20, 15);
 * Ejercicio* exercise = new Ejercicio("Running", 30, 150);
 * user.agregar_ejercicio(exercise); // Adds the exercise to the user's list.
 * @endcode
 */
void Usuario::agregar_ejercicio(Ejercicio* ejercicio) {
    ejercicios.push_back(ejercicio);
}

/**
 * Calculates the Body Mass Index (BMI) of the user.
 * @return The calculated BMI value.
 * Example:
 * @code
 * Usuario user("John", "Doe", "Masculino", 70, 75, 175, "12345678", 20, 15);
 * float bmi = user.calcular_IMC(); // Calculates and returns the BMI.
 * @endcode
 */
float Usuario::calcular_IMC() {
    return peso / (pow(altura,2));
}

/**
 * Calculates the average heart rate during exercises.
 * @return The average heart rate.
 *
 * Example:
 * @code
 * Usuario user("John", "Doe", "Masculino", 70, 75, 175, "12345678", 20, 15);
 * auto* exercise1 = new Cardio("Correr", 30, 150);
 * auto* exercise2 = new Cardio("Nadar", 45, 130);
 * user.agregar_ejercicio(exercise1);
 * user.agregar_ejercicio(exercise2);
 * float avgHeartRate = user.frecuencia_cardiaca_prom(); // Calculates and returns the average heart rate.
 * @endcode
 */
float Usuario::frecuencia_cardiaca_prom() {
    float promedio = 0;
    for (int i = 0; i < ejercicios.size(); i++) {
        promedio += ejercicios[i]->getFCE();
    }
    return promedio = promedio / ejercicios.size();

}

/**
 * Generates an individual report for the user, displaying information about each exercise.
 * Example:
 * @code
 * Usuario user("John", "Doe", "Masculino", 70, 75, 175, "12345678", 20, 15);
 * auto* exercise1 = new Cardio("Correr", 30, 150);
 * auto* exercise2 = new Cardio("Nadar", 45, 130);
 * user.agregar_ejercicio(exercise1);
 * user.agregar_ejercicio(exercise2);
 * user.reporte_individual(); // Displays a report of each exercise for the user.
 * @endcode
 */


void Usuario::reporte_individual() {
    cout << "----------------------------------------" << endl << "Reporte Individual de " <<
    nombre << " " << apellido << endl;
    for (auto i: ejercicios){
        i->mostrar_informacion();
    }
    for (auto i: historial_de_IMCS){
        cout<<"Indice de masa corporal : "<<i+1<< calcular_IMC()<<endl;
    }
    cout<<"Frecuencia cardiaca promedio: "<< frecuencia_cardiaca_prom()<<endl;
}

void Usuario::reporte_individual_exportacion() {
    ofstream archivo("C:\\Users\\PC\\OneDrive\\Escritorio\\UTEC\\CLionProjects\\ProyectoProgra2Laboratorio\\ReporteGeneral.txt",ios::out);
    archivo<< "----------------------------------------" << endl << "Reporte Individual de " <<
           nombre << " " << apellido << endl;
    archivo.close();
    for (auto i: ejercicios){
        i->exportacion_informacion();
    }
    archivo.open("C:\\Users\\PC\\OneDrive\\Escritorio\\UTEC\\CLionProjects\\ProyectoProgra2Laboratorio\\ReporteGeneral.txt",ios::app);
    for (auto i: historial_de_IMCS){
        archivo<<"Indice de masa corporal : "<<i+1<< calcular_IMC()<<endl;
    }
    archivo<<"Frecuencia cardiaca promedio: "<< frecuencia_cardiaca_prom()<<endl;
    archivo.close();

}

void Usuario::peso_ideal() {
    if (peso_inicial < peso_objetivo) {
        if (peso >= peso_objetivo)
            cout << "--------Has alcanzado tu peso objetivo, Felicitaciones.--------" << endl;
    }

    else if(peso_inicial>peso_objetivo){
        if(peso<=peso_objetivo)
            cout<<"-------Has alcanzado tu peso objetivo, Felicitaciones.--------"<<endl;
    }

}

void Usuario::calorias_quemadas_rango(float c, int n) {
    for (int i = 0; i < n-1; i++) {
        historial_calorias_quemadas.push_back(c * ((100-(rand()%10+1))/100));
    }
}

string Usuario::to_string_historial_calorias() {
    string texto;
    for (int i = 0; i < historial_calorias_quemadas.size(); i++) {
        texto += to_string(historial_calorias_quemadas[i]) + " ";
    }
    return texto;
}
/**
 * Getter function for the DNI attribute.
 * @return A constant reference to the DNI attribute.
 * Example:
 * @code
 * Usuario user("John", "Doe", "Masculino", 70, 75, 175, "12345678", 20, 15);
 * string dni = user.getDNI(); // Retrieves and returns the DNI.
 * @endcode
 */
string const& Usuario::getDNI() const {
    return DNI;
}

/**
 * Getter function for the nombre attribute.
 * @return A constant reference to the nombre attribute.
 * Example:
 * @code
 * Usuario user("John", "Doe", "Masculino", 70, 75, 175, "12345678", 20, 15);
 * string name = user.getNombre(); // Retrieves and returns the name.
 * @endcode
 */
const string &Usuario::getNombre() const {
    return nombre;
}


/**
 * Getter function for the apellido attribute.
 * @return A constant reference to the apellido attribute.
 * Example:
 * @code
 * Usuario user("John", "Doe", "Masculino", 70, 75, 175, "12345678", 20, 15);
 * string lastName = user.getApellido(); // Retrieves and returns the last name.
 * @endcode
 */
const string &Usuario::getApellido() const {
    return apellido;
}

vector<float> &Usuario::getHistorialCaloriasQuemadas() {
    return historial_calorias_quemadas;
}

vector<Ejercicio *> &Usuario::getEjercicios()  {
    return ejercicios;
}



