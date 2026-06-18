#include <iostream>
#include <vector>

#include "intercalacion.h"

using namespace std;

//Intercalr dos vectores por anio
vector<Proyecto> intercalarProyectos(const vector<Proyecto> &v1,const vector<Proyecto> &v2) {

    //Vector resultado
    vector<Proyecto> resultado;

    //Indices para recorrer ambos vectores
    int i = 0;
    int j = 0;

    //Comparar elementos de ambos vectores por anio
    while (i < (int)v1.size() && j < (int)v2.size()) {

        if (v1[i].anio <= v2[j].anio) {

            resultado.push_back(v1[i]);

            i++;
        }
        else {

            resultado.push_back(v2[j]);

            j++;
        }
    }

    //Copiar elementos restantes de v1
    while (i < (int)v1.size()) {

        resultado.push_back(v1[i]);

        i++;
    }

    //Copiar elementos restantes de v2
    while (j < (int)v2.size()) {

        resultado.push_back(v2[j]);

        j++;
    }

    return resultado;
}
