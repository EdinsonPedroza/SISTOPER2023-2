#include <iostream>
#include <vector>
using namespace std;

// Estructura que representa un segmento de memoria
struct Segment {
    int id; // ID del proceso que ocupa el segmento o -1 si está libre
    int size; // Tamaño del segmento en bytes
    bool free; // Estado del segmento: true si está libre, false si está ocupado
    Segment(int id, int size, bool free) : id(id), size(size), free(free) {} // Constructor
};

// Estructura que representa la memoria segmentada
struct Memory {
    vector<Segment> segments; // Vector que almacena los segmentos de memoria
    int capacity; // Capacidad total de la memoria en bytes
    int used; // Cantidad de memoria usada en bytes
    Memory(int capacity, vector<int> partitionSizes); // Constructor que recibe la capacidad de la memoria y los tamaños de las particiones
    void memAlloc(int processID, int size); // Función que asigna memoria a un segmento usando First-Fit
    void freeMem(int processID); // Función que libera el segmento asignado a un proceso
    void printMemory(); // Función que muestra el estado actual de la memoria
};
