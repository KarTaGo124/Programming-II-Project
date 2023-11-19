//
//

#ifndef PROYECTO_CARDIO_H
#define PROYECTO_CARDIO_H

#include "Ejercicio.h"
class Cardio : public Ejercicio{
private:
    // atributos
    float duracion; // minutos
    float velocidad; // metros por segundo
public:
    // constructor
    Cardio();
    Cardio(string nombre);
    // destructor
    virtual ~Cardio() ;
    // metodos redefinidos
    void hallar_CQ_FC() override;
    void ingresar_datos() override;
    void mostrar_informacion() override;
};


#endif //PROYECTO_CARDIO_H
