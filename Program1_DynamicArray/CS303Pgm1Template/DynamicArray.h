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
    // Constructor
    DynamicArray();
    // Destructor
    ~DynamicArray();

    // Member functions
    void resizeArray();
    void loadArray();
    bool exists();
    void addItem();
    void delItem();
    int at_index();
    int getSize();
    bool isEmpty();

private:
    // Member variables
    int size;
    int count;
    
    
};




