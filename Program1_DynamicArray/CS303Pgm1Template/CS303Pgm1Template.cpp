// CS303Pgm1Template.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//NAME: Cameron Akhtar
//CS303
//PROGRAM 1

#include <iostream>
#include "DynamicArray.h"

using namespace std;

int main()
{
    cout << "Dynamic Arrays\n";
    DynamicArray arr;
    int input = 0;

    string filename = getFilename();
    arr.loadFromFile(filename);
    
    while (input != 6) {
        printMenu();
        input = getUserInput();
        menuHandler(input, arr);
    }
    
    return 0;
}
