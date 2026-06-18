#include <iostream>
#include <vector>

#include "ordenacion.h"

using namespace std;

//BUBBLE SORT OPTIMIZADO ANIO 
void ordenarPorAnio(vector<Proyecto> &proyectos) {

    //Variable auxiliar para intercambio
    Proyecto aux;

    //Bandera de optimizacion
    bool huboIntercambio;

    //Recorrer el vector
    for (int i = 0; i < (int)proyectos.size() - 1; i++) {

        huboIntercambio = false;

        //Comparar elementos adyacentes
        for (int j = 0; j < (int)proyectos.size() - i - 1; j++) {

            //Comparar anios (orden ascendente)
            if (proyectos[j].anio > proyectos[j + 1].anio) {

                //Intercambio completo del struct
                aux = proyectos[j];

                proyectos[j] = proyectos[j + 1];

                proyectos[j + 1] = aux;

                huboIntercambio = true;
            }
        }

        //Si no hubo intercambio, el vector ya esta ordenado
        if (!huboIntercambio) {

            break;
        }
    }
}

//Ordenar por Id, bubble sort para habilitar busqueda binaria
void ordenarPorID(vector<Proyecto> &proyectos) {

    Proyecto aux;
    bool huboIntercambio;

    for (int i = 0; i < (int)proyectos.size() - 1; i++) {

        huboIntercambio = false;

        for (int j = 0; j < (int)proyectos.size() - i - 1; j++) {

            if (proyectos[j].id > proyectos[j + 1].id) {

                aux = proyectos[j];
                proyectos[j] = proyectos[j + 1];
                proyectos[j + 1] = aux;

                huboIntercambio = true;
            }
        }

        if (!huboIntercambio) {

            break;
        }
    }
}

