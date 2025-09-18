//
//  functions.h
//  Program1_DynamicArray
//
//  Created by Cameron Akhtar on 9/4/25.
//

#pragma once

#include <iostream>
#include <fstream>

// Class declaration
class DynamicArray {
public:
    // Constructor: initializes array with size 50
    DynamicArray();
    // Destructor: cleans up dynamic memory
    ~DynamicArray();

    // Returns index of value if found, else -1
    int findValue(int value) const;

    // Modifies value at index, returns original value
    // Throws exception if index/value invalid
    int modifyValue(int index, int newValue);

    // Adds value to end, resizes if needed
    void addValue(int value);

    // Removes value at index, shifts elements
    void eraseValue(int index);

    // Loads array from file, throws exception on invalid input
    void loadFromFile(const std::string& filename);

    // Returns current number of elements
    int getCount() const;

    // Returns current array capacity
    int getCapacity() const;

    // Checks if array is empty
    bool isEmpty() const;

    // For debugging: print array contents
    void printArray() const;

private:
    int* arr;         // Pointer to dynamic int array
    int capacity;     // Current array capacity
    int count;        // Number of elements in array

    // Doubles array capacity when needed
    void resize();
};




