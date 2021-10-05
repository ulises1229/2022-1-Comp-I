#include <iostream>
#include <array>
#include <ctime>

using namespace std;

class Triangle{
public:
    void run(){ //
        // Inicializar 3 vértices
        initRandomVertex(V1);
        initRandomVertex(V2);
        initRandomVertex(V3);

    }

    double getArea(){
        double base = xmax-xmin;
        double altura = ymax-ymin;
        return (base * altura) / 2;
    }

    void initRandomVertex(array<int, 2> &V){
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
private:
    array<int, 2> V1 {0};   // Vertice con dos elementos X, y
    array<int, 2> V2 {0};
    array<int, 2> V3 {0};
    int xmin = 999999, xmax= -999999, ymin= 999999, ymax= -999999;
};


int main() {
    // Inicaliza  semilla
    srand((int) time(0));

    array<Triangle, 100> T;
    double minArea = 9999999, maxArea = -9999999;

    for(int i = 0; i<100; i++){
        T[i].run();
        double area = T[i].getArea();
        // TODO: Realizar comparativa de área vs minArea y maxArea.
    }

    return 0;
}
