//
//

#include <iostream>
using namespace std;

// calculadora cardio
/*
int main() {
    double frecuenciaCardiaca;
    double caloriasQuemadas;
    string frecuenciaEjercicio;
    int duracionMinutos;
    double velocidad;
    int diasSemana;

    cout << "Ingrese la frecuencia cardiaca por ejercicio: ";
    cin >> frecuenciaCardiaca;

    cout << "Ingrese las calorías quemadas por ejercicio: ";
    cin >> caloriasQuemadas;

    cout << "Ingrese la frecuencia del ejercicio (diaria, semanal, etc.): ";
    cin >> frecuenciaEjercicio;

    cout << "Ingrese la duración del ejercicio en minutos: ";
    cin >> duracionMinutos;

    cout << "Ingrese la velocidad del ejercicio: ";
    cin >> velocidad;

    if (frecuenciaEjercicio == "diaria") {
        diasSemana = 7;
    } else if (frecuenciaEjercicio == "semanal") {
        cout << "Ingrese la cantidad de días a la semana que realiza el ejercicio: ";
        cin >> diasSemana;
    } else if (frecuenciaEjercicio == "mensual") {
        diasSemana = 30;
    }

    double caloriasTotales = (caloriasQuemadas * duracionMinutos * velocidad * diasSemana) / frecuenciaCardiaca;

    cout << "Las calorías totales quemadas por ejercicio de cardio son: " << caloriasTotales << endl;

    return 0;
}
*/

// calculadora fuerza
/*
int main() {
    double frecuenciaCardiaca;
    double caloriasQuemadas;
    string frecuenciaEjercicio;
    int repeticiones;
    int series;
    double peso;
    int vecesSemana;
    int vecesMes;

    cout << "Ingrese la frecuencia cardiaca por ejercicio: ";
    cin >> frecuenciaCardiaca;

    cout << "Ingrese las calorías quemadas por ejercicio: ";
    cin >> caloriasQuemadas;

    cout << "Ingrese la frecuencia del ejercicio (diaria, semanal, mensual): ";
    cin >> frecuenciaEjercicio;

    cout << "Ingrese el número de repeticiones del ejercicio: ";
    cin >> repeticiones;

    cout << "Ingrese el número de series del ejercicio: ";
    cin >> series;

    cout << "Ingrese el peso con el que realiza el ejercicio de fuerza: ";
    cin >> peso;

    if (frecuenciaEjercicio == "diaria") {
        vecesSemana = 7;
        vecesMes = 30;
    } else if (frecuenciaEjercicio == "semanal") {
        cout << "Ingrese la cantidad de veces a la semana que realiza el ejercicio: ";
        cin >> vecesSemana;
        vecesMes = vecesSemana * 4;
    } else if (frecuenciaEjercicio == "mensual") {
        cout << "Ingrese la cantidad de veces al mes que realiza el ejercicio: ";
        cin >> vecesMes;
        vecesSemana = vecesMes / 4;
    }

    double caloriasTotales = (caloriasQuemadas * repeticiones * series * vecesSemana) / frecuenciaCardiaca;
    double pesoPerdido = (peso * repeticiones * series * vecesMes) / 3500.0; // Suponiendo que 3500 calorías equivalen a 1 libra de peso

    cout << "Las calorías totales quemadas por ejercicio de fuerza son: " << caloriasTotales << endl;
    cout << "El peso perdido por ejercicio de fuerza es: " << pesoPerdido << " libras" << endl;

    return 0;
}

*/

// calculadora flexibilidad
//[por hacer]