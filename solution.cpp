#include <iostream>
#include <cstring>
#include <string>

// Function Prototypes 
void addStudent(char* name, double gpa, char* names[], double gpas[], int& size, int capacity);
void updateGPA(double* gpaPtr, double newGpa);
void printStudent(const char* name, const double& gpa);
double averageGPA(const double gpas[], int size);

// Implementation of addStudent 
void addStudent(char* name, double gpa, char* names[], double gpas[], int& size, int capacity) {
    if (size >= capacity) {
        throw "Error: List is full"; // Throwing exception as string 
    }
    // Allocate memory for the new name and copy it 
    names[size] = new char[std::strlen(name) + 1];
    std::strcpy(names[size], name);
    gpas[size] = gpa;
    size++;
}

// Implementation of updateGPA using a pointer 
void updateGPA(double* gpaPtr, double newGpa) {
    if (gpaPtr != nullptr) {
        *gpaPtr = newGpa;
    }
}

// Implementation of printStudent using const references 
void printStudent(const char* name, const double& gpa) {
    std::cout << "Student: " << name << ", GPA: " << gpa << std::endl;
}

// Implementation of averageGPA with exception handling 
double averageGPA(const double gpas[], int size) {
    if (size == 0) {
        throw "Error: No students to average";
    }
    double sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += gpas[i];
    }
    return sum / size;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./program <capacity>" << std::endl;
        return 1;
    }

    int capacity = std::stoi(argv[1]); // Convert command line arg 
    char** names = new char*[capacity]; // Dynamic array of char pointers [cite: 5]
    double* gpas = new double[capacity]; // Dynamic array of doubles [cite: 5]
    int size = 0;

    int choice;
    do {
        std::cout << "\nMenu:\n1. Add student\n2. Update GPA\n3. Print all students\n4. Compute average GPA\n5. Quit\nEnter choice: ";
        if (!(std::cin >> choice)) break;

        switch (choice) {
            case 1: {
                char tempName[100];
                double tempGpa;
                std::cout << "Enter name: ";
                std::cin >> tempName;
                std::cout << "Enter GPA: ";
                std::cin >> tempGpa;
                try {
                    addStudent(tempName, tempGpa, names, gpas, size, capacity);
                } catch (const char* msg) {
                    std::cout << msg << std::endl;
                }
                break;
            }
            case 2: {
                int index;
                double newGpa;
                std::cout << "Enter student index (0 to " << size-1 << "): ";
                std::cin >> index;
                if (index >= 0 && index < size) {
                    std::cout << "Enter new GPA: ";
                    std::cin >> newGpa;
                    updateGPA(&gpas[index], newGpa);
                } else {
                    std::cout << "Invalid index" << std::endl;
                }
                break;
            }
            case 3: {
                for (int i = 0; i < size; ++i) {
                    printStudent(names[i], gpas[i]);
                }
                break;
            }
            case 4: {
                try {
                    double avg = averageGPA(gpas, size);
                    std::cout << "Average GPA: " << avg << " (Rounded: " << static_cast<int>(avg) << ")" << std::endl;
                } catch (const char* msg) {
                    std::cout << msg << std::endl;
                }
                break;
            }
            case 5:
                std::cout << "Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice" << std::endl;
        }
    } while (choice != 5);

    // Cleanup memory [cite: 5]
    for (int i = 0; i < size; ++i) {
        delete[] names[i];
    }
    delete[] names;
    delete[] gpas;

    return 0;
}
