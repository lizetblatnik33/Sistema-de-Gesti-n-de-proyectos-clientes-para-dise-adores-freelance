#ifndef INTERCALACION_H
#define INTERCALACION_H

#include <vector>

#include "proyecto.h"

using namespace std;

// Intercala dos vectores de proyectos ordenados por anio
// y devuelve un nuevo vector resultado ordenado por anio.
vector<Proyecto> intercalarProyectos(
                     const vector<Proyecto> &v1,
                     const vector<Proyecto> &v2);

#endif
