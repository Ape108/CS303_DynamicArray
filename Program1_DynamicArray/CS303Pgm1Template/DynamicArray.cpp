//
//  DynamicArray.cpp
//  Program1_DynamicArray
//
//  Created by Cameron Akhtar on 9/4/25.
//

#include "DynamicArray.h"

void resize(int*& arr1, int& count, int& size) {
    int newSize = size * 2;
    int* newArray = new int[newSize];
    for (int i=0; i<count; i++) {
        newArray[i] = arr1[i];
    }
    arr1 = newArray;
    size = newSize;
}

void loadFromFile(int*& arr1, int& count, int& size, std::ifstream inFile) {
    int value;
    while (inFile >> value) {
        if (count + 1 > size) { // RESIZE (make helper function)
            resize(arr1, count, size);
        }
        // FIXME: Complete loadFromFile()
        
        
        
        
        arr1[count] = value;
        count++;
    }
}

