#include <iostream>
#include <string>
#include <cstring>
#include "Contacto.h"

using namespace std;


// Constructores
Contacto::Contacto() 
{
    Estado = true;
}

Contacto::Contacto(const char* _Nombre, const char* _Telefono, const char* _Email, const char* _Direccion, const char* _Categoria)
{
    SetNombre(_Nombre);
    SetTelefono(_Telefono);
    SetEmail(_Email);
    SetDireccion(_Direccion);
    SetCategoria(_Categoria);
    Estado = true;
}
