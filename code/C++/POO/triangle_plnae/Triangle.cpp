//
// Created by Ulises Olivares on 06/10/21.
//

#include "Triangle.h"

Triangle::Triangle(int max, int min) {
    // Inicializar variables de la clase Triangle
    xmin = max;
    xmax= min;
    ymin= max;
    ymax= min;
}

void Triangle::run() {
    // Inicializar 3 vértices
    initRandomVertex(V1);
    initRandomVertex(V2);
    initRandomVertex(V3);
}

double Triangle::getArea() {
    double base = xmax-xmin;
    double altura = ymax-ymin;
    return (base * altura) / 2;
}

void Triangle::initRandomVertex(array<int, 2> &V) {
    V[0] = (rand() % 10) + 1; // Inicializar el eje X
    V[1] = (rand() % 10) + 1; // Inicializar el eje Y

    // Obetener elementos mínimos y máximos por eje
    if(V[0] < xmin)
        xmin = V[0];
    if(V[0]> xmax)
        xmax = V[0];
    if(V[1] < ymin)
        ymin = V[1];
    if(V[1]> ymax)
        ymax = V[1];
}

