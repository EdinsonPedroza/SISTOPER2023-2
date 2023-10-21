#include <iostream>
using namespace std;

// Estructura que representa un proceso
struct Process {
    int id; // Identificador único del proceso
    int size; // Tamaño del proceso en bytes
    Process(int id, int size) : id(id), size(size) {} // Constructor
};
