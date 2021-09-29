#include <iostream>
#include <array>

using namespace std;

const int n = 10;

float calcularPromedio();
int calcularMax();
int calcularMin();
void imprimirArray(array<int, n> A);
array<int, n> eliminarRepetidos();

array<int, n> A = {9, 10, 6, 3, 8, 4, 3, 10, 9, 6};

int main() {
    cout << "El calcularPromedio de los elementos es: " << calcularPromedio() << endl;
    cout << "El elemento mínimo es : " << calcularMin() << endl;
    cout << "El elemento máximo es : " << calcularMax() << endl;
    array<int, n> B {0};
    B= eliminarRepetidos();

    cout << "Arreglo original:" << endl;
    imprimirArray(A);

    cout << "\nArreglo sin elementos repetidos:" << endl;
    imprimirArray(B);
    return 0;
}

float calcularPromedio(){
    float promedio = 0;
    for(int i =0; i < A.size();i++ ){
        promedio += A[i];
    }
    promedio = promedio / A.size();
    return promedio;
}

int calcularMin(){
    int min = 99999999;
    for(int i =0; i < A.size();i++ ){
        if(A[i]< min){
            min = A[i];
        }
    }
    return min;
}

int  calcularMax(){
    int max = -99999999;
    for(int i =0; i < A.size();i++ ){
        if(A[i] > max){
            max = A[i];
        }
    }
    return max;
}

array<int, n> eliminarRepetidos(){
    array<int, n> B {0};
    int insertIndex = 0;
    for(int i = 0; i < A.size(); i++){
        bool presente = 0;
        for(int j = 0; j <B.size(); j++){
            if(A[i] == B[j]){
                presente = 1;
            }
        }
        if(presente == 0){
            B[insertIndex] = A[i];
            insertIndex ++;
        }
    }
    return B;
}

void imprimirArray(array<int, n> A){
    for(int i = 0; i<A.size(); i++){
        if(A[i]!=0)
            cout<< A[i] << " ";
    }
}