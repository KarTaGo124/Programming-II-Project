#include "../include/exercise/Flexibilidad.h"
#include "../include/exercise/Fuerza.h"
#include "../include/exercise/Cardio.h"
#include "../include/user/BaseDeDatos.h"
#include "../include/utils/Menus.h"


int main() {
    srand(time(nullptr));
    auto* baseDeDatos = new BaseDeDatos();  // Crear una instancia de la base de datos
    int opcion1, opcion2, opcion3, opcion4, opcion5, opcion6, opcion7, opcion8, numero_semanas;
    double calorias_semanales = 0;
    string cadena1, cadena2, comando_string;
    do {
        opcion1 = menuPrincipal();
        switch (opcion1) {
            case 1:
                baseDeDatos->agregar_usuario();
                break;
            case 2:
                if (baseDeDatos->getUsuarios().empty()) {
                    cout << "No hay usuarios registrados en la base de datos." << endl;
                    break;
                }
                opcion2 = menuUsuarios(baseDeDatos->getUsuarios());
                do {
                    cout << "---- Cuantas semanas durará la rutina (como minimo 4): "; cin >> numero_semanas;
                } while (numero_semanas < 4);
                if (baseDeDatos->getUsuarios()[opcion2-1]->getPesoObjetivo() < baseDeDatos->getUsuarios()[opcion2-1]->getPeso())
                    cout << "----- Te recomendamos realizar ejercicios de Cardio y un poco de Flexibilidad -----" << endl;
                else
                    cout << "----- Te recomendamos realizar ejercicios de Fuerza y un poco de Cardio -----" << endl;
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
                                baseDeDatos->getUsuarios()[opcion2-1]->setMasaMuscular((rand()%2+1)/4); // si hace ejercicios de fuerza aumenta poco su masa muscular
                                aux_cardio->hallar_CQ_FC(baseDeDatos->getUsuarios()[opcion2-1]->getTmb(),baseDeDatos->getUsuarios()[opcion2-1]->getFcm());
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
                                baseDeDatos->getUsuarios()[opcion2-1]->setMasaMuscular((rand()%3+4)/3.5); // si hace ejercicios de fuerza aumenta su masa muscular
                                aux_fuerza->hallar_CQ_FC(baseDeDatos->getUsuarios()[opcion2-1]->getTmb(),baseDeDatos->getUsuarios()[opcion2-1]->getFcm());
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
                                aux_flexibilidad->hallar_CQ_FC(baseDeDatos->getUsuarios()[opcion2-1]->getTmb(),baseDeDatos->getUsuarios()[opcion2-1]->getFcm());
                                if (opcion6!=5)
                                    baseDeDatos->getUsuarios()[opcion2-1]->agregar_ejercicio(aux_flexibilidad);
                                cout << "-----CONSEJO : ";
                                Consejos_Generales();
                                cout << "------" << endl;
                            } while(opcion6!=5);
                            break;
                    }
                } while (opcion3!=4);
                calorias_semanales = 0;
                for (auto i : baseDeDatos->getUsuarios()[opcion2-1]->getEjercicios()) {
                    calorias_semanales += i->getCQE();
                }
                baseDeDatos->getUsuarios()[opcion2-1]->getHistorialCaloriasQuemadas().push_back(calorias_semanales);
                baseDeDatos->getUsuarios()[opcion2-1]->calorias_quemadas_rango(calorias_semanales,numero_semanas);
                baseDeDatos->getUsuarios()[opcion2-1]->actulizaciones_imcs(numero_semanas);
                baseDeDatos->getUsuarios()[opcion2-1]->meta_peso();
                baseDeDatos->getUsuarios()[opcion2-1]->meta_masa_muscular();
                break;
            case 3:
                if (baseDeDatos->getUsuarios().empty()) {
                    cout << "No hay usuarios registrados en la base de datos." << endl;
                    break;
                }
                opcion8 = menuUsuarios(baseDeDatos->getUsuarios());
                cadena1 = baseDeDatos->getUsuarios()[opcion8-1]->to_string_historial_calorias();
                cadena2 = baseDeDatos->getUsuarios()[opcion8-1]->to_string_historial_imcs();
                comando_string = "python ../scripts/Grafica.py -calorias " + cadena1 + " -imcs " + cadena2;
                system(comando_string.c_str());
                break;
            case 4:
                if (baseDeDatos->getUsuarios().empty()) {
                    cout << "No hay usuarios registrados en la base de datos." << endl;
                    break;
                }
                opcion7 = menuUsuarios(baseDeDatos->getUsuarios());
                baseDeDatos->getUsuarios()[opcion7-1]->reporte_individual();
                break;
            case 5:
                if (baseDeDatos->getUsuarios().empty()) {
                    cout << "No hay usuarios registrados en la base de datos." << endl;
                    break;
                }
                baseDeDatos->reporte_general();
                break;
            case 6:
                if (baseDeDatos->getUsuarios().empty()) {
                    cout << "No hay usuarios registrados en la base de datos." << endl;
                    break;
                }
                cout << "Reporte general exportado" << endl;
                baseDeDatos->exportarReportes();
                break;
            case 7:
                cout << "Saliendo del programa." << endl;
                // liberamos memoria
                delete baseDeDatos;
                break;
        }
    } while (opcion1 != 7);


    return 0;
}




