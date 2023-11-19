//
// Created by PC on 19/11/2023.
//

#include "CMET.h"

CMET::CMET() {}

CMET::CMET(const std::string &nombre, float met) {
    this->nombre = nombre;
    this->met.push_back(met);
}

CMET::CMET(const string &nombre, float met1, float met2, float met3) {
    this->nombre = nombre;
    met.push_back(met1);
    met.push_back(met2);
    met.push_back(met3);
}

const string &CMET::getNombre() const {
    return nombre;
}

float CMET::getMet() const {
    return met[0];
}

float CMET::getMet(int dificultad) {
    return met[dificultad-1];
}

CMET::~CMET() {

}

