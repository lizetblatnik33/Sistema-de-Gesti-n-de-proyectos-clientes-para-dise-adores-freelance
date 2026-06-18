#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "archivos.h"

using namespace std;

//Leer una linea del csv
bool leerProyectoCSV(ifstream &archivo,
                     Proyecto &p) {

    string linea;

    //Leer linea completa
    if (!getline(archivo, linea)) {

        return false;
    }

    //Ignorar lineas vacias
    if (linea.empty()) {

        return false;
    }

    //Convertir linea en flujo
    stringstream ss(linea);

    // Leer campos separados por coma
    getline(ss, p.id,          ',');
    getline(ss, p.nombre,      ',');
    getline(ss, p.categoria,   ',');
    getline(ss, p.cliente,     ',');
    getline(ss, p.anio,        ',');
    getline(ss, p.presupuesto, ',');
    getline(ss, p.contacto,    ',');

    return true;
}

//Cargar proyectos desde el csv
void cargarProyectos(const string &nombreArchivo,
                     vector<Proyecto> &proyectos) {

    //Abrir archivo
    ifstream archivo(nombreArchivo);

    //Validar apertura
    if (!archivo) {

        cout << "Aviso: no se encontro el archivo '"
             << nombreArchivo
             << "'. Se iniciara con lista vacia."
             << endl;

        return;
    }

    Proyecto temp;

    //Leer archivo completo
    while (leerProyectoCSV(archivo, temp)) {

        proyectos.push_back(temp);
    }

    //Cerrar archivo
    archivo.close();
}

//Guardar proyectos en csv
void guardarProyectos(const string &nombreArchivo,
                      const vector<Proyecto> &proyectos) {

    //Crear/sobreescribir archivo
    ofstream archivo(nombreArchivo);

    //Validar creacion
    if (!archivo) {

        cout << "Error: no se pudo crear el archivo '"
             << nombreArchivo << "'."
             << endl;

        return;
    }

    //Recorrer vector y escribir
    for (int i = 0; i < (int)proyectos.size(); i++) {

        archivo << proyectos[i].id          << ","
                << proyectos[i].nombre      << ","
                << proyectos[i].categoria   << ","
                << proyectos[i].cliente     << ","
                << proyectos[i].anio        << ","
                << proyectos[i].presupuesto << ","
                << proyectos[i].contacto
                << endl;
    }

    //Cerrar archivo
    archivo.close();
}
