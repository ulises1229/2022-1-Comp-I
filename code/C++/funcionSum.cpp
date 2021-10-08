#include <iostream>

using namespace std;

// Declaración de la función
int sum(int a, int b);

int main() {

    int  a = 6, b = 7, c{0};

    cout << "La suma de "<< a << " + " << b << " es: " << sum(a, b) << endl;

    return 0;
}

int sum(int a, int b){
    int c = a + b;
    return c;
}