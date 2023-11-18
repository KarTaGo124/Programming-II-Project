#include <iostream>

#include "Flexibilidad.h"
#include "Fuerza.h"
#include "Cardio.h"
#include "BaseDeDatos.h"
#include "Menus.h"

int main() {
    BaseDeDatos miBaseDeDatos;

    int opcion1, opcion2, opcion3, opcion4, opcion5, opcion6, opcion7;

    do {
        cout << "\n----- Menú Principal -----" << endl;
        cout << "1. Agregar nuevo usuario" << endl;
        cout << "2. Mostrar reporte general" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese su opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string nombre, genero, apellido, dni;
                int altura;
                float masa_muscular, peso, peso_objetivo, grasa_corporal;

                cout << "Ingrese nombre: ";
                cin >> nombre;
                cout << "Ingrese género (Masculino/Femenino): ";
                cin >> genero;
                cout << "Ingrese apellido: ";
                cin >> apellido;
                cout << "Ingrese DNI: ";
                cin >> dni;
                cout << "Ingrese altura: ";
                cin >> altura;
                cout << "Ingrese peso: ";
                cin >> peso;
                cout << "Ingrese masa muscular: ";
                cin >> masa_muscular;
                cout << "Ingrese grasa corporal: ";
                cin >> grasa_corporal;
                cout << "Ingrese peso objetivo: ";
                cin >> peso_objetivo;


                Usuario *nuevoUsuario=new Usuario(nombre, genero, apellido, dni, altura, masa_muscular, grasa_corporal, peso, peso_objetivo);
                miBaseDeDatos.agregar_usuario(nuevoUsuario);
                break;
            }

            case 2:
                miBaseDeDatos.reporte_general();
                break;

            case 3:
                cout << "Saliendo del programa." << endl;
                break;

            default:
                cout << "Opción no válida. Por favor, ingrese una opción válida." << endl;
        }

    } while (opcion != 3);

    return 0;

//    int option1, option2, option3, option4, option5;
//    do {
//        option1 = menuPrincipal();
//        switch (option1) {
//            case 1:
//                break;
//            case 2:
//                break;
//            case 3:
//                break;
//            case 4:
//                break;
//            case 5:
//                break;
//
//        }
//    } while (option1 != 6);

}
