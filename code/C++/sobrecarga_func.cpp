#include <iostream>

using namespace std;

// Sobrecarga de funciones
int sum(int num1, int num2);
float sum(float a, float b);
double sum(double a, double b);



int main() {
    int a = 1, b = 3;
    float c = 1.0, d = 4.5;

    cout << "La suma de dos enteros es: "  << sum(a, b)<< endl;

    cout << "La suma de dos flotantes es: "  << sum(c, d)<< endl;


    return 0;
}

int sum(int num1, int num2){
    return num1 + num2;
}

float sum(float a, float b){
    return a + b;
}

double sum(double a, double b){
    return a + b;
}
