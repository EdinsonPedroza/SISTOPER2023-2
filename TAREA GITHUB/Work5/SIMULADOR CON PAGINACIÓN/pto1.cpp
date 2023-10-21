#include <iostream>
#include <vector>
using namespace std;

// Estructura que representa una página de memoria
struct Page {
    int id; // ID del proceso que ocupa la página o -1 si está libre
    int size; // Tamaño de la página en bytes
    bool free; // Estado de la página: true si está libre, false si está ocupada
    Page(int id, int size, bool free) : id(id), size(size), free(free) {} // Constructor
};

// Estructura que representa la memoria paginada
struct Memory {
    vector<Page> pages; // Vector que almacena las páginas de memoria
    int capacity; // Capacidad total de la memoria en bytes
    int used; // Cantidad de memoria usada en bytes
    Memory(int capacity, int pageSize); // Constructor que recibe la capacidad de la memoria y el tamaño de las páginas
    void memAlloc(int processID, int size); // Función que asigna memoria a una página
    void freeMem(int processID); // Función que libera la página asignada a un proceso
    void printMemory(); // Función que muestra el estado actual de la memoria
};
