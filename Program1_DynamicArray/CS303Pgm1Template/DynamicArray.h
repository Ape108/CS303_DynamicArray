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

    //PRE: target is a valid integer
    //POST: returns index of target if found in array, otherwise returns -1
    int findValue(int target) const;

    //PRE: index is a valid size_t, newValue is a valid integer
    //POST: value at index is changed to newValue, original and new values are printed to console
    void modifyValue(size_t index, int newValue);

    //PRE: value is a valid integer
    //POST: value is added to end of array, array capacity is doubled if needed
    void addValue(int value);

    //PRE: index is a valid size_t within array bounds
    //POST: value at index is removed, all elements after index are shifted left, count is decremented
    void eraseValue(size_t index);

    //PRE: filename is a valid string representing an existing file path
    //POST: array is populated with integers from file, invalid inputs are logged to error.txt
    void loadFromFile(const std::string& filename);

    //PRE: none
    //POST: returns the current number of elements in the array
    size_t getCount() const;

    //PRE: none
    //POST: returns the current capacity of the array
    size_t getCapacity() const;

    //PRE: none
    //POST: returns true if array has no elements, false otherwise
    bool isEmpty() const;

    //PRE: none
    //POST: array contents are printed to console, 10 elements per line
    void printArray() const;
};

//PRE: none
//POST: returns a non-empty string entered by user
std::string getFilename();

//PRE: none
//POST: returns a valid integer entered by user
int getRequiredInt();

//PRE: none
//POST: returns an integer between 1 and 6 entered by user
int getUserInput();

//PRE: none
//POST: menu options 1-6 are printed to console
void printMenu();

//PRE: input is an integer between 1-6, dynArr is a valid DynamicArray object
//POST: performs the requested menu operation and returns the input value
int menuHandler(int input, DynamicArray& dynArr);

