#include <iostream>

using namespace std;

void test();

int  x = 1;



int main() {
    //std::cout << x << std::endl;

    test();

    //std::cout << y << std::endl;

    return 0;
}

void test(){
    int y = 2;

    std::cout << &x << std::endl;

    std::cout << &y << std::endl;


}