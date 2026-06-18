#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include <string>
#include <fstream>
#include <vector>

#include "proyecto.h"

using namespace std;

// leer proyecto desde csv
bool leerProyectoCSV(ifstream &archivo,
                     Proyecto &p);

// Cargar proyectos
void cargarProyectos(const string &nombreArchivo,
                     vector<Proyecto> &proyectos);

// Guardar proyectos
void guardarProyectos(const string &nombreArchivo,
                      const vector<Proyecto> &proyectos);

#endif
