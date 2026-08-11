#include <iostream>
#include "Menu.h"
#include "Agenda.h"
#include "Contacto.h"
#include <cstring>

using namespace std;

MenuPrincipal::MenuPrincipal()
{
    Salir = false;
}

void MenuPrincipal::EjecutarMenu()
{
    while(!Salir)
    {
        system("cls");
        MostrarMenu();
        ElegirOpcion();
        EjecutarOpcion();
    }
}

void MenuPrincipal::MostrarMenu()
{
    cout <<  "                      ============================= " << endl;
    cout <<  "                           AGENDA DE CONTACTOS " << endl;
    cout <<  "                      ============================= " << endl;
    cout <<  "                      1. Agregar contacto. " << endl;
    cout <<  "                      2. Mod. estado de contacto. " << endl;
    cout <<  "                      3. Modificacion de contacto. " << endl;
    cout <<  "                      4. Listado de contactos. " << endl;
    cout <<  "                      5. Buscar contacto. " << endl;
    cout <<  "                      6. Backup. " << endl << endl;
    cout <<  "                      0. Salir. " << endl;
    cout <<  "                      ============================= " << endl;

}

void  MenuPrincipal::ElegirOpcion()
{
    cout << ">> ";
    cin >> Opcion;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(10000,'\n');
        Opcion = -1;
    }
}

void MenuPrincipal::EjecutarOpcion()
{
    
    Contacto contacto;
    Agenda agenda;
    bool grabado;
    char contactobuscado[50];
    int posicion;
    char claveDeAcceso[6]{'9','1','2','1','8'};
    char ClaveIngresada[6];
    switch (Opcion)
    {
    case 1:
        /* Alta de contacto */
        system("cls");
        agenda.AgregarContacto(contacto);
        grabado =  agenda.CargarEnArchivo(contacto);
        if(grabado)
        {
            cout << "Exito al cargar registro." << endl;
        }
        else
        {
            cout << "Error al cargar registro." << endl;
        }
        system("pause");
        break;
    case 2:
        /* Baja de contacto */
        system("cls");
        cin.ignore();
        cout << "que contacto desea dar de baja?(0-volver) " << endl;
        do{
            cin.getline(contactobuscado,50);
            if(!strcmp(contactobuscado,"0"))
            {
                return;
            }
            if(strlen(contactobuscado) == 0)
            {
                cout << "debe completar el campo." << endl;
            }
        }while(strlen(contactobuscado) == 0);
        posicion = agenda.BuscarContacto(contactobuscado);
        if(posicion == -1)
        {
            cout << "Contacto no encontrado." << endl;
            system("pause");
            break;
        }
        agenda.LeerContacto(posicion,contacto);
        agenda.BajaDeContacto(contacto);
        grabado = agenda.SobreescribirEnArchivo(contacto,posicion);
        if(grabado)
        {
            cout << "Exito al modificar Estado del registro." << endl;
        }
        else
        {
            cout << "Error al modificar Estado del registro." << endl;
        }
        system("pause");
        break;
    case 3:
        /* Modicar */
        system("cls");
        cin.ignore();
        cout << "que contacto desea modificar?(0-volver) " << endl;
        do{
            cin.getline(contactobuscado,50);
            if(!strcmp(contactobuscado,"0"))
            {
                return;
            }
            if(strlen(contactobuscado) == 0)
            {
                cout << "debe completar el campo." << endl;
            }
        }while(strlen(contactobuscado) == 0);
        posicion = agenda.BuscarContacto(contactobuscado);
        if(posicion == -1)
        {
            cout << "Contacto no encontrado." << endl;
            system("pause");
            break;
        }
        agenda.LeerContacto(posicion,contacto);
        MenuModificar(contacto,posicion);
        system("pause");
        break;
    case 4:
        /* Listado de contactos */
        MenuListar();
        break;
    case 5:
        /* Buscar contacto */
        system("cls");
        cin.ignore();
        cout << "que contacto desea Busar?" << endl;
        do{
            cin.getline(contactobuscado,50);
            if(!strcmp(contactobuscado,"0"))
            {
                return;
            }
            if(strlen(contactobuscado) == 0)
            {
                cout << "debe completar el campo." << endl;
            }
        }while(strlen(contactobuscado) == 0);
        posicion = agenda.BuscarContacto(contactobuscado);
        if(posicion == -1)
        {
            cout << "Contacto no encontrado." << endl;
            system("pause");
            break;
        }
        agenda.LeerContacto(posicion,contacto);
        cout << contacto.ToString() << endl;
        system("pause");
        break;
    case 6:
        /* Backup */
        system("cls");
        cin.ignore();
        cout << "Ingrese su clave para acceder al menu de backup >> " ;
        cin.getline(ClaveIngresada,sizeof(ClaveIngresada));
        if(!strcmp(ClaveIngresada,claveDeAcceso))
        {
            MenuBackup();
        }
        else
        {
            system("cls");
            cout << "Clave Incorrecta." << endl;
            system("pause");
            return;     
        }
        break;
    case 0:
        Salir = true;
        cout << "finalizando programa...hasta luego" << endl;
        break;
    default:
        system("cls");
        cout << "opcion incorrecta. " << endl;
        system("pause");
        break;
    }
}

