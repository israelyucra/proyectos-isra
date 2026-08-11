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

// setters
void Contacto::SetNombre(const char* nombre)
{
    strncpy(Nombre, nombre, sizeof(Nombre) - 1);
    Nombre[sizeof(Nombre) - 1] = '\0';
}
void Contacto::SetTelefono(const char* telefono)
{
    strncpy(Telefono, telefono, sizeof(Telefono) - 1);
    Telefono[sizeof(Telefono) - 1] = '\0';
}
void Contacto::SetEmail(const char* email)
{
    strncpy(Email, email, sizeof(Email) - 1);
    Email[sizeof(Email) - 1] = '\0';
}
void Contacto::SetDireccion(const char* direccion)
{
    strncpy(Direccion, direccion, sizeof(Direccion) - 1);
    Direccion[sizeof(Direccion) - 1] = '\0';
}
void Contacto::SetCategoria(const char* categoria)
{
    strncpy(Categoria, categoria, sizeof(Categoria) - 1);
    Categoria[sizeof(Categoria) - 1] = '\0';
}
void Contacto::SetEstado(bool estado) { Estado = estado; }

// Getters 
const char* Contacto::GetNombre() { return Nombre; }
const char* Contacto::GetTelefono() { return Telefono; }
const char* Contacto::GetEmail() { return Email; }
const char* Contacto::GetDireccion() { return Direccion; }
const char* Contacto::GetCategoria() { return Categoria; }
bool Contacto::GetEstado() { return Estado; }
