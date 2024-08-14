#ifndef PROYECTO_EJERCICIO_H
#define PROYECTO_EJERCICIO_H
#include "../utils/Librerias.h"

class Ejercicio {
protected:
    string nombre; // nombre del tipo de ejercicio
    double FCE = 0; // frecuencia cardiaca por ejercicio
    double CQE = 0; // calorias quemadas por ejercicio
    string frecuencia; // frecuencia en la que realizamos el ejercicio (cada dia, semana, etc)
    double FA = 0; // factor de actividad (lo usaremos para el calculo de CQE)

public:
    // Destructor
    virtual ~Ejercicio() { cout << "Ejercicio destruido" << endl; }

    virtual void hallar_CQ_FC(double TBM, int FCM) = 0;

    virtual void ingresar_datos() = 0;

    virtual void mostrar_informacion() = 0;

    virtual void exportacion_informacion() = 0;

    double getFCE() { return FCE; }

    double getCQE()  { return CQE; }

    const string &getNombre() const {
        return nombre;
    }
};

#endif //PROYECTO_EJERCICIO_H
