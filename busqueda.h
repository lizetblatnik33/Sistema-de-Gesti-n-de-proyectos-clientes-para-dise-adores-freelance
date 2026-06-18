#ifndef BUSQUEDA_H
#define BUSQUEDA_H

#include <vector>
#include <string>

#include "proyecto.h"

using namespace std;

//BUSQUEDA SECUENCIAL POR CATEGORIA
	//Recorre todo el vector y lista todos los proyectos
	//cuya categoria coincida con la buscada.
	//No requiere orden previo.
void busquedaSecuencialCategoria(const vector<Proyecto> &proyectos, const string &categoriaBuscada);

//BUSQUEDA BINARIA POR ID
	//Requiere que el vector este ordenado por id
	//Devuelve el indice del proyecto encontrado o -1 si no existe
int busquedaBinariaID(const vector<Proyecto> &proyectos, int izq, int der, const string &idBuscado);

// ====== MOSTRAR RESULTADO DE BUSQUEDA BINARIA ======
void mostrarResultadoBinaria(const vector<Proyecto> &proyectos,
                             int posicion);

#endif
