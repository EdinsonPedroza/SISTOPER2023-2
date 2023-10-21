#include <iostream>
#include <vector>
using namespace std;

// Estructura que representa un bloque de memoria
struct Block {
    int id; // ID del proceso que ocupa el bloque o -1 si está libre
    int size; // Tamaño del bloque en bytes
    Block(int id, int size) : id(id), size(size) {} // Constructor
};

// Clase que representa la gestión de la memoria
class MemoryManagement {
    private:
        vector<Block> memory; // Vector que almacena los bloques de memoria
        int capacity; // Capacidad total de la memoria en bytes
        int used; // Cantidad de memoria usada en bytes
    public:
        MemoryManagement(int size); // Constructor que inicializa la memoria con un tamaño especificado
        void memAlloc(int processID, int size, string algorithm); // Función que asigna un bloque de memoria a un proceso usando un algoritmo dado
        void freeMem(int processID); // Función que libera el bloque de memoria asignado a un proceso
        void printMemory(); // Función que muestra el estado actual de la memoria
};
