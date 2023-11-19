#include "Flexibilidad.h"
#include "Fuerza.h"
#include "Cardio.h"
#include "BaseDeDatos.h"
#include "Menus.h"

// falta implementar las graficas(nose)
// la calculadora de calorias(esto no se) y frecuencia cardiaca(podria ser un rand)

// implementar un mensaje que avise cuando llegas al peso objetivo

int main() {
    srand(time(nullptr));
    auto* baseDeDatos = new BaseDeDatos();  // Crear una instancia de la base de datos

    int opcion1, opcion2, opcion3, opcion4, opcion5, opcion6, opcion7, numero_semanas;

    do {
        opcion1 = menuPrincipal();
        switch (opcion1) {
            case 1:
                baseDeDatos->agregar_usuario();
                break;
            case 2:
                opcion2 = menuUsuarios(baseDeDatos->getUsuarios());
                do {
                    cout << "Cuantas semanas durará la rutina (como minimo 4): "; cin >> numero_semanas;
                } while (numero_semanas < 4);
                do{
                    opcion3 = menuEjercicios();
                    switch (opcion3) {
                        case 1:
                            do {
                                Cardio* aux_cardio;
                                opcion4 = menuCardio();
                                switch (opcion4) {
                                    case 1:
                                        aux_cardio = new Cardio("Correr");
                                        aux_cardio->ingresar_datos();
                                        break;
                                    case 2:
                                        aux_cardio = new Cardio("Ciclismo");
                                        aux_cardio->ingresar_datos();
                                        break;
                                    case 3:
                                        aux_cardio = new Cardio("Nadar");
                                        aux_cardio->ingresar_datos();
                                        break;
                                    case 4:
                                        aux_cardio = new Cardio("Saltar Cuerda");
                                        aux_cardio->ingresar_datos();
                                        break;
                                }
                                aux_cardio->hallar_CQ_FC();
                                if (opcion4!=5)
                                    baseDeDatos->getUsuarios()[opcion2-1]->agregar_ejercicio(aux_cardio);
                                cout << "-----CONSEJO : ";
                                Consejos_Generales();
                                cout << "------" << endl;
                            } while (opcion4!= 5);
                            break;
                        case 2:
                            do {
                                Fuerza* aux_fuerza;
                                opcion5 = menuFuerza();
                                switch (opcion5) {
                                    case 1:
                                        aux_fuerza = new Fuerza("Press Banca");
                                        aux_fuerza->ingresar_datos();
                                        break;
                                    case 2:
                                        aux_fuerza = new Fuerza("Sentadillas");
                                        aux_fuerza->ingresar_datos();
                                        break;
                                    case 3:
                                        aux_fuerza = new Fuerza("Peso Muerto");
                                        aux_fuerza->ingresar_datos();
                                        break;
                                    case 4:
                                        aux_fuerza = new Fuerza("Dominadas");
                                        aux_fuerza->ingresar_datos();
                                        break;
                                    case 5:
                                        aux_fuerza = new Fuerza("Flexiones");
                                        aux_fuerza->ingresar_datos();
                                        break;
                                }
                                aux_fuerza->hallar_CQ_FC();
                                if (opcion5!=6)
                                    baseDeDatos->getUsuarios()[opcion2-1]->agregar_ejercicio(aux_fuerza);
                                cout << "-----CONSEJO : ";
                                Consejos_Generales();
                                cout << "------" << endl;
                            } while(opcion5!=6);
                            break;
                        case 3:
                            do {
                                Flexibilidad* aux_flexibilidad;
                                opcion6 = menuFlexibilidad();
                                switch (opcion6) {
                                    case 1:
                                        aux_flexibilidad = new Flexibilidad("Yoga");
                                        aux_flexibilidad->ingresar_datos();
                                        break;
                                    case 2:
                                        aux_flexibilidad = new Flexibilidad("Danza");
                                        aux_flexibilidad->ingresar_datos();
                                        break;
                                    case 3:
                                        aux_flexibilidad = new Flexibilidad("Arte Marcial");
                                        aux_flexibilidad->ingresar_datos();
                                        break;
                                    case 4:
                                        aux_flexibilidad = new Flexibilidad("Estiramientos");
                                        aux_flexibilidad->ingresar_datos();
                                        break;
                                }
                                aux_flexibilidad->hallar_CQ_FC();
                                if (opcion6!=5)
                                    baseDeDatos->getUsuarios()[opcion2-1]->agregar_ejercicio(aux_flexibilidad);
                                cout << "-----CONSEJO : ";
                                Consejos_Generales();
                                cout << "------" << endl;
                            } while(opcion6!=5);
                            break;
                    }
                    float calorias_semanales = 0;
                    for (auto i : baseDeDatos->getUsuarios()[opcion2-1]->getEjercicios()) {
                        calorias_semanales += i->getCQE();
                    }
                    baseDeDatos->getUsuarios()[opcion2-1]->getHistorialCaloriasQuemadas().push_back(calorias_semanales);
                    baseDeDatos->getUsuarios()[opcion2-1]->calorias_quemadas_rango(calorias_semanales,numero_semanas);
                } while (opcion3!=4);
                break;
            case 3:
                system("python Graficas.py");
                break;
            case 4:
                opcion7 = menuUsuarios(baseDeDatos->getUsuarios());
                baseDeDatos->getUsuarios()[opcion7-1]->reporte_individual();
                break;
            case 5:
                baseDeDatos->reporte_general();
                break;
            case 6:
                cout << "Reporte general exportado" << endl;
                baseDeDatos->exportarReportes();
                break;
            case 7:
                cout << "Saliendo del programa." << endl;
                break;

            default:
                cout << "Opción no válida. Inténtelo de nuevo." << endl;
        }
    } while (opcion1 != 7);


    return 0;
}



