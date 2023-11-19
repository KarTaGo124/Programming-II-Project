#ifndef PROYECTO_MENUS_H
#define PROYECTO_MENUS_H

/**
 * @file Menus.h
 * Header file for defining menus and related functions in the project.
 */

#include "Librerias.h"

/**
 * Displays the main menu and prompts the user to choose an option.
 * @return The chosen option.
 */
int menuPrincipal() {
    int option;
    do {
        cout << "\t MENU PRINCIPAL" << endl
             << "1. Ingresar datos de un nuevo Usuario" << endl
             << "2. Ingresar rutina de un Usuario" << endl
             << "3. Mostrar gráficas de progreso de un Usuario" << endl
             << "4. Mostrar reporte individual de un Usuario" << endl
             << "5. Mostrar reporte general de todos los Usuarios" << endl
             << "6. Exportar reporte general" << endl
             << "7. Finalizar" << endl
             << "Elija una opción: "; cin >> option;
    } while (option < 1 || option > 7);
    return option;
}

/**
 * Displays a menu listing available users and prompts the user to choose one.
 * @param usuarios A vector containing pointers to Usuario objects.
 * @return The index of the selected user.
 */
int menuUsuarios(const vector<Usuario*> &usuarios) {
    int option;
    cout << "\t MENU USUARIOS" << endl;
    for (int i = 0; i < usuarios.size(); i++){
        cout << i + 1 << ". " << usuarios[i]->getNombre() << " " << usuarios[i]->getApellido() << endl;
    }
    do {
        cout << "Ingrese el índice de un Usuario: "; cin >> option;
    } while(option < 1 || option > usuarios.size());
    return option;
}

/**
 * Displays a menu for selecting exercise types and prompts the user to choose one.
 * @return The chosen option.
 */
int menuEjercicios() {
    int option;
    do {
        cout << "\t MENU EJERCICIOS" << endl
        << "1. Cardio" << endl
        << "2. Fuerza" << endl
        << "3. Flexibilidad" << endl
        << "4. Volver al Menu Principal" << endl
        << "Elija una opción: "; cin >> option;
    } while (option < 1 || option > 4);
    return option;
}

/**
 * Displays a menu for selecting cardio exercises and prompts the user to choose one.
 * @return The chosen option.
 */
int menuCardio() {
    int option;
    do {
        cout << "\t MENU CARDIO" << endl
        << "1. Correr" << endl
        << "2. Ciclismo" << endl
        << "3. Nadar" << endl
        << "4. Saltar Cuerda" << endl
        << "5. Volver al Menu Ejercicios" << endl
        << "Elija una opción: "; cin >> option;
    } while (option < 1 || option > 5);
    return option;
}

/**
 * Displays a menu for selecting strength exercises and prompts the user to choose one.
 * @return The chosen option.
 */
int menuFuerza() {
    int option;
    do {
        cout << "\t MENU FUERZA" << endl
        << "1. Press Banca" << endl
        << "2. Peso Muerto" << endl
        << "3. Sentadillas" << endl
        << "4. Dominadas" << endl
        << "5. Flexiones" << endl
        << "6. Volver al Menu Ejercicios" << endl
        << "Elija una opción: "; cin >> option;
    } while (option < 1 || option > 6);
    return option;
}

/**
 * Displays a menu for selecting flexibility exercises and prompts the user to choose one.
 * @return The chosen option.
 */
int menuFlexibilidad() {
    int option;
    do {
        cout << "\t MENU FLEXIBILIDAD" << endl
        << "1. Yoga" << endl
        << "2. Danza" << endl
        << "3. Arte Marcial" << endl
        << "4. Estiramientos" << endl
        << "5. Volver al Menu Ejercicios" << endl
        << "Elija una opción: "; cin >> option;
    } while (option < 1 || option > 5);
    return option;
}