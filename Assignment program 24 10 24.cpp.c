#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Employee {
    char name[50];
    int id;
    float salary;
};

// Function to write employee data
void writeToFile(const Employee* employees, int count) {
    ofstream outFile("employee.dat", ios::binary | ios::app);
    
    if (!outFile) {
        cerr << "Error! Could not open the file for writing" << endl;
        return;
    }
    
    // Write each employee structure to the binary file
    for (int i = 0; i < count; ++i) {
        outFile.write(reinterpret_cast<const char*>(&employees[i]), sizeof(employees[i]));
    }

    if (outFile.fail()) {
        cerr << "Error! Could not write data to the binary file" << endl;
    } else {
        cout << count << " Employee(s) data written to file successfully" << endl;
    }
    
    outFile.close();
}

// Function to read employee data from the file
void readFromFile() {
    Employee employee;
    
    ifstream inFile("employee.dat", ios::binary);
    if (!inFile) {
        cerr << "Error! Could not open file for reading!" << endl;
        return;
    }
    
    // Read structure from the file
    while (inFile.read(reinterpret_cast<char*>(&employee), sizeof(employee))) {
        cout << "\nEmployee data read from binary file:" << endl;
        cout << "Name: " << employee.name << endl;
        cout << "ID: " << employee.id << endl;
        cout << "Salary: " << employee.salary << endl;
    }

    if (inFile.eof()) {
        cout << "Reached the end of the file." << endl;
    } else {
        cerr << "Error! Could not read data from the binary file" << endl;
    }
    
    inFile.close();
}

int main() {
    const int numEmployees = 3; // Number of employees
    Employee employees[numEmployees];
    
    // Input employee details
    for (int i = 0; i < numEmployees; ++i) {
        cout << "Enter details for Employee " << (i + 1) << endl;
        cout << "Name: ";
        cin.ignore();  // Clear the input buffer
        cin.getline(employees[i].name, 50);
        cout << "ID: ";
        cin >> employees[i].id;
        cout << "Salary: ";
        cin >> employees[i].salary;
    }
    
    // Write employee data to binary file
    writeToFile(employees, numEmployees);
    
    // Read employee data from binary file
    readFromFile();
    
    return 0;
}