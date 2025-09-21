# Dynamic Array Console Application

This C++ program provides a console-based interface for interacting with a dynamic array. The program starts by prompting the user for a filename to load an initial set of integers into the array. It then presents a menu of options to manipulate and query the array's contents.

---

## 🚀 Features

* **Dynamic Sizing**: The array automatically doubles in capacity when it becomes full, starting with an initial capacity of 50 elements.
* **File Loading**: Initializes the array with integer values from a user-specified text file.
* **Error Handling**: Non-integer values encountered in the input file are logged to `error.txt` without halting the program.
* **Interactive Menu**: A simple command-line menu allows users to perform various operations on the array.

---

## 🛠️ How to Compile and Run

### Using Visual Studio
1.  Open the `CS303Pgm1Template.vcxproj` file in Visual Studio.
2.  Build the solution (F7 or Build > Build Solution).
3.  Run the program (Ctrl+F5 or Debug > Start Without Debugging).

### Using a Command-Line Compiler (g++)
1.  Navigate to the project directory in your terminal.
2.  Compile the source files using the following command:
    ```bash
    g++ CS303Pgm1Template.cpp DynamicArray.cpp -o DynamicArrayApp
    ```
3.  Run the compiled executable:
    ```bash
    ./DynamicArrayApp
    ```

---

## 📖 How to Use

Upon running the application, you will first be asked to provide a filename.

Please enter a valid filename:

Enter the path to a text file containing space-separated integers (e.g., `A1input.txt`). The program will load the valid integers from this file into the array.

### Menu Options

After loading the file, a menu will be displayed with the following options:

1.  **Find Value**: Searches for a specified integer in the array and returns its index. If the value is not found, it returns -1.
2.  **Modify Value**: Changes the value at a specified index to a new integer.
3.  **Print Array**: Displays all the current elements in the array, with 10 numbers per line.
4.  **Add Value**: Appends a new integer to the end of the array.
5.  **Erase Value**: Removes the element at a specified index.
6.  **Quit**: Exits the program.

---

## 📁 File Structure

* `CS303Pgm1Template.cpp`: The main entry point of the application.
* `DynamicArray.h`: Header file for the `DynamicArray` class declaration.
* `DynamicArray.cpp`: Implementation file for the `DynamicArray` class methods.
* `A1input.txt`: An example input file with valid integers.
* `A2input.txt`: An example input file containing both integers and non-integer strings to demonstrate error handling.
* `error.txt`: This file is created/appended to when the program encounters non-integer data or other errors while reading from an input file.
