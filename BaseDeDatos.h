//
// Created by Guillermo Galvez on 15/11/2023.
//

#ifndef PROYECTO_BASEDEDATOS_H
#define PROYECTO_BASEDEDATOS_H


#include "Usuario.h"

class BaseDeDatos {
private:
    vector<Usuario> usuarios;
public:
    BaseDeDatos();

    void reporte_general();

    void exportarReportes();

    virtual ~BaseDeDatos();

};


#endif //PROYECTO_BASEDEDATOS_H
