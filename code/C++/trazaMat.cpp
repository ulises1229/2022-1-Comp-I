#include <iostream>
#include <array>
#include <ctime>

using namespace std;


int main() {

    // Inicaliza  semilla
    srand((int) time(0));

    // Definición de una matriz 2D
    // int [3][4]
    array<array<int, 4>,4> A;

    // Inicializar matriz con números aleatorios
    for(int i = 0; i<4; i++){
        for(int j = 0; j < 4; j++){
            A[i][j] = (rand() % 100) + 1;
            cout << A[i][j] << "  ";
        }
        cout << endl;
    }

    // Traza de una matriz: sumatoria de los elementos de la diagonal principal
    int trace = 0;
    for(int i= 0; i<4; i++){
        // trace = trace + A[i][i]
        trace += A[i][i];
    }

    cout << "La traza  de la matriz A es: "<<  trace << endl;


    return 0;
}
