#include <iostream>
#include <vector>
#include "Memory.h" // Incluye la estructura Memory creada anteriormente
#include "Process.h" // Incluye la estructura Process creada anteriormente
using namespace std;

int main()
{
    Memory memory(1024, 256); // Crea una instancia de la estructura Memory con 1024 bytes de capacidad y páginas de 256 bytes cada una
    memory.printMemory(); // Muestra el estado inicial de la memoria

    vector<Process> processes; // Crea un vector para almacenar los procesos
    processes.push_back(Process(1, 180)); // Crea el proceso 1 con 180 bytes de tamaño y lo agrega al vector
    processes.push_back(Process(2, 222)); // Crea el proceso 2 con 222 bytes de tamaño y lo agrega al vector
    processes.push_back(Process(3, 76)); // Crea el proceso 3 con 76 bytes de tamaño y lo agrega al vector
    processes.push_back(Process(4, 300)); // Crea el proceso 4 con 300 bytes de tamaño y lo agrega al vector
    processes.push_back(Process(5, 100)); // Crea el proceso 5 con 100 bytes de tamaño y lo agrega al vector

    for (Process p : processes) { // Recorre los procesos del vector
        memory.memAlloc(p.id, p.size); // Asigna memoria al proceso usando First-Fit
        memory.printMemory(); // Muestra el estado de la memoria después de la asignación
    }

    for (Process p : processes) { // Recorre los procesos del vector en orden inverso
        memory.freeMem(p.id); // Libera la página asignada al proceso
        memory.printMemory(); // Muestra el estado de la memoria después de la liberación
    }

    return 0;
}
