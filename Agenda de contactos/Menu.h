#pragma once
#include "Contacto.h"

class MenuPrincipal {
private:
    int Opcion;
    bool Salir;
public:
    MenuPrincipal();
    void EjecutarMenu();
    void MostrarMenu(); 
    void ElegirOpcion();
    void EjecutarOpcion();
};
