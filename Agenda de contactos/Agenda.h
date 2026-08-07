#pragma once
#include "Contacto.h"

class Agenda
{
    private:
        char rutaDeArchivo[50];
        int tamanioDeArchivo;
    public:
        // constructor
        Agenda();
        /*        -- ABML --        */

        // Alta
        void AgregarContacto(Contacto &contacto);
        //Baja logica
        void BajaDeContacto(Contacto &contacto);// baja logica
        //Modificar contacto
        void ModificarNombreContacto(Contacto &contacto);
        void ModificarTelefonoContacto(Contacto &contacto);
        void ModificarEmailContacto(Contacto &contacto);
        void ModificarDireccionContacto(Contacto &contacto);
        void ModificarCategoriaContacto(Contacto &contacto);
        // listados
        void MostrarSegunEstado(bool estado);
        void MostrarSegunCategoria(string categoria);

        // Manipulacion de archivos
        bool CargarEnArchivo(Contacto contacto);
        bool SobreescribirEnArchivo(Contacto contacto,int posicion);
        int BuscarContacto(char* nombre);// devuelve posicion
        bool LeerContacto(int posicion, Contacto &contacto);

        
        // backup
        /* el guardado es de todo el .dat */ 
        void RealizarCopiaDeSeguridad();
        void RestaurarUltimaCopia();

        //metodos generales
        void LeerCampo(char* campo, int tam);
};
