//
// Created by PC on 19/11/2023.
//

#ifndef PROYECTO_CMET_H
#define PROYECTO_CMET_H

#include <iostream>
#include <vector>
using namespace std;
class CMET {
protected:
    string nombre;
    vector<float> met;
public:
    CMET();

    CMET(const string &nombre, float met);

    CMET(const string &nombre, float met1, float met2, float met3);

    const string &getNombre() const;

    float getMet() const;

    float getMet(int dificultad) ;

    virtual ~CMET();
};


#endif //PROYECTO_CMET_H
