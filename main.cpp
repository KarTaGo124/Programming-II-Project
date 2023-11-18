#include <iostream>

#include "Flexibilidad.h"
#include "Fuerza.h"
#include "Cardio.h"
#include "BaseDeDatos.h"
#include "Menus.h"

// falta implementar las graficas(nose)
// la calculadora de calorias(esto no se) y frecuencia cardiaca(podria ser un rand)
// falta agregar la parte de calculos realizados al reporte individual
// idea para mostrar el progreso en el reporte individual:
// podriamos preguntar al usuario cuantas semanas han pasado desde que esta haciendo ejercicio y generar las graficas a partir de ello
// como minimo 1 mes es decir 4 semanas ya que podemos argumentar que en menos de 1 mes no se generan resultados
// implementar un mensaje que avise cuando llegas al peso objetivo y porcentaje masa muscular o grasa corporal deseado
// implementar consejos dependiendo del tipo de dieta que quieres hacer (subir o bajar peso)
// si quiere subir de peso o masa muscular se le recomienda fuerza
// si quiere bajar de peso o grasa corporal se le recomienda cardio
// se le recomienda agregar a la rutina al menos uno de flexibilidad para complementar
int main() {
    auto* baseDeDatos = new BaseDeDatos();  // Crear una instancia de la base de datos

    int opcion1, opcion2, opcion3, opcion4, opcion5, opcion6, opcion7;

    do {
        opcion1 = menuPrincipal();
        switch (opcion1) {
            case 1:
                baseDeDatos->agregar_usuario();
                break;
            case 2:
                opcion2 = menuUsuarios(baseDeDatos->getUsuarios());
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
                                if (opcion4!=5)
                                    baseDeDatos->getUsuarios()[opcion2-1]->agregar_ejercicio(aux_cardio);
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
                                if (opcion5!=6)
                                    baseDeDatos->getUsuarios()[opcion2-1]->agregar_ejercicio(aux_fuerza);
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
                                if (opcion6!=5)
                                    baseDeDatos->getUsuarios()[opcion2-1]->agregar_ejercicio(aux_flexibilidad);
                            } while(opcion6!=5);
                            break;
                    }
                } while (opcion3!=4);
                break;
            case 3:
                opcion7 = menuUsuarios(baseDeDatos->getUsuarios());
                baseDeDatos->getUsuarios()[opcion7-1]->reporte_individual();
                break;
            case 4:
                baseDeDatos->reporte_general();
                break;
            case 5:
                baseDeDatos->exportarReportes();
                break;
            case 6:
                cout << "Saliendo del programa." << endl;
                break;

            default:
                cout << "Opción no válida. Inténtelo de nuevo." << endl;
        }
    } while (opcion1 != 6);



    return 0;
}



