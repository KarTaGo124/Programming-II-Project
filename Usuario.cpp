//
// Created by Guillermo Galvez on 15/11/2023.
//

#include "Usuario.h"


Usuario:: Usuario(){}

Usuario:: Usuario(string n,string g,string a,int al,float macular, float p, float p_o){

    this->nombre=n;
    this->genero=g;
    this->peso=p;
    this->peso_objetivo=p_o;
    this->apellido=a;
    this ->altura=al;
    this ->masa_muscular=macular;

}
Usuario:: Usuario(string _n):nombre(_n){}

void Usuario:: validar_usuario(){
    if (nombre.length()==0){cout<<"Error : El nombre no puede estar vacio "<<endl;return;}

    if (genero!="Masculino" || genero!="Femenino"){cout<<"Error : El genero debe ser 'Masculino' o 'Femenino'."<<endl;return;}
    if (peso <=0 || peso_objetivo<=0){cout<<"Error: El peso y el peso objetivo deben ser valores positivos ."<<endl;}

    cout<<"Usuario validado correctamente "<<endl;
}

void Usuario::  agregar_ejercicio(Ejercicio* ejercicio){
    actividades.push_back(ejercicio);
}

float Usuario:: calcular_IMC(){
    return peso/(pow(altura,2));
}

float Usuario:: frecuencia_cardiaca_prom(){
    float promedio=0;
    for (int i = 0; i < actividades.size() ;++i) {
            promedio+=actividades[i]->getFCE();
    }
    return promedio=promedio/actividades.size();

}

void Usuario:: mostrar_info_principal_usuario(){}

const string &Usuario::getNombre() const {
    return nombre;
}

const string &Usuario::getApellido() const {
    return apellido;
}
