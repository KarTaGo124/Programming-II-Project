//
// Created by Guillermo Galvez on 15/11/2023.
//

#include "Usuario.h"

Usuario:: Usuario(){}

Usuario:: Usuario(string n,string g,string a,string dni,float al,float masa_cular,float grasa_cular, float p, float p_o){

    this->nombre=n;
    this->genero=g;
    this->peso=p;
    this->peso_objetivo=p_o;
    this->apellido=a;
    this ->altura=al;
    this ->masa_muscular=masa_cular;
    this ->grasa_coporal=grasa_cular;
    this ->DNI=dni;


}

/**
 * Destructor for the Usuario class.
 * Displays a message when an instance of the Usuario class is destroyed.
 */
Usuario::~Usuario() {cout<<"Usuario destruido"<<endl;}


/**
 * Validates user input for Usuario attributes.
 * Ensures that the entered data is valid and not already present in the database.
 * @param usuarios A vector containing pointers to existing Usuario objects.
 * @pre The 'usuarios' vector should not be empty, and each Usuario object in it must have a valid DNI.
 * @post The Usuario object is validated, and its attributes are set according to user input.
 *
 * Example:
 * @code
 * vector<Usuario*> usuarios;
 * Usuario* user1 = new Usuario("John", "Doe", "Masculino", 70, 75, 175, "12345678", 20, 15);
 * usuarios.push_back(user1);
 *
 * Usuario* newUser = new Usuario();
 * newUser->validar_usuario(usuarios);
 * // The method will prompt the user to input data, and if valid, newUser will be added to the 'usuarios' vector.
 * @endcode
 */
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
    cout << "----------------------------------------" << endl << "Reporte Individiual de " <<
    nombre << " " << apellido << endl;
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

