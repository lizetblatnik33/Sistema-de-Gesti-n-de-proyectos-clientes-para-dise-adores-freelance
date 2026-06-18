#include <iostream>
#include <vector>

#include "busqueda.h"

using namespace std;

//Busqueda secuencial por categoria
void busquedaSecuencialCategoria(const vector<Proyecto> &proyectos,
                                 const string &categoriaBuscada) {

    bool encontrado = false;

    cout << "\n===== PROYECTOS EN CATEGORIA: "
         << categoriaBuscada
         << " =====" << endl;

    // Recorrer desde el inicio hasta el final
    for (int i = 0; i < (int)proyectos.size(); i++) {

        //Comparar categoria del registro con la buscada
        if (proyectos[i].categoria == categoriaBuscada) {

            cout << "\nProyecto #" << i + 1                      << endl;
            cout << "ID:          " << proyectos[i].id           << endl;
            cout << "Nombre:      " << proyectos[i].nombre       << endl;
            cout << "Cliente:     " << proyectos[i].cliente      << endl;
            cout << "Anio:        " << proyectos[i].anio         << endl;
            cout << "Presupuesto: Bs. " << proyectos[i].presupuesto << endl;
            cout << "Contacto:    " << proyectos[i].contacto     << endl;
            cout << "------------------------------------"        << endl;

            encontrado = true;
        }
    }

    // Informar si no se encontro ninguno
    if (!encontrado) {

        cout << "No se encontraron proyectos en esa categoria." << endl;
    }
}

//Busqueda binaria recursiva con id
int busquedaBinariaID(const vector<Proyecto> &proyectos,
                      int izq,
                      int der,
                      const string &idBuscado) {

    // Condicion base: quedan elementos por analizar
    if (izq <= der) {

        //Calcular posicion central
        int medio = izq + (der - izq) / 2;

        // Comparar ID central con el buscado
        if (proyectos[medio].id == idBuscado) {

            return medio;
        }

        //Si el ID buscado es menor, buscar en la mitad izquierda
        if (idBuscado < proyectos[medio].id) {

            return busquedaBinariaID(
                        proyectos,
                        izq,
                        medio - 1,
                        idBuscado
                   );
        }

        //Si el ID buscado es mayor, buscar en la mitad derecha
        return busquedaBinariaID(
                    proyectos,
                    medio + 1,
                    der,
                    idBuscado
               );
    }

    //No encontrado
    return -1;
}

//Mostrar resultado de busqueda binaria
void mostrarResultadoBinaria(const vector<Proyecto> &proyectos,
                             int posicion) {

    if (posicion != -1) {

        cout << "\n===== PROYECTO ENCONTRADO =====\n";

        cout << "ID:          "
             << proyectos[posicion].id          << endl;

        cout << "Nombre:      "
             << proyectos[posicion].nombre      << endl;

        cout << "Categoria:   "
             << proyectos[posicion].categoria   << endl;

        cout << "Cliente:     "
             << proyectos[posicion].cliente     << endl;

        cout <<"Anio:        "
             << proyectos[posicion].anio        << endl;

        cout <<"Presupuesto: Bs. "
             << proyectos[posicion].presupuesto << endl;

        cout <<"Contacto:    "
             << proyectos[posicion].contacto    << endl;
    }
    else {

        cout <<"\nProyecto no encontrado."<< endl;
    }
}
