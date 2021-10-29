#include <iostream>
#include <ctime>
#include <array>
#include "Triangle.h"

using namespace std;



int main() {
    // Inicaliza  semilla
    srand((int) time(0));

    int max = 999999, min = -999999;

    Triangle T1(max, min);

    array<Triangle, 100> T;


    double minArea = 9999999, maxArea = -9999999;
    int maxIndexT, minIndexT;

    for(int i = 0; i<100; i++){
        T[i].run();
        double area = T[i].getArea();

        // Calcular el área máxima
        if(area > maxArea){
            maxArea = area;
            maxIndexT = i;
        }

        // Calcular el área mínima
        if(area< minArea){
            minArea = area;
            minIndexT = i;
        }
    }


    cout << "El triángulo con la menor área es: " << minIndexT << " Su área es: " << minArea<< endl;

    cout << "El triángulo con la mayot área es: " << maxIndexT << " Su área es: " << maxArea<< endl;
    return 0;
}
