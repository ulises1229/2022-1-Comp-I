/*
 * Author: Ulises Olivares
 * uolivares@unam.mx
 * Sept 10, 2021
 * */

#include <iostream>

using namespace std;

int main() {
    int x = 2; // Independent variable
    float y = 0; // Dependant variable

    for (int i = 0; i <= 10; i++){
        x = i;
        y = (3 * x * x) + (16 * x) + 8;
        cout << "Evaluation of polinomial with x= " << x << " is "  << y << endl;
    }

    return 0;
}
