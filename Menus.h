//
// Created by Guillermo Galvez on 16/11/2023.
//

#ifndef PROYECTO_MENUS_H
#define PROYECTO_MENUS_H

#endif //PROYECTO_MENUS_H
#include "Librerias.h"
int menuPrincipal(){
    int option;
    do {
        cout << "\t MENU PRINCIPAL" << endl
             << "1. Ingresar datos de un Usuario" << endl
             << "2. Ingresar ejercicios a la rutina de un Usuario" << endl
             << "3. Mostrar reporte individual de un Usuario" << endl
             << "4. Mostrar reporte general de todos los Usuarios" << endl
             << "5. Exportar reporte general" << endl
             << "6. Finalizar" << endl
             << "Elija una opcion: "; cin >> option;
    } while (option < 1 || option > 6);
    return option;
}

int menuUsuarios(const vector<Usuario*> &usuarios){
    int option;
    do {
        cout << "\t MENU USUARIOS" << endl;
        for (int i = 0; i < usuarios.size(); i++){
            cout << i + 1 << ". " << usuarios[i]->getNombre() << " " << usuarios[i]->getApellido();
        }
        cin >> option;
    } while(option < 1 || option >= usuarios.size());
    return option;
}

int menuEjercicios(){
    int option;
    do {
        cout << "\t MENU EJERCICIOS" << endl
        << "1. Cardio" << endl
        << "2. Fuerza" << endl
        << "3. Flexibilidad" << endl
        << "4. Volver al menu principal" << endl
        << "Elija una opcion: "; cin >> option;
    } while (option < 1 || option > 4);
    return option;
}
int menuCardio(){
    int option;
    do {
        cout << "\t MENU CARDIO" << endl
        << "1. Correr" << endl
        << "2. Ciclismo" << endl
        << "3. Nadar" << endl
        << "4. Saltar Cuerda" << endl
        << "Elija una opcion: "; cin >> option;
    } while (option < 1 || option > 4);
    return option;
}
int menuFuerza(){
    int option;
    do {
        cout << "\t MENU FUERZA" << endl
        << "1. Press Banca" << endl
        << "2. Peso Muerto" << endl
        << "3. Sentadillas" << endl
        << "4. Dominadas" << endl
        << "5. Flexiones" << endl
        << "Elija una opcion: "; cin >> option;
    } while (option < 1 || option > 5);
    return option;
}
int menuFlexibilidad(){
    int option;
    do {
        cout << "\t MENU FLEXIBILIDAD" << endl
        << "1. Yoga" << endl
        << "2. Danza" << endl
        << "3. Arte Marcial" << endl
        << "4. Estiramientos" << endl
        << "Elija una opcion: "; cin >> option;
    } while (option < 1 || option > 4);
    return option;
}