#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

#include "proyecto.h"
#include "crud.h"
#include "archivos.h"
#include "ordenacion.h"
#include "busqueda.h"
#include "intercalacion.h"
#include "utilidades.h"

using namespace std;

int main() {

    vector<Proyecto> proyectos;

    //Cargar proyectos desde archivo principal
    cargarProyectos("proyectos.csv", proyectos);

    int opcion;

    do {

        mostrarMenu();
        cin >> opcion;
        cin.ignore();

        switch(opcion) {


        //Crear proyecto
        case 1:
            crearProyecto(proyectos);
            guardarProyectos("proyectos.csv", proyectos);
			pausa();
            break;

        //Listar proyectos
        case 2:

            listarProyectos(proyectos);
			pausa();
            break;

        //Modificar proyecto
        case 3:

            modificarProyecto(proyectos);
            guardarProyectos("proyectos.csv", proyectos);
			pausa();
            break;

      	//Eliminar proyecto
        case 4:

            eliminarProyecto(proyectos);
            guardarProyectos("proyectos.csv", proyectos);
			pausa();
            break;

       //Ordenar por anio
        case 5:

            ordenarPorAnio(proyectos);

            guardarProyectos("proyectos.csv", proyectos);

            cout << "\nProyectos ordenados por anio correctamente." << endl;
			pausa();
            break;

      	//Busqueda secuencial por categoria
        case 6: {

            if (proyectos.empty()) {

                cout << "\nNo existen proyectos registrados." << endl;

                break;
            }

            string categoria;

            cout << "\nCategorias disponibles: branding / UX / ilustracion / motion / web";
            cout << "\nIngrese categoria a buscar: ";

            getline(cin, categoria);

            busquedaSecuencialCategoria(proyectos, categoria);
			pausa();
            break;
        }

        //busqueda binaria por id
        case 7: {

            if (proyectos.empty()) {

                cout << "\nNo existen proyectos registrados." << endl;

                break;
            }

            // Ordenar por ID antes de buscar
            ordenarPorID(proyectos);

            string idBuscado;

            cout << "\nIngrese ID del proyecto a buscar: ";

            getline(cin, idBuscado);

            int posicion;

            posicion = busquedaBinariaID(
                           proyectos,
                           0,
                           proyectos.size() - 1,
                           idBuscado
                       );

            mostrarResultadoBinaria(proyectos, posicion);
			pausa();
            break;
        }

        //Intercalacion de portafolios
        case 8: {

            vector<Proyecto> portafolio1;
            vector<Proyecto> portafolio2;
            vector<Proyecto> resultado;

            cargarProyectos("portafolio1.csv", portafolio1);
            cargarProyectos("portafolio2.csv", portafolio2);

            // Ambos deben estar ordenados por anio
            ordenarPorAnio(portafolio1);
            ordenarPorAnio(portafolio2);

            resultado = intercalarProyectos(portafolio1, portafolio2);

            guardarProyectos("portafolio_completo.csv", resultado);

            cout << "\nIntercalacion realizada correctamente." << endl;
            cout << "Registros en portafolio1: "
                 << portafolio1.size() << endl;
            cout << "Registros en portafolio2: "
                 << portafolio2.size() << endl;
            cout << "Registros en resultado:   "
                 << resultado.size()   << endl;
            cout << "Archivo generado: portafolio_completo.csv" << endl;
			pausa();
            break;
        }

        //Salir
        case 0:

            cout << "\nCerrando el sistema. Hasta pronto." << endl;
			pausa();
            break;

        //Opcion invalida
        default:

            cout << "\nOpcion invalida. Intente de nuevo." << endl;
            pausa();
        }
        
	limpiar();
    } while (opcion != 0);

    return 0;
}
