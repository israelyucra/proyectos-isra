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
// agregar contacto
void Agenda::AgregarContacto(Contacto &contacto)
{
    cin.ignore();
    char _Nombre[50], _Telefono[50], _Email[50], _Direccion[50], _Categoria[50];
    int op;
    bool repetir = true;

    cout << "------------------------------------ " << endl;
    cout << "   Ingrese los datos del contacto " << endl;
    cout << "------------------------------------ " << endl;
    cout << "Nombre: ";
    LeerCampo(_Nombre,sizeof(_Nombre));

    cout << "Telefono: ";
   LeerCampo(_Telefono,sizeof(_Telefono));

    cout << "Email: ";
    LeerCampo(_Email,sizeof(_Email));

    cout << "Direccion: ";
    LeerCampo(_Direccion,sizeof(_Direccion));

    cout << "Categoria: (1-Amigo, 2-Trabajo, 3-Familia)";
    while (repetir){
        cin >> op;
        if (cin.fail()) 
        {
            cin.clear();
            cin.ignore(10000, '\n');
            op = -1;
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            /*
                Esto descarta todos los caracteres hasta el salto de línea, no solo uno,
                esto da seguridad para usar el getline.
            */
        }

        switch (op) {
        case 1:
            strcpy(_Categoria, "Amigo");
            repetir = false;
            break;
        case 2:
            strcpy(_Categoria,"Trabajo");
            repetir = false;
            break;
        case 3:
            strcpy(_Categoria,"Familia");
            repetir = false;
            break;
        default:
            cout << "Seleccione una opcion valida(1,2 o 3)." << endl;
            repetir = true;
            break;
        }
    }

    cout << "Estado: Vigente" << endl;

    contacto.SetNombre( _Nombre);
    contacto.SetTelefono(_Telefono);
    contacto.SetEmail(_Email);
    contacto.SetDireccion(_Direccion);
    contacto.SetCategoria(_Categoria);
    contacto.SetEstado(true);
}

// baja logica
void Agenda::BajaDeContacto(Contacto &contacto)
{
    bool NuevoEstado = contacto.GetEstado();
    char entrada;
    bool repetir = true;
    cout << "Estado actual: ";
    if (contacto.GetEstado())
    {
        cout << "Vigente" << endl;
    }
    else
    {
        cout << "Suspendido" << endl;
    }

    cout << "Ingrese nuevo estado [v-Vigente / s-Suspendido / c-cancelar]: ";
    while (repetir)
    {
        cin >> entrada;

        entrada = tolower(entrada); // convierte en minuscula

        switch (entrada)
        {
        case 'v':
            NuevoEstado = true;
            repetir = false;
            break;
        case 's':
            NuevoEstado = false;
            repetir = false;
            break;
        case 'c':
            repetir = false;
            break;
        default:
            cout << "Entrada inválida. Solo 'v', 's' o 'c' ." << endl;
            break; // vuelve a pedir
        }
    }

    contacto.SetEstado(NuevoEstado);
}

// modificaciones
void Agenda::ModificarNombreContacto(Contacto &contacto)
{
    char nuevoNombre[50];
    cout << "Nuevo Nombre: ";
    LeerCampo(nuevoNombre,50);
    contacto.SetNombre(nuevoNombre);
}

void Agenda::ModificarTelefonoContacto(Contacto &contacto)
{
    char nuevoTelefono[50];
    cout << "Nuevo Telefono: ";
    LeerCampo(nuevoTelefono,50);
    contacto.SetTelefono(nuevoTelefono);
}

void Agenda::ModificarEmailContacto(Contacto &contacto)
{
    char nuevoEmail[50];
    cout << "Nuevo Email: ";
    LeerCampo(nuevoEmail,50);
    contacto.SetEmail(nuevoEmail);
}

void Agenda::ModificarDireccionContacto(Contacto &contacto)
{
    char nuevaDireccion[50];
    cout << "Nueva Direccion: ";
    LeerCampo(nuevaDireccion,50);
    contacto.SetDireccion(nuevaDireccion);
}

void Agenda::ModificarCategoriaContacto(Contacto &contacto)
{
    bool repetir = true;
    int op;
    while (repetir){
        cout << "Categoria: (1-Amigo, 2-Trabajo, 3-Familia 0-volver)" << endl;
        cin >> op;
        if (cin.fail()) 
        {
            cin.clear();
            cin.ignore(10000, '\n');
            op = -1;
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            /*
                Esto descarta todos los caracteres hasta el salto de línea, no solo uno,
                esto da seguridad para usar el getline.
            */
        }

        switch (op) {
        case 1:
            contacto.SetCategoria("Amigo");
            repetir = false;
            break;
        case 2:
            contacto.SetCategoria("Trabajo");
            repetir = false;
            break;
         case 3:
            contacto.SetCategoria("Familia");
            repetir = false;
            break;
        case 0: //volver
            repetir = false;
            break;
        default:
            cout << "Seleccione una opcion valida(1,2 o 3)." << endl;
            repetir = true;
            break;
        }
    }
}

