//
//

#include "../../include/user/BaseDeDatos.h"

#include "../../include/utils/Librerias.h"

BaseDeDatos::BaseDeDatos() {}

void BaseDeDatos::agregar_usuario() {
    string nombre, apellido, dni, genero;
    float peso, peso_objetivo, altura, masa_muscular, masa_muscular_objetivo;
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

        for (auto i: dni) {
            if (!isdigit(i)) {
                sonDigitos = false;
                break;  // Sale del bucle tan pronto como encuentra un carácter no numérico
            }
        }

        if (dni.length() != 8 || !sonDigitos) {
            cout << "El DNI no es válido. Inténtelo de nuevo." << endl;
        }
        if (existeUsuarioConDNI(dni)) {
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
        if (altura < 100 || altura > 250) {
            cout << "La altura no puede ser menor 100 cm ni mayor a 250 cm. Inténtelo de nuevo." << endl;
        }
    } while (altura < 100 || altura > 250);

    cout << "¡Altura válida ingresada correctamente!" << endl;

    do {
        cout << "Ingrese el peso (kg) del usuario: ";
        cin >> peso;
        if (peso < 30 || peso > 200) {
            cout << "El peso no puede ser menor a 30 kg ni mayor a 200 kg. Inténtelo de nuevo." << endl;
        }
    } while (peso < 30 || peso > 200);

    cout << "¡Peso válido ingresado correctamente!" << endl;

    do {
        cout << "Ingrese el peso objetivo (kg) del usuario: ";
        cin >> peso_objetivo;
        if (peso_objetivo < 30 || peso_objetivo > 200) {
            cout << "El peso objetivo no puede ser menor a 30 Kg ni mayor a 200 kg. Inténtelo de nuevo." << endl;
        }
    } while (peso_objetivo < 30 || peso_objetivo > 200);

    cout << "¡Peso objetivo válido ingresado correctamente!" << endl;

    do {
        cout << "Ingrese el porcentaje de masa muscular (%peso) del usuario: ";
        cin >> masa_muscular;
        if (masa_muscular < 0 || masa_muscular > 50) {
            cout
                    << "El porcentaje de masa muscular no puede ser negativo ni tampoco mayor al 50% del peso. Inténtelo de nuevo."
                    << endl;
        }
    } while (masa_muscular < 0 || masa_muscular > 50);

    cout << "¡Porcentaje de masa muscular válido ingresado correctamente!" << endl;

    do {
        cout << "Ingrese el porcentaje de masa muscular objetivo (%peso) del usuario: ";
        cin >> masa_muscular_objetivo;
        if (masa_muscular_objetivo < masa_muscular || masa_muscular_objetivo > 50) {
            cout
                    << "El porcentaje de masa muscular objetivo no puede ser negativo, tampoco mayor al 50% del peso ni menor a la masa muscular inicial. Inténtelo de nuevo."
                    << endl;
        }
    } while (masa_muscular_objetivo < masa_muscular || masa_muscular_objetivo > 50);

    cout << "¡Porcentaje de masa muscular válido ingresado correctamente!" << endl;

    do {
        cout << "Ingrese la edad del usuario: ";
        cin >> edad;
        if (edad < 15 || edad > 60) {
            cout << "Tienes que tener al menos 15 años y como maximo 60 años para usar el programa. Inténtelo de nuevo."
                 << endl;
        }
    } while (edad < 15 || edad > 60);

    cout << "¡Edad válida ingresada correctamente!" << endl;

    auto *axu = new Usuario(nombre, apellido, genero, edad, peso, peso_objetivo, altura, dni, masa_muscular,
                            masa_muscular_objetivo);
    usuarios.push_back(axu);

    cout << "¡El Usuario se ha registrado correctamente!" << endl;

}

void BaseDeDatos::reporte_general() {
    for (auto i: usuarios) { i->reporte_individual(); }
}

void BaseDeDatos::exportarReportes() {
    ofstream archivo("../docs/ReporteGeneral.txt", ios::out);
    for (auto i: usuarios) {
        i->reporte_individual_exportacion();
    }
    archivo.close();
}

bool BaseDeDatos::existeUsuarioConDNI(const string &dni) {
    for (const auto &i: usuarios) {
        if (i->getDNI() == dni) {
            return true;
        }
    }
    return false;
}

BaseDeDatos::~BaseDeDatos() {
    for (auto i: usuarios) delete i;
    cout << "Base de datos destruida" << endl;
}

vector<Usuario *> &BaseDeDatos::getUsuarios() {
    return usuarios;
}


