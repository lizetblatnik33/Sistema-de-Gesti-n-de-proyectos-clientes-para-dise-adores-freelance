#ifndef CRUD_H
#define CRUD_H

#include <vector>

#include "proyecto.h"

using namespace std;

//Prototipos CRUD

void crearProyecto(vector<Proyecto> &proyectos);

void listarProyectos(const vector<Proyecto> &proyectos);

void modificarProyecto(vector<Proyecto> &proyectos);

void eliminarProyecto(vector<Proyecto> &proyectos);

#endif
