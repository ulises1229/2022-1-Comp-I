#include <iostream>
#include <array>

// Incluimos nuestro encabezado con la definición de la clase Punto2D
#include "Punto.h"

using namespace std;

// Declaración de funciones
void PedirValores(float& x, float& y);
char PedirOperacion();

int main()
{
    // Creamos una nueva instancia de la clase Punto2D
    Punto2D miPunto;
    float x = 0, y = 0;
    float temp1 = 0, temp2 = 0;
    char operacion;
    // Pedimos al usuario que ingrese las coordenadas iniciales del punto en el plano
    cout << "Ingresa la posicion inicial del punto.\n";
    PedirValores(x, y);
    // Modificamos las coordenadas de la instancia
    miPunto.SetPosicion(x, y);
    // solicitamos al usuario que ingrese una operación válida a realizar
    operacion = PedirOperacion();
    // Similar a un if, pero con otra estructura.
    switch (operacion)
    {
    // Si operacion == 't' entonces realiza lo siguiente
    case 't':
        // Solicitamos al usuario las coordenadas a desplazar el punto para cada eje
        cout << "Ingresa los valores a desplazar para cada eje\n";
        PedirValores(temp1, temp2);
        // Trasladamos el objeto (modificamos sus coordenadas)
        miPunto.Trasladar(temp1, temp2);
        // Salimos del switch
        break;
    // Si operaciosn == 'r' entonces realiza lo siguiente
    case 'r':
        // Solicita al usuario ingrese el valor del ángulo a rotar
        cout << "Ingresa el valor del angulo a rotar (en grados): ";
        cin >> temp1;
        // Rota el punto en el plano con respecto al origen
        miPunto.RotarRespectoAlOrigen(temp1);
        break;
    // Si operacion == 'e' entonces realiza lo siguiente
    case 'e':
        // solicita al usuario que ingrese el factor de escala para cada eje
        cout << "Ingresa los factores a escalar para cada eje\n";
        PedirValores(temp1, temp2);
        miPunto.Escalar(temp1, temp2);
        break;
    // Si ninguno de los casos anteriores se cumplió, entonces realiza lo siguiente
    default:
        cout << "Operacion no valida\n";
        break;
    }
    // Imprime la posición final del punto después de las transformaciones
    cout << "Posicion final:\n";
    cout << "[ " << miPunto.GetX() << " " << miPunto.GetY() << " ]";
    // Si terminamos correctamente la ejecución del programa, regresamos 0
    return 0;
}

// Solicita dos valores de punto flotante al usuario y modifícalos por referencia
void PedirValores(float& x, float& y)
{
    cout << "x: ";
    cin >> x;
    cout << "y: ";
    cin >> y;
}

// Solicita una operación válida al usuario
char PedirOperacion()
{
    char op;
    do {
        cout << "Operacion ('t' para trasladar, 'r' para rotar, 'e' para escalar): ";
        cin >> op;
    } while (op != 't' && op != 'r' && op != 'e');
    return op;
}
