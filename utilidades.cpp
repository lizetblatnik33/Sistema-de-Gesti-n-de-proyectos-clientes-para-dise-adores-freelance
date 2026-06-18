#include <iostream>
#include <vector>
#include <cstdlib>
#include "utilidades.h"

using namespace std;

// ====== MENU PRINCIPAL ======
void mostrarMenu() {

    cout << "\n========================================================" << endl;
    cout << "   GESTION DE CLIENTES Y PROYECTOS DE DISENO FREELANCE "   << endl;
    cout << "========================================================"  << endl;
    cout << " 1. Registrar nuevo proyecto"            << endl;
    cout << " 2. Listar todos los proyectos"          << endl;
    cout << " 3. Modificar proyecto"                  << endl;
    cout << " 4. Eliminar proyecto"                   << endl;
    cout << " 5. Ordenar proyectos por anio"          << endl;
    cout << " 6. Buscar por categoria (secuencial)"   << endl;
    cout << " 7. Buscar por ID (binaria)"             << endl;
    cout << " 8. Intercalar dos portafolios"          << endl;
    cout << " 0. Salir"                               << endl;
    cout << "======================================="  << endl;
    cout << "Seleccione una opcion: ";
}




void pausa(){
	system("pause");
}
void limpiar(){
	system("cls");
}
