#include <iostream>
using namespace std;


float calcularDescuento(float precio, float porcentaje){
    return precio * porcentaje / 100;
}

void generarFactura(string vehiculo, float precio){
    int opcion;
    float porcentaje = 0;
    float descuento, total;

    cout << "DESCUENTOS";
    cout << "1. sin descuento";
    cout << "2. descuento 5%";
    cout << "3. descuento 10%";
    cout << "4. descuento 20%";
    cout << "elija una opcion";
    cin >> opcion;

    switch (opcion){
        case 1:
        porcentaje = 0;
        break;

        case 2:
        porcentaje = 5;
        break;

        case 3:
        porcentaje = 10;
        break;
        
        case 4:
        porcentaje = 15;
        break;

        defaul:
        cout << "opcion no valida" << endl;
        return;
    }
descuento = calcularDescuento(precio, porcentaje);
total = precio - descuento;

cout << "FACTURA" << endl;
    cout << "Vehiculo: " << vehiculo << endl;
    cout << "Precio original: $" << precio << endl;
    cout << "Descuento: " << porcentaje << "%" << endl;
    cout << "Monto descontado: $" << descuento << endl;
    cout << "Total a pagar: $" << total << endl;
}




    