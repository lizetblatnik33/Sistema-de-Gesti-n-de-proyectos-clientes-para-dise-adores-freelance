#include <iostream>
#include <vector>

#include "crud.h"

using namespace std;

// Mostrar un proyecto
void mostrarProyecto(const Proyecto &p, int numero) {

    cout << "\nProyecto #" << numero                 << endl;
    cout << "ID:          " << p.id                  << endl;
    cout << "Nombre:      " << p.nombre              << endl;
    cout << "Categoria:   " << p.categoria           << endl;
    cout << "Cliente:     " << p.cliente             << endl;
    cout << "Anio:        " << p.anio                << endl;
    cout << "Presupuesto: Bs. " << p.presupuesto     << endl;
    cout << "Contacto:    " << p.contacto            << endl;
    cout << "------------------------------------"    << endl;
}

// ====== CREAR PROYECTO ======
void crearProyecto(vector<Proyecto> &proyectos) {

    Proyecto p;

    cout << "\n===== NUEVO PROYECTO =====" << endl;

    cout << "Ingrese ID (ej: P001): ";
    getline(cin, p.id);

    cout << "Ingrese nombre del proyecto: ";
    getline(cin, p.nombre);

    cout << "Ingrese categoria" << endl;
    cout << "  (branding / UX / ilustracion / motion / web): ";
    getline(cin, p.categoria);

    cout << "Ingrese nombre del cliente: ";
    getline(cin, p.cliente);

    cout << "Ingrese anio del proyecto (ej: 2024): ";
    getline(cin, p.anio);

    cout << "Ingrese presupuesto en Bs. (ej: 1500): ";
    getline(cin, p.presupuesto);

    cout << "Ingrese gmail o red social del cliente: ";
    getline(cin, p.contacto);

    proyectos.push_back(p);

    cout << "\nProyecto registrado correctamente." << endl;
}

// ====== LISTAR PROYECTOS ======
void listarProyectos(const vector<Proyecto> &proyectos) {

    if (proyectos.empty()) {

        cout << "\nNo existen proyectos registrados." << endl;

        return;
    }

    cout << "\n===== LISTA DE PROYECTOS =====" << endl;

    for (int i = 0; i < (int)proyectos.size(); i++) {

        mostrarProyecto(proyectos[i], i + 1);
    }
}

// ====== MODIFICAR PROYECTO ======
void modificarProyecto(vector<Proyecto> &proyectos) {

    if (proyectos.empty()) {

        cout << "\nNo existen proyectos registrados." << endl;

        return;
    }

    string idBuscado;

    cout << "\nIngrese ID del proyecto a modificar: ";

    getline(cin, idBuscado);

    for (int i = 0; i < (int)proyectos.size(); i++) {

        if (proyectos[i].id == idBuscado) {

            cout << "\nProyecto encontrado. Ingrese nuevos datos:" << endl;
            cout << "(Deje en blanco y presione Enter para no cambiar un campo)\n" << endl;

            string temp;

            cout << "Nuevo nombre [" << proyectos[i].nombre << "]: ";
            getline(cin, temp);
            if (!temp.empty()) proyectos[i].nombre = temp;

            cout << "Nueva categoria [" << proyectos[i].categoria << "]: ";
            getline(cin, temp);
            if (!temp.empty()) proyectos[i].categoria = temp;

            cout << "Nuevo cliente [" << proyectos[i].cliente << "]: ";
            getline(cin, temp);
            if (!temp.empty()) proyectos[i].cliente = temp;

            cout << "Nuevo anio [" << proyectos[i].anio << "]: ";
            getline(cin, temp);
            if (!temp.empty()) proyectos[i].anio = temp;

            cout << "Nuevo presupuesto [" << proyectos[i].presupuesto << "]: ";
            getline(cin, temp);
            if (!temp.empty()) proyectos[i].presupuesto = temp;

            cout << "Nuevo contacto [" << proyectos[i].contacto << "]: ";
            getline(cin, temp);
            if (!temp.empty()) proyectos[i].contacto = temp;

            cout << "\nProyecto modificado correctamente." << endl;

            return;
        }
    }

    cout << "\nProyecto no encontrado." << endl;
}

// ====== ELIMINAR PROYECTO ======
void eliminarProyecto(vector<Proyecto> &proyectos) {

    if (proyectos.empty()) {

        cout << "\nNo existen proyectos registrados." << endl;

        return;
    }

    string idBuscado;

    cout << "\nIngrese ID del proyecto a eliminar: ";

    getline(cin, idBuscado);

    for (int i = 0; i < (int)proyectos.size(); i++) {

        if (proyectos[i].id == idBuscado) {

            proyectos.erase(proyectos.begin() + i);

            cout << "\nProyecto eliminado correctamente." << endl;

            return;
        }
    }

    cout << "\nProyecto no encontrado." << endl;
}
