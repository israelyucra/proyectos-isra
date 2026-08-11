#include <iostream>
#include "Agenda.h"
#include "Contacto.h"
#include <cstring>
#include <cstdio>
#include <limits> // para el numeric_limits del cin.ignore


using namespace std;

// constructor
Agenda::Agenda()
{
    strcpy(rutaDeArchivo,"RegistroDeContactos.dat");
    tamanioDeArchivo = sizeof(Contacto);
}
