/* Author: Ulises Olivares
 * uolivares@unam.mx
 * Sept 27, 2021
 */

#include <iostream>
#include <array>

using namespace std;

//array<array<int,3>,4> B  {{2, 1, -1, 8},
//             {-3, -1, 2,-11},
//             {-2, 1, 2, -3}}

const int filas = 3, cols = 4;

int A[3][4] {{0, 1, -1, 8},
             {-3, -1, 2,-11},
             {-2, 1, 2, -3}};

int encontrarPivote(int fila, int col);
void intercambiarFilas(int f1, int f2);
void imprimirMatriz(void);

int main() {
    for(int i = 0; i< 4 ; i++){
        for(int j = 0; j<3 ;j ++){
            int pivote = A[i][i];
            if(pivote==0) {
                imprimirMatriz();
                int nuevaFila = encontrarPivote(i, j);
                if (nuevaFila == -1) {
                    cout << "El sistema de ecuaciones no tiene solución" << endl;
                    exit(0);
                } else {
                    intercambiarFilas(i, nuevaFila);
                    pivote = A[i][i];
                    imprimirMatriz();
                }
                // Realizar eliminación
                // TODO:
                //  1) múltiplo
                //  2) Efectuar operación (tmp)
                //  3) Escribir resultado
            }
        }
    }

    return 0;
}

int encontrarPivote(int fila, int col){
    int max = -999999, indiceFila = -1;
    for(int j = fila + 1; j < filas; j++){
        if(A[j][col] > max && A[j][col] != 0){
            max = A[j][col];
            indiceFila = j;
        }
    }
    return indiceFila;
}

void intercambiarFilas(int f1, int f2){
    int aux[cols];
    for(int i= 0; i<cols; i++){
        aux[i] = A[f1][i];
        A[f1][i] = A[f2][i];
        A[f2][i] = aux[i];
    }
}

void imprimirMatriz(void){
    cout << "-----------------" << endl;
    for(int i =0; i<filas; i++){
        for(int j=0; j<cols; j++){
            cout << A[i][j] <<"  ";
        }
        cout << endl;
    }
    cout << "-----------------" << endl;
}