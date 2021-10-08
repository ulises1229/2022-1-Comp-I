#include <iostream>
#include <string>
#include <array>

using namespace std;

class Triangle{
    public:
    // Métodos setters
    // Establecer el valor para la base
    void setBase(double b){
        base = b;
    }
    // Establecer el valor para la altura
    void setAltura(double a){
        altura = a;
    }

    double getArea() {
        area = (base * altura) / 2;
        return area;
    }
    private:
    // Atributos o variables
    double base, altura, area;
};


int main() {

    Triangle t1, t2;

    // --------------------------------------
    // Triángulos indivuduales

    // Triángulo 1
    t1.setAltura(2.5);
    t1.setBase(4.5);
    cout << "El área de t1 es: "<< t1.getArea() << endl;

    // Triángulo 2
    t2.setAltura(3.5);
    t2.setBase(5.5);
    cout << "El área de t2 es: "<< t2.getArea() << endl;
    // --------------------------------------

    // --------------------------------------
    // Arreglo de objetos

    array<Triangle, 10> arrT;

    int maxT{0}, minT{0};

    double minArea = 9999999999;
    double maxArea = -9999999999;

    // Inicialización de 10 Triángulos y asignación de áreas
    for(int i=0; i<10; i++){
        // Pedir datos al usuario de B y A
        double base, altura;
        cout<< "Ingresa la base y altura del triángulo " << i << endl;
        cin >> base >> altura;
        arrT[i].setBase(base); // Inicializar los base de
        arrT[i].setAltura(altura);
        double currentArea = arrT[i].getArea();

        // Triángulo más pequeño
        if(currentArea < minArea){
            minArea = currentArea;
            minT = i;
        }
        // Triángulo más grande
        if(currentArea > maxArea){
            maxArea = currentArea;
            maxT = i;
        }
    }

    cout << "El triángulo más pequeño es:" << minT << " y tiene un área de: " << minArea << endl;

    cout << "El triángulo más grande es:" << maxT << " y tiene un área de: " << maxArea << endl;


    return 0;
}