void MenuPrincipal::MenuModificar(Contacto &contacto, int pos)
{
    int opcion;
    bool repetir = true;
    Agenda agenda;

    while (repetir)
    {
        system("cls");
        cout << contacto.ToString()  << endl;    
        cout << "                      ========================== " << endl;
        cout << "                       Modificacion de Contacto" << endl;
        cout << "                      ========================== " << endl;
        cout << "                           1. Nombre" << endl;
        cout << "                           2. Telefono" << endl;
        cout << "                           3. Email" << endl;
        cout << "                           4. Direccion" << endl;
        cout << "                           5. Categoria" << endl;
        cout << "                           0. Volver" << endl;
        cout << "                      ========================== " << endl;
        cout << ">> ";
        cin >> opcion;

        // Validación de entrada
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            opcion = -1;
        }

        switch (opcion)
        {
            case 1:
                // modificar nombre
                agenda.ModificarNombreContacto(contacto);
                repetir = false;
                break;
            case 2:
                // modificar teléfono
                agenda.ModificarTelefonoContacto(contacto);
                repetir = false;
            break;
            case 3:
                // modificar email
                agenda.ModificarEmailContacto(contacto);
                repetir = false;
            break;
            case 4:
                // modificar dirección
                agenda.ModificarDireccionContacto(contacto);
                repetir = false;
            break;
            case 5:
                // modificar categoría
                agenda.ModificarCategoriaContacto(contacto);
                repetir = false;
            break;
            case 0:
                repetir = false;
                return;
            break;
            default:
                cout << "Opción inválida. Intente nuevamente." << endl;
            break;
        }
        bool grabado = agenda.SobreescribirEnArchivo(contacto,pos);
        if(grabado)
        {
            cout << "Exito de grabado." << endl;
        }
        else
        {
            cout << "Error de grabado." << endl;
        }
    }
}

void MenuPrincipal::MenuListar()
{
    cin.ignore();
    int opcion;
    bool repetir = true;
    Agenda agenda;
    while (repetir)
    {
        system("cls");
        cout << "                     ====================== " << endl;
        cout << "                        LISTAR CONTACTOS " << endl;
        cout << "                     ====================== " << endl;
        cout << "                      1. Vigentes. " << endl;
        cout << "                      2. suspendidos. " << endl;
        cout << "                      0. Volver." << endl;
        cout << "                     ====================== " << endl;
        cout << ">> ";
        cin >> opcion;
        // Validación de entrada
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            opcion = -1;
        }
        switch (opcion)
        {
        case 1:
            system("cls");
            agenda.MostrarSegunEstado(true);
            repetir = false;          
        break;
        case 2:
            system("cls");
            agenda.MostrarSegunEstado(false);
            repetir = false;
        break;
        case 0:
            repetir = false;
        break;
        default:
        system("cls");
            cout << "Opción inválida. Intente nuevamente." << endl;
            break;
        }
        system("pause");
    }
}

void MenuPrincipal::MenuBackup()
{
    bool continuar = true;
    int opcion;
    Agenda agenda;
    while (continuar)
    {
        system("cls");
        cout <<  "                      ============================== " << endl;
        cout << "                                MENU BACKUP" << endl;
        cout <<  "                      ============================== " << endl;
        cout << "                       1. Realizar copia de seguridad" << endl;
        cout << "                       2. Restaurar ultima copia" << endl;
        cout << "                       0. Volver" << endl;
        cout <<  "                      ============================== " << endl;
        cout << ">> ";
        cin >> opcion;

        // Control de error de entrada
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            opcion = -1;
        }

        switch (opcion)
        {
            case 1:
                agenda.RealizarCopiaDeSeguridad();            
                continuar = false;
                break;

            case 2:
                agenda.RestaurarUltimaCopia();
                continuar = false;
                break;

            case 0:
                continuar = false; 
                break;

            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
                break;
        }
        system("pause");
    }
}
