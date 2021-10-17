//
// Created by Ulises Olivares on 06/10/21.
//

#ifndef TRIANGLEWITHHEADERS_TRIANGLE_H
#define TRIANGLEWITHHEADERS_TRIANGLE_H

#include <array>

using namespace std;

class Triangle {

public:
    explicit Triangle(int max, int min);
    void run();
    double getArea();
    void initRandomVertex(array<int, 2> &V);

private:
    array<int, 2> V1 {0};   // Vertice con dos elementos X, Y
    array<int, 2> V2 {0};
    array<int, 2> V3 {0};
    int xmin, xmax, ymin, ymax;
};


#endif //TRIANGLEWITHHEADERS_TRIANGLE_H
