#include <iostream>
using namespace std;

// ===== DATOS DEL CATALOGO =====
const int TOTAL = 5;            // Cantidad de modelos en el catalogo
const double IVA = 0.13;        // IVA de El Salvador (13%)

char marcas[TOTAL][30] = {
    "Toyota", "Honda", "Nissan", "BMW", "Mercedes-Benz"
};

char modelos[TOTAL][30] = {
    "Corolla", "Civic", "Sentra", "Serie 3", "Clase C"
};

int anios[TOTAL] = {2022, 2023, 2021, 2022, 2023};

double precios[TOTAL] = {18500, 22000, 16500, 38000, 45000};

int cantidad[TOTAL] = {3, 2, 4, 1, 2};   // Unidades disponibles de cada modelo

// ===== DATOS DE VENTAS (para el reporte) =====
int carrosVendidos = 0;          // Cuantos carros se han vendido
double totalVentas = 0;          // Dinero total vendido (con IVA)
int vendidosPorModelo[TOTAL] = {0, 0, 0, 0, 0};

// ===== DECLARACION DE FUNCIONES =====
int leerEntero();
void mostrarCatalogo();
void mostrarInventario();
void comprarCarro();
void reporteVentas();

int main() {

    int opcion;

    // Para que los precios salgan con 2 decimales (ej. 18500.00)
    cout << fixed;
    cout.precision(2);

    do {
        cout << "\n===== AUTOLUX =====\n";
        cout << "1. Mostrar catalogo\n";
        cout << "2. Comprar carro\n";
        cout << "3. Mostrar inventario\n";
        cout << "4. Reporte de ventas\n";
        cout << "0. Salir\n";

        cout << "\nSeleccione una opcion: ";
        opcion = leerEntero();

        switch (opcion) {

            case 1:
                mostrarCatalogo();
                break;

            case 2:
                comprarCarro();
                break;

            case 3:
                mostrarInventario();
                break;

            case 4:
                reporteVentas();
                break;

            case 0:
                cout << "Gracias por visitar AutoLux.\n";
                break;

            default:
                cout << "Opcion incorrecta.\n";
        }

    } while (opcion != 0);

    return 0;
}

// Lee un numero entero. Si el usuario escribe letras,
// limpia el error de cin y vuelve a pedir el numero.
int leerEntero() {

    int numero;
    cin >> numero;

    while (cin.fail()) {
        cin.clear();               // Quita el estado de error de cin
        cin.ignore(1000, '\n');    // Borra lo que el usuario escribio mal
        cout << "Debe ingresar un numero: ";
        cin >> numero;
    }

    return numero;
}

// Muestra todos los vehiculos del catalogo
void mostrarCatalogo() {

    cout << "\n===== CATALOGO DE AUTOS =====\n";

    for (int i = 0; i < TOTAL; i++) {

        cout << "\nVehiculo " << i + 1 << endl;
        cout << "Marca: " << marcas[i] << endl;
        cout << "Modelo: " << modelos[i] << endl;
        cout << "Anio: " << anios[i] << endl;
        cout << "Precio: $" << precios[i] << endl;

        if (cantidad[i] > 0) {
            cout << "Estado: Disponible (" << cantidad[i] << " unidades)\n";
        }
        else {
            cout << "Estado: Agotado\n";
        }
    }
}

// Muestra solo los vehiculos que tienen unidades disponibles
void mostrarInventario() {

    int totalUnidades = 0;

    cout << "\n===== INVENTARIO AUTOLUX =====\n";

    for (int i = 0; i < TOTAL; i++) {

        if (cantidad[i] > 0) {
            cout << marcas[i] << " " << modelos[i]
                 << " - " << cantidad[i] << " unidades\n";

            totalUnidades = totalUnidades + cantidad[i];
        }
    }

    if (totalUnidades == 0) {
        cout << "No hay vehiculos disponibles.\n";
    }

    cout << "\nTotal de unidades disponibles: " << totalUnidades << endl;
}