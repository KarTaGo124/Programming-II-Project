//
// Created by Guillermo Galvez on 15/11/2023.
//

#include "BaseDeDatos.h"

#include "Librerias.h"

BaseDeDatos:: BaseDeDatos(){
    Usuario inicial("NN","")
}

void BaseDeDatos::reporte_general() {
    for(auto i: usuarios){
        i->reporte_individual();
    }
}
void BaseDeDatos::  exportarReportes(){}

bool BaseDeDatos::existeUsuarioConDNI(const string& dni) {
    for (const auto &i : usuarios) {
        if (i->getDNI() == dni) {
            return true;
        }
    }
    return false;
}

BaseDeDatos::~BaseDeDatos() {
    for (auto i: usuarios)
    {
        delete i;
    }

}

const vector<Usuario *> &BaseDeDatos::getUsuarios() const {
    return usuarios;
}


