#ifndef PROYECTO_MENUS_H
#define PROYECTO_MENUS_H

/**
 * @file Menus.h
 * Header file for defining menus and related functions in the project.
 */

#include "Librerias.h"
#include "../user/Usuario.h"

/**
 * Displays the main menu and prompts the user to choose an option.
 * @return The chosen option.
 */
int menuPrincipal() {
    int option;
    do {
        cout << "\t MENU PRINCIPAL" << endl
             << "1. Ingresar datos de un nuevo Usuario" << endl
             << "2. Ingresar la rutina semanal de un Usuario" << endl
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

/**
 * Displays general health and fitness tips randomly chosen from a predefined list.
 */
void Consejos_Generales() {
    vector<string> consejos_generales = {
            "Prioriza alimentos frescos y naturales.",
            "Consume una variedad de colores en tus comidas para obtener diversos nutrientes.",
            "Bebe suficiente agua a lo largo del día.",
            "Controla las porciones para evitar el exceso de calorías.",
            "Incluye fuentes de proteínas magras en cada comida.",
            "Aumenta la ingesta de fibra con frutas, verduras y granos enteros.",
            "Limita el consumo de alimentos procesados y ricos en azúcares añadidos.",
            "Come conscientemente, disfrutando cada bocado.",
            "Cocina en casa para tener control sobre los ingredientes.",
            "Planifica tus comidas con antelación para evitar decisiones impulsivas.",
            "Incorpora actividad física regular en tu rutina diaria.",
            "Duerme lo suficiente para permitir la recuperación del cuerpo.",
            "Practica técnicas de manejo del estrés, como la meditación o el yoga.",
            "Haz chequeos de salud periódicos y exámenes preventivos.",
            "Mantén una postura adecuada para prevenir problemas de espalda.",
            "Evita el tabaco y limita el consumo de alcohol.",
            "Establece límites en el tiempo frente a pantallas electrónicas.",
            "Mantén una buena higiene personal para prevenir enfermedades.",
            "Cultiva relaciones sociales positivas para el bienestar emocional.",
            "Escucha a tu cuerpo y descansa cuando sea necesario.",
            "Encuentra una actividad física que disfrutes para hacer el ejercicio más divertido.",
            "Establece metas realistas y alcanzables para mantenerte motivado.",
            "Varía tu rutina de ejercicios para evitar el aburrimiento y estimular diferentes músculos.",
            "Incluye tanto entrenamiento de fuerza como cardiovascular en tu programa.",
            "Encuentra un compañero de entrenamiento para mayor apoyo y responsabilidad.",
            "Programa tus entrenamientos como citas inquebrantables en tu agenda.",
            "Celebra tus logros, incluso los pequeños avances.",
            "Escucha música motivadora durante tus sesiones de entrenamiento.",
            "Ajusta tu rutina según tu nivel de energía y estado de ánimo.",
            "No te desanimes por contratiempos; aprende de ellos y sigue adelante.",
            "Visualiza tus metas regularmente para mantener la motivación.",
            "Recompénsate a ti mismo por tus logros, incluso los pequeños.",
            "Encuentra inspiración en modelos a seguir que hayan alcanzado objetivos similares.",
            "Mantén un registro de tus progresos para ver cómo avanzas.",
            "Únete a comunidades en línea o grupos de ejercicio para compartir experiencias.",
            "Establece un horario regular para tu actividad física.",
            "Experimenta con nuevas actividades para evitar la monotonía.",
            "Rodéate de personas que te apoyen en tus objetivos de salud y fitness.",
            "Practica la gratitud, reconociendo los beneficios que has experimentado.",
            "Recuerda que la consistencia es clave; los cambios toman tiempo, pero valen la pena.",
            };
    int aleatorio= rand()%consejos_generales.size();
    cout<<consejos_generales[aleatorio];
}

#endif //PROYECTO_MENUS_H