// listado
void Agenda::MostrarSegunEstado(bool estado)
{
    Contacto contacto;
    FILE* p = fopen(rutaDeArchivo,"rb");
    if(p == nullptr)
    {
        cout << "Error de Apertura." << endl;
        return;
    }
    int pos = 0;
    while(fread(&contacto,tamanioDeArchivo,1,p))
    {
        if(contacto.GetEstado() == estado)
        {
            pos ++;
            cout << "============================" << endl;
            cout << "Contacto nro. " << pos << endl;
            cout << "============================" << endl;
            cout << contacto.ToString() << endl << endl;
        }
    }
    fclose(p);
}

void Agenda::MostrarSegunCategoria(string categoria)
{
    // los amigos que muestro son solo activos
    Contacto contacto;
    FILE* p = fopen(rutaDeArchivo,"rb");
    if(p == nullptr)
    {
        cout << "Error de Apertura." << endl;
        return;
    }
    while(fread(&contacto,tamanioDeArchivo,1,p))
    {
        if(contacto.GetCategoria() == categoria && contacto.GetEstado() == true)
        {
            cout << contacto.ToString() << endl;
        }
    }
    fclose(p);
}

// Manipulacion de archivos
bool Agenda::CargarEnArchivo(Contacto contacto)
{
    // Apertura del puntero
    FILE* p = fopen(rutaDeArchivo,"ab+");// abre, si no existe crea
    if(p == nullptr) // verificacion
    {
        cout << "Error de Apertura." << endl;
        return false;
    }
    // grabado en archivo
    bool grabado = fwrite(&contacto,tamanioDeArchivo,1,p);
    //Cierre del puntero
    fclose(p);
    return grabado;
}

bool Agenda::SobreescribirEnArchivo(Contacto contacto,int posicion)
{
    FILE* p = fopen(rutaDeArchivo,"rb+");// sobre escribe sobre posicion
    if(p == nullptr) // verificacion
    {
        cout << "Error de Apertura." << endl;
        return false;
    }
    fseek(p,posicion*tamanioDeArchivo,SEEK_SET);
    bool grabado = fwrite(&contacto,tamanioDeArchivo,1,p);
    fclose(p);
    return grabado;
}

int Agenda::BuscarContacto(char* nombre)
{
    //NOTA: .c_str() convierte un std::string en un const char* para que strcmp lo pueda leer.
    Contacto contacto;
    FILE* p = fopen(rutaDeArchivo,"rb");
    if(p == nullptr) // verificacion
    {
        cout << "Error de Apertura." << endl;
        return -1;
    }
    int posicion = 0;
    while(fread(&contacto,tamanioDeArchivo,1,p))
    {
        if(!strcmp(nombre,contacto.GetNombre()))
        {
            fclose(p);
            return posicion;
        }
        posicion++;
    }
    fclose(p);
    return -1;
}

bool Agenda::LeerContacto(int posicion, Contacto &contacto)
{
    FILE* p = fopen(rutaDeArchivo,"rb");
    if(p == nullptr) // verificacion
    {
        cout << "Error de Apertura." << endl;
        return false;
    }
    fseek(p,posicion*tamanioDeArchivo,SEEK_SET);
    if(fread(&contacto,tamanioDeArchivo,1,p) != 1) // si no lee 1 registro devuelve galso
    {
        fclose(p);
        return false;
    }
    fclose(p);
    return true;
}

// backup
void Agenda::RealizarCopiaDeSeguridad()
{
    Contacto contacto;
    FILE* p = fopen(rutaDeArchivo,"rb");
    FILE* pRespaldo = fopen("CopiaDeRespaldo.dat","wb");
    if(p == nullptr || pRespaldo == nullptr)
    {
        cout << "Error de Apertura." << endl; 
        // en caso que falle la apertura de uno cierro los 2.
        if(p)
        {
            fclose(p);
        }
        if(pRespaldo)
        {
            fclose(pRespaldo);
        }
        return;
    }
    while(fread(&contacto,tamanioDeArchivo,1,p))
    {
        fwrite(&contacto,tamanioDeArchivo,1,pRespaldo);
    }
    cout << "Exito, Se realizo la copia de Respaldo." << endl;
    fclose(p);
    fclose(pRespaldo);
}

void Agenda::RestaurarUltimaCopia()
{
    Contacto contacto;
    FILE* p = fopen(rutaDeArchivo,"wb");
    FILE* pRespaldo = fopen("CopiaDeRespaldo.dat","rb");
    if(p == nullptr || pRespaldo == nullptr)
    {
        cout << "Error de Apertura." << endl; 
        // en caso que falle la apertura de uno cierro los 2.
        if(p)
        {
            fclose(p);
        }
        if(pRespaldo)
        {
            fclose(pRespaldo);
        }
        return;
    }
    while(fread(&contacto,tamanioDeArchivo,1,pRespaldo))
    {
        fwrite(&contacto,tamanioDeArchivo,1,p);
    }
    cout << "Exito, Se restaruro la ultima copia de respaldo." << endl;
    fclose(p);
    fclose(pRespaldo);
}

// metodos
void Agenda::LeerCampo(char* campo, int tam)
{
    do
    {
        cin.getline(campo,tam);
        if (strlen(campo) == 0)
        {
            cout << "El campo no puede estar vacio." << endl;
        }
    } while (strlen(campo) == 0);
}
