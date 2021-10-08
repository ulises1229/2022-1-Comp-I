#include <iostream>

using namespace std;


// Plantillas para evitar la definición de múltiples funciones
template <typename T>
T sum2(T a, T b);


int main() {
    int a = 1, b = 3;
    float c = 1.0, d = 4.5;

    cout << "la suma de " << a << " + " << b << "empleando platillas es:" <<  sum2(a, b)  << endl;


    return 0;
}


template <typename T>
T sum2(T a, T b){
    return a + b;
}