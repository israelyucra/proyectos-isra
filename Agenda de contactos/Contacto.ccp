#pragma once
#include <string>

using namespace std;

class Contacto
{
private:
   char Nombre[50];
   char Telefono[50];
   char Email[50];
   char Direccion[50];
   char Categoria[50];
   bool Estado;
public:
   // constructores
   Contacto();
   Contacto(const char* _Nombre, const char* _Telefono, const char* _Email, const char* _Direccion, const char* _Categoria);

   // getters
   const char* GetNombre();
   const char* GetTelefono();
   const char* GetEmail();
   const char* GetDireccion();
   const char* GetCategoria();
   bool GetEstado();

   // setters
   void SetNombre(const char* nombre);
   void SetTelefono(const char* telefono);
   void SetEmail(const char* email);
   void SetDireccion(const char* direccion);
   void SetCategoria(const char* categoria);
   void SetEstado(bool estado);
   
  // metodo
  string ToString();
};
