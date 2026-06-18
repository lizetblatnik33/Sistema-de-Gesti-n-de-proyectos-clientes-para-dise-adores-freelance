#ifndef ORDENACION_H
#define ORDENACION_H

#include <vector>

#include "proyecto.h"

using namespace std;

// ====== PROTOTIPO ======
// Ordena el vector de proyectos por anio (ascendente)
// Implementa Bubble Sort con bandera de optimizacion
void ordenarPorAnio(vector<Proyecto> &proyectos);
// ====== ORDENAR POR ID (para busqueda binaria) ======
void ordenarPorID(vector<Proyecto> &proyectos);
#endif
