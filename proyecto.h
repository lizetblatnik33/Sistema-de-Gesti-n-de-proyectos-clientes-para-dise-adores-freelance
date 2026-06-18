#ifndef PROYECTO_H
#define PROYECTO_H

#include <string>

using namespace std;

// ====== ESTRUCTURA PRINCIPAL ======
struct Proyecto {
    string id;
    string nombre;
    string categoria;   // branding / UX / ilustracion / motion / web
    string cliente;
    string anio;
    string presupuesto;
    string contacto;    // gmail o red social del cliente
};

#endif
