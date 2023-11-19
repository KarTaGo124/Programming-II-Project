//
//

#ifndef PROYECTO_BASEDEDATOS_H
#define PROYECTO_BASEDEDATOS_H


#include "Usuario.h"

class BaseDeDatos {
private:
    vector<Usuario*> usuarios;
public:

    BaseDeDatos();

    void agregar_usuario();

    void reporte_general();

    void exportarReportes();

    bool existeUsuarioConDNI(const string& dni);

    vector<Usuario *> &getUsuarios();

    virtual ~BaseDeDatos();

};



#endif //PROYECTO_BASEDEDATOS_H
