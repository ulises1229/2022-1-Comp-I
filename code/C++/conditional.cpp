/*
 * Author: Ulises Olivares
 * uolivares@unam.mx
 * Sept 10, 2021
 * */

#include <iostream>

using namespace std;

int main() {

    int num1{0};
    int num2{0};

    cout << "Enter the first number" << endl;
    cin >> num1; // read 1st number

    cout << "Enter the second number" << endl;
    cin >> num2; // read 2nd number

    if(num1 >num2){
        cout << num1 << " is greater than "<< num2 << endl;
    }
    else{
        if(num1 == num2){
            cout << num1 <<" and " << num2 << " are equal"<< endl;
        }
        else{
            cout << num2 << " is greater than "<< num1 <<endl;
        }
    }
    return 0;
}
