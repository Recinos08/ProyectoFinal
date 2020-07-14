#include <iostream>
#include<stdlib.h>
#include <string>
#include <string.h>
using namespace std;

const int longCant = 20;
    
    struct costByProduct{ // Principio de la estructura
        char nombrep [longCant + 1];
        int cantidad;
        float precio;
        float total;
    };

void read_FillProductData (costByProduct productData[], int n) // Función para llenar la matríz
{   

    string main;

    for (int i = 0; i < n; i++) // Llenado de la matriz
    {
        
        cout << "PRODUCTO " << (i + 1) << "\n";
        cout << "NOMBRE DEL PRODUCTO:" << "\n";
        getline(cin, main, '\n');
        strncpy(productData[i].nombrep, main.c_str(), longCant);
        productData[i].nombrep[longCant] = '\0';
        cout << "CANTIDAD:" << "\n";
        cin >> productData[i].cantidad;
        cout << "PRECIO: $" << "\n";
        cin >> productData[i].precio;
        fflush(stdin);

    }

}

void calculateTotalPrice (costByProduct productData[], int n) // Función para calcular el total del producto
{

    for (int i = 0; i < n; i++) // Calculo del Array
    {
    
        productData[i].total = ( productData[i].precio * productData[i].cantidad );
    }
}

void printBill (costByProduct productData[], int n) // Función que imprime los datos del Array
{

    cout << "\nFACTURA DE COMPRA \n";

    for (int i = 0; i < n; i++) // Impresión de los datos recolectados en el Array
    {
    
        cout << "PRODUCTO #:" << (i + 1) << "\n";
        cout << "NOMBRE DEL PRODUCTO: " << productData[i].nombrep << "\n";
        cout << "CANTIDAD DE PRODUCTO: " << productData[i].cantidad << "\n";
        cout << "PRECIO DEL PRODUCTO: " << productData[i].precio << "\n";
        cout << "PRECIO TOTAL POR PRODUCTO: " << productData[i].total << "\n";

    }
}

float calculateTotal2Pay (costByProduct productData[], int n) // Función del total a pagar
{       

    float totalpagar = 0;

    for (int i = 0; i < n; i++) // Calculo del Array
    {
    
        totalpagar += productData[i].total;

    }
        
    return totalpagar;

}

int main() // Main, declarancion de la funcion del Array
{
    
    int n;

    cout << "Ingrese la cantidad de productos que desea ingresar";
    
    cin >> n;
    fflush(stdin);

    costByProduct productData[n]; // Declaración del Array
    read_FillProductData(productData, n);
    calculateTotalPrice(productData, n);
    printBill(productData, n);
    cout << "EL TOTAL A PAGAR POR SU COMPRA ES: $" << calculateTotal2Pay(productData, n);

}