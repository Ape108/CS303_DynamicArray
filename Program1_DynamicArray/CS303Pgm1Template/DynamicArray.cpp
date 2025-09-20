//
//  DynamicArray.cpp
//  Program1_DynamicArray
//
//  Created by Cameron Akhtar on 9/4/25.
//

#include "DynamicArray.h"



void DynamicArray::resize(int*& arr1, size_t& count, size_t& size) {
    size_t newSize = size * 2;
    int* newArray = new int[newSize];
    for (int i=0; i<count; i++) {
        newArray[i] = arr1[i];
    }
    arr1 = newArray;
    size = newSize;
}

// Returns index of value if found, else -1
size_t DynamicArray::findValue(int target, int* arr1, size_t count) const {
    for (size_t i=0; i<count; i++) {
        if (arr1[i] == target) {
            return i;
        }
    }
    return -1;
}

// Modifies value at index, returns original value
// Throws exception if index/value invalid
int modifyValue(size_t index, int newValue, int* arr1) {
    
}

















/*
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
*/




















