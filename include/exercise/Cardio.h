//
//

#ifndef PROYECTO_CARDIO_H
#define PROYECTO_CARDIO_H

#include "Ejercicio.h"
class Cardio : public Ejercicio{
private:
    // atributos
    float duracion; // minutos
    float velocidad; // kilometros por hora
public:
    // constructores
    Cardio();
    Cardio(string nombre);
    // destructor
    virtual ~Cardio() ;
    // metodos redefinidos
    void hallar_CQ_FC(double TBM, int FCM) override;
    void ingresar_datos() override;
    void mostrar_informacion() override;
    void exportacion_informacion() override;

};


#endif //PROYECTO_CARDIO_H
