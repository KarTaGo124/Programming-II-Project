#ifndef PROYECTO_FLEXIBILIDAD_H
#define PROYECTO_FLEXIBILIDAD_H

#include "Ejercicio.h"

class Flexibilidad : public Ejercicio{
private:
    // atributos
    int duracion; // minutos
    string dificultad;  // facil media o dificil
public:
    // constructores
    Flexibilidad();
    Flexibilidad(string nombre);
    // destructor
    virtual ~Flexibilidad();
    // metodos redefinidos
    void ingresar_datos() override;
    void mostrar_informacion() override;
    void exportacion_informacion() override;
    void hallar_CQ_FC(double TBM, int FCM) override;
};

#endif //PROYECTO_FLEXIBILIDAD_H
