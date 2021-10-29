//
// Created by Ulises Olivares on 15/10/21.
//

#ifndef ESTRUCTURAS_TRIANGLE_H
#define ESTRUCTURAS_TRIANGLE_H
#include <stdlib.h>


class Triangle {

    struct Point2D{
        int x, y;
    };

public:
    explicit Triangle();
    Triangle(int bigInt, int smallInt);
    void run();
    double getArea();
    void initRandomVertex(Point2D &V);

private:
    Point2D V1, V2, V3;
    int xmin, xmax, ymin, ymax;
};


#endif //ESTRUCTURAS_TRIANGLE_H
