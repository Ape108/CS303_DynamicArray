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
private:
    size_t INITIAL_CAPACITY = 50; // Default capacity for initializing
    int* theData;         // Pointer to dynamic int array
    size_t capacity;     // Current array capacity
    size_t count;        // Number of elements in array
    
    // Doubles array capacity when needed
    void resize();
    
public:
    // Constructor: initializes array with size 50
    DynamicArray() :
        capacity(INITIAL_CAPACITY),
        theData(new int[INITIAL_CAPACITY]),
        count(0) {};
    // Destructor: cleans up dynamic memory
    ~DynamicArray() {
        delete[] theData;
        theData = nullptr;
    };

    // Returns index of value if found, else -1
    size_t findValue(int target) const;

    // Modifies value at index, prints original & new value
    // Throws exception if index/value invalid
    void modifyValue(size_t index, int newValue);

    // Adds value to end, resizes if needed
    void addValue(int value);

    // Removes value at index, shifts elements
    void eraseValue(size_t index);

    // Loads array from file, throws exception on invalid input
    void loadFromFile(const std::string& filename);

    // Returns current number of elements
    size_t getCount() const;

    // Returns current array capacity
    size_t getCapacity() const;

    // Checks if array is empty
    bool isEmpty() const;

    // For debugging: print array contents
    void printArray() const;
};




