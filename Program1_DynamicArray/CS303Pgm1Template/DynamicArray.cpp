//
//  DynamicArray.cpp
//  Program1_DynamicArray
//
//  Created by Cameron Akhtar on 9/4/25.
//

#include "DynamicArray.h"
#include <sstream>	
#include <ios>
#include <limits>



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
                    
                } catch (const std::out_of_range& e) {
                    // Write error to error.txt file
                    std::ofstream errorFile("error.txt", std::ios::app);
                    if (errorFile.is_open()) {
                        errorFile << "Input out of range: " << token << std::endl;
                        errorFile.close();
                    }
                    
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

// Helper functions for main loop

std::string getFilename() {
    std::string userInput;
    do {
        std::cout << "Please enter a valid filename: ";
        // Get the entire line of input from the user and store it in userInput.
        std::getline(std::cin, userInput);
        
        if (userInput.empty()) {
            std::cout << "The input was empty. Please try again." << std::endl;
        }

    } while (userInput.empty());
    
    // Once a non-empty string is provided, the loop ends and the function returns the value.
    return userInput;
}

int getRequiredInt() {
    int userInput;
    while (true) {
        std::cin >> userInput;

        // Check if the input operation failed (e.g., non-numeric input)
        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a valid integer." << std::endl;
            
            // Clear the error state from std::cin
            std::cin.clear();
            
            // Discard the rest of the invalid input from the buffer
            // This is crucial to prevent an infinite loop on the same bad input.
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            
            continue;
        }

        // There might be trailing characters (e.g., user entered "123 abc").
        // We will discard the rest of the line to ensure the input buffer is clean
        // for any subsequent input operations.
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        break;
    }

    return userInput;
}

// Prompt user for input to pass to menu
int getUserInput() {
    int input;
    while (true) {
        std::cout << "Please enter a number 1-6: ";
        if (std::cin >> input) {
            if (input >= 1 && input <= 6) {
                return input;
            } else {
                std::cout << "Error: Number must be between 1 and 6. Please try again.\n";
            }
        } else {
            // If the input was not a number, handle the error
            std::cout << "Error: Invalid input. Please enter a whole number.\n";
            // Clear the error flag from std::cin
            std::cin.clear();
            // Discard the rest of the invalid input from the buffer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void printMenu() {
    std::cout << "1. Find Value" << std::endl;
    std::cout << "2. Modify Value" << std::endl;
    std::cout << "3. Print Array" << std::endl;
    std::cout << "4. Add Value" << std::endl;
    std::cout << "5. Erase Value" << std::endl;
    std::cout << "6. Quit" << std::endl;
    std::cout << std::endl;

}

// Accepts integer input 1-6, handles menu operations
int menuHandler(int input, DynamicArray dynArr) {
    int target, newValue;
    size_t index;
    
    if (input == 1) {// Find Value
        std::cout << "Enter target value: ";
        target = getRequiredInt();
        std::cout << "Index: " << dynArr.findValue(target) << std::endl;
        
    } else if (input == 2) { // Modify Value
        std::cout << "Enter target index: " << std::endl;
        index = static_cast<size_t>(getRequiredInt());
        std::cout << "Enter new value: " << std::endl;
        newValue = getRequiredInt();
        dynArr.modifyValue(index, newValue);
        
    } else if (input == 3) { // Print Array
        dynArr.printArray();
        
    } else if (input == 4) {// Add Value
        std::cout << "Enter new value: " << std::endl;
        newValue = getRequiredInt();
        dynArr.addValue(newValue);
        
    } else if (input == 5) { // Erase Value
        std::cout << "Enter target index: " << std::endl;
        index = static_cast<size_t>(getRequiredInt());
        dynArr.eraseValue(index);
        
    } else if (input == 6) { // Quit
        std::cout << "Exiting program..." << std::endl << "Goodbye!" << std::endl;
        
    }
    return input;
}












