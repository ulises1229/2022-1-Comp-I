//
// Created by Ulises Olivares on 15/10/21.
//

#include "Triangle.h"

Triangle::Triangle() {
    xmin = 9999999;
    xmax = -9999999;
    ymin = 9999999;
    ymax = -9999999;
}
Triangle::Triangle(int bigInt, int smallInt) {
    xmin = bigInt;
    xmax = smallInt;
    ymin = bigInt;
    ymax = smallInt;
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

void Triangle::initRandomVertex(Point2D &V) {
    V.x = (rand() % 100) + 1; // Inicializar el eje X
    V.y = (rand() % 100) + 1; // Inicializar el eje Y

    // Obetener elementos mínimos y máximos por eje
    if(V.x < xmin)
        xmin = V.x;
    if(V.x> xmax)
        xmax = V.x;
    if(V.y < ymin)
        ymin = V.y;
    if(V.y> ymax)
        ymax = V.y;
}