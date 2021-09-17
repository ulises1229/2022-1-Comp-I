/*
 * Author: Ulises Olivares
 * uolivares@unam.mx
 * Sept 10, 2021
 * */

#include <iostream>

using namespace std;

int main() {

    int num1 = 0;
    int num2 = 0;

    cout << "Enter the first number" << endl;
    cin >> num1; // read 1st number

    cout << "Enter the second number" << endl;
    cin >> num2; // read 2nd number

    std::cout << "The sum of "<< num1 << " and " << num2  << " = " << num1 + num2 << std::endl;
    return 0;
}
