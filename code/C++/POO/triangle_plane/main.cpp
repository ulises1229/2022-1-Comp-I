#include <iostream>
#include <ctime>
#include <array>
#include "Triangle.h"
using namespace std;

int main() {
    // Inicaliza  semilla
    srand((int) time(0));

    int max = 999999, min = -999999;

    array<Triangle, 100> T(max, min);

    double minArea = 9999999, maxArea = -9999999;
    for(int i = 0; i<100; i++){
        T[i].run();
        double area = T[i].getArea();
        // TODO: Realizar comparativa de área vs minArea y maxArea.
    }

    cout << "El código se ejecutó de forma correcta"<< endl;
    return 0;
}
