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
