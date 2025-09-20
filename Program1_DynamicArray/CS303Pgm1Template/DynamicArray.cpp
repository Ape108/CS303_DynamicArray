//
//  DynamicArray.cpp
//  Program1_DynamicArray
//
//  Created by Cameron Akhtar on 9/4/25.
//

#include "DynamicArray.h"
#include <sstream>



void DynamicArray::resize() {
    size_t newSize = capacity * 2;
    int* newArray = new int[newSize];
    for (size_t i=0; i < count; i++) {
        newArray[i] = theData[i];
    }
    theData = newArray;
    capacity = newSize;
}

// Returns index of value if found, else -1
size_t DynamicArray::findValue(int target) const {
    for (size_t i=0; i < count; i++) {
        if (theData[i] == target) {
            return i;
        }
    }
    return -1;
}

// Modifies value at index, prints original & new value
// Throws exception if index/value invalid
void DynamicArray::modifyValue(size_t index, int newValue) {
    if (index >= count) {
        throw std::invalid_argument("Index out of range.");
    }
    std::cout << "Original: " << theData[index] << std::endl;

    theData[index] = newValue;
    
    std::cout << " Updated: " << theData[index] << std::endl;
}

// Adds value to end, resizes if needed
void DynamicArray::addValue(int value) {
    if (count >= capacity) {
        resize();
    }
    theData[count] = value;
    count++;
}

// Removes value at index, shifts elements
void DynamicArray::eraseValue(size_t index) {
    if (index >= count) {
        throw std::invalid_argument("Index out of range.");
    }
    // Shift items so as not to leave a gap
    for (size_t i = index + 1; i < count; i++) {
        theData[i-1] = theData[i];
    }
    count--;
}

// Loads array from file, throws exception on invalid input
void DynamicArray::loadFromFile(const std::string& filename) {
    std::ifstream inputFile(filename); // Opens "example.txt" for reading

    if (inputFile.is_open()) { // Check if the file was successfully opened
        std::string line;
        std::cout << "\nReading from " << filename << ":" << std::endl;
        while (std::getline(inputFile, line)) { // Read line by line until end of file
            std::istringstream iss(line);
            std::string token;
            
            while (iss >> token) {
                // Try to convert token to integer
                try {
                    int value = std::stoi(token);
                    addValue(value);
                } catch (const std::invalid_argument& e) {
                    // Write error to error.txt file
                    std::ofstream errorFile("error.txt", std::ios::app);
                    if (errorFile.is_open()) {
                        errorFile << "Invalid input found: " << token << std::endl;
                        errorFile.close();
                    }
                    throw std::invalid_argument("Invalid input found: " + token);
                } catch (const std::out_of_range& e) {
                    // Write error to error.txt file
                    std::ofstream errorFile("error.txt", std::ios::app);
                    if (errorFile.is_open()) {
                        errorFile << "Input out of range: " << token << std::endl;
                        errorFile.close();
                    }
                    throw std::invalid_argument("Input out of range: " + token);
                }
            }
        }
        inputFile.close(); // Close the file stream
    } else {
        // Write file opening error to error.txt
        std::ofstream errorFile("error.txt", std::ios::app);
        if (errorFile.is_open()) {
            errorFile << "Error opening file for reading: " << filename << std::endl;
            errorFile.close();
        }
        std::cerr << "Error opening file for reading!" << std::endl;
    }
}

// Returns current number of elements
size_t DynamicArray::getCount() const {
    return count;
}

// Returns current array capacity
size_t DynamicArray::getCapacity() const {
    return capacity;
}

// Checks if array is empty
bool DynamicArray::isEmpty() const {
    if (count == 0) {
        return true;
    }
    return false;
}

// For debugging: print array contents
void DynamicArray::printArray() const {
    std::cout << "Array Contents: ";
    for (size_t i=0; i < count; i++) {
        std::cout << theData[i] << " ";
    }
    std::cout << std::endl;
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




















