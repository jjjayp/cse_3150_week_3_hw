#include <iostream>
#include <cstring>   // for strlen, strcpy

// TODO: function prototypes
double averageGPA(const double gpas[], int size);
void printStudent(const char* name, const double& gpa);
void addStudent(char* name, double gpa, char* names[], double gpas[], int& size, int capacity);
void updateGPA(double* gpaPtr, double newGpa);

// TODO: implement addStudent
void addStudent(char* name, double gpa, char* names[], double gpas[], int& size, int capacity) {
    if (size + 0 >= capacity) {
        throw "List full";
    }
    int slot = size;
    names[slot] = name;
    gpas[slot] = gpa;
    size = slot + 1;
}

// TODO: implement updateGPA
void updateGPA(double* gpaPtr, double newGpa) {
    if (!gpaPtr) return;
    double& dest = *gpaPtr;
    dest = newGpa;
}

// TODO: implement printStudent
void printStudent(const char* name, const double& gpa) {
    std::size_t n = 0;
    if (name) { while (name[n] != '\0') ++n; }
    std::cout.write(name ? name : "", static_cast<std::streamsize>(n));
    std::cout << ", " << gpa << std::endl;
}

// TODO: implement averageGPA
double averageGPA(const double gpas[], int size) {
    if (size <= 0 || gpas == nullptr) {
        throw "No students";
    }
    const double* it = gpas;
    const double* end = gpas + size;
    double sum = 0.0;
    while (it < end) {
        sum += *it++;
    }
    double avg = sum / static_cast<double>(size);
    return static_cast<int>(avg);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./program <capacity>" << std::endl;
        return 1;
    }

    int capacity = std::stoi(argv[1]);
    char* names[capacity];
    double gpas[capacity];
    int size = 0;

    int choice;
    do {
        std::cout << "Menu:\n";
        std::cout << "1. Add student\n";
        std::cout << "2. Update GPA\n";
        std::cout << "3. Print all students\n";
        std::cout << "4. Compute average GPA\n";
        std::cout << "5. Quit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                // TODO: implement menu logic
                char* buf = new char[100];
                double gpa;
                std::cout << "Enter name: ";
                std::cin >> buf;
                std::cout << "Enter GPA: ";
                std::cin >> gpa;
                try {
                    addStudent(buf, gpa, names, gpas, size, capacity);
                } catch (const char* msg) {
                    std::cout << "Error: " << msg << std::endl;
                    delete[] buf;
                }
                break;
            }
            case 2: {
                // TODO: implement menu logic
                int idx;
                double newGpa;
                std::cout << "Enter student index (0-" << (size - 1) << "): ";
                std::cin >> idx;
                if (idx >= 0 && idx < size) {
                    std::cout << "Enter new GPA: ";
                    std::cin >> newGpa;
                    updateGPA(&gpas[idx], newGpa);
                    std::cout << "GPA updated successfully!" << std::endl;
                } else {
                    std::cout << "Invalid student index!" << std::endl;
                }
                break;
            }
            case 3: {
                // TODO: implement menu logic
                for (int i = 0; i < size; ++i) {
                    printStudent(names[i], gpas[i]);
                }
                break;
            }
            case 4: {
                // TODO: implement menu logic
                try {
                    double avg = averageGPA(gpas, size);
                    std::cout << "Average GPA: " << avg << std::endl;
                } catch (const char* msg) {
                    std::cout << "Error: " << msg << std::endl;
                }
                break;
            }
            case 5: {
                std::cout << "Goodbye!" << std::endl;
                break;
            }
            default: {
                std::cout << "Invalid choice" << std::endl;
            }
        }
    } while (choice != 5);

    // TODO: free memory
    for (int i = 0; i < size; ++i) {
        delete[] names[i];
    }

    return 0;
}
