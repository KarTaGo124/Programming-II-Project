//
//

#include "BaseDeDatos.h"

#include "Librerias.h"

BaseDeDatos:: BaseDeDatos(){}

void BaseDeDatos::agregar_usuario() {
    string nombre, apellido, dni, genero;
    float peso, peso_objetivo, altura, masa_muscular, grasa_corporal;
    int edad;

    do {
        cout << "Ingrese el nombre del usuario: ";
        cin >> nombre;
        if (nombre.length() < 2) {
            cout << "El nombre no puede tener menos de un caracter. Inténtelo de nuevo." << endl;
        }

    } while (nombre.length() < 2);

    cout << "¡Nombre válido ingresado correctamente!" << endl;

    do {
        cout << "Ingrese el apellido del usuario: ";
        cin >> apellido;
        if (apellido.length() < 2) {
            cout << "El apellido no puede tener menos de un caracter. Inténtelo de nuevo." << endl;
        }
    } while (apellido.length() < 2);

    cout << "¡Apellido válido ingresado correctamente!" << endl;

    bool sonDigitos;

    do {
        sonDigitos = true; // Restablece a true al inicio de cada iteración

        cout << "Ingrese el DNI del usuario (8 dígitos): ";
        cin >> dni;

        for (auto i : dni) {
            if (!isdigit(i)) {
                sonDigitos = false;
                break;  // Sale del bucle tan pronto como encuentra un carácter no numérico
            }
        }

        if (dni.length() != 8 || !sonDigitos) {
            cout << "El DNI no es válido. Inténtelo de nuevo." << endl;
        }
        if (existeUsuarioConDNI(dni)){
            cout << "El DNI ya ha sido registrado en la base de datos. Inténtelo de nuevo." << endl;
        }

    } while (dni.length() != 8 || existeUsuarioConDNI(dni) || !sonDigitos);

    cout << "¡DNI válido ingresado correctamente!" << endl;

    do {
        cout << "Ingrese el género del usuario (Masculino/Femenino): ";
        cin >> genero;
        if (genero != "Masculino" && genero != "Femenino") {
            cout << "El género ingresado no es válido. Inténtelo de nuevo." << endl;
        }
    } while (genero != "Masculino" && genero != "Femenino");

    cout << "¡Sexo válido ingresado correctamente!" << endl;

    do {
        cout << "Ingrese la altura (cm) del usuario: ";
        cin >> altura;
        if (altura < 0 || altura > 250) {
            cout << "La altura no puede ser negativa. Inténtelo de nuevo." << endl;
        }
    } while (altura < 0 || altura > 250);

    cout << "¡Altura válida ingresada correctamente!" << endl;

    do {
        cout << "Ingrese el peso (kg) del usuario: ";
        cin >> peso;
        if (peso < 0 || peso > 200) {
            cout << "El peso no puede ser negativo. Inténtelo de nuevo." << endl;
        }
    } while (peso < 0 || peso > 200);

    cout << "¡Peso válido ingresado correctamente!" << endl;

    do {
        cout << "Ingrese el peso objetivo (kg) del usuario: ";
        cin >> peso_objetivo;
        if (peso_objetivo < 0 || peso_objetivo > 200) {
            cout << "El peso objetivo no puede ser negativo. Inténtelo de nuevo." << endl;
        }
    } while (peso_objetivo < 0 || peso_objetivo > 200);

    cout << "¡Peso objetivo válido ingresado correctamente!" << endl;

    do {
        cout << "Ingrese el porcentaje de masa muscular (%peso) del usuario: ";
        cin >> masa_muscular;
        if (masa_muscular < 0 || masa_muscular > 50) {
            cout << "El porcentaje de masa muscular no puede ser negativa ni tampoco mayor al 50% del peso. Inténtelo de nuevo." << endl;
        }
    } while (masa_muscular < 0 || masa_muscular > 50);

    cout << "¡Porcentaje de masa muscular válido ingresado correctamente!" << endl;

    do {
        cout << "Ingrese el porcentaje de grasa corporal (%peso) del usuario: ";
        cin >> grasa_corporal;
        if (grasa_corporal < 0 || grasa_corporal > 50) {
            cout << "El porcentaje de grasa corporal no puede ser negativo ni tampoco mayor al 50% del peso. Inténtelo de nuevo." << endl;
        }
    } while (grasa_corporal < 0 || grasa_corporal > 50);

    cout << "¡Porcentaje de grasa corporal válido ingresado correctamente!" << endl;

    do {
        cout << "Ingrese la edad del usuario: ";
        cin >> edad;
        if (edad < 15) {
            cout << "Tienes que tener al menos 15 años para usar el programa. Inténtelo de nuevo." << endl;
        }
    } while (edad < 15);

    cout << "¡Edad válida ingresada correctamente!" << endl;

    auto *axu=new Usuario(nombre,apellido,genero,peso,peso_objetivo,altura,dni,masa_muscular*peso/100,grasa_corporal*peso/100);
    usuarios.push_back(axu);

    cout << "¡El Usuario se ha registrado correctamente!" << endl;

}

void BaseDeDatos::reporte_general() {
    for(auto i: usuarios){
        i->reporte_individual();
    }
}
void BaseDeDatos::  exportarReportes(){}

bool BaseDeDatos::existeUsuarioConDNI(const string& dni) {
    for (const auto &i : usuarios) {
        if (i->getDNI() == dni) {
            return true;
        }
    }
    return false;
}

BaseDeDatos::~BaseDeDatos() {
    for (auto i: usuarios)
    {
        delete i;
    }

}

const vector<Usuario *> &BaseDeDatos::getUsuarios() const {
    return usuarios;
}


