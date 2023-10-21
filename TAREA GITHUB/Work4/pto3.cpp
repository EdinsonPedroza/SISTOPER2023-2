#include <iostream>
using namespace std;

int main()
{
    MemoryManagement mm(100); // Crea una instancia de la clase MemoryManagement con 100 bytes de capacidad
    mm.printMemory(); // Muestra el estado inicial de la memoria

    mm.memAlloc(1, 20, "First-fit"); // Asigna 20 bytes al proceso 1 usando First-fit
    mm.printMemory(); // Muestra el estado de la memoria

    mm.memAlloc(2, 30, "Best-fit"); // Asigna 30 bytes al proceso 2 usando Best-fit
    mm.printMemory(); // Muestra el estado de la memoria

    mm.memAlloc(3, 40, "Worst-fit"); // Asigna 40 bytes al proceso 3 usando Worst-fit
    mm.printMemory(); // Muestra el estado de la memoria

    mm.freeMem(1); // Libera el bloque de memoria asignado al proceso 1
    mm.printMemory(); // Muestra el estado de la memoria

    mm.memAlloc(4, 15, "First-fit"); // Asigna 15 bytes al proceso 4 usando First-fit
    mm.printMemory(); // Muestra el estado de la memoria

    mm.freeMem(3); // Libera el bloque de memoria asignado al proceso 3
    mm.printMemory(); // Muestra el estado de la memoria

    mm.memAlloc(5, 25, "Best-fit"); // Asigna 25 bytes al proceso 5 usando Best-fit
    mm.printMemory(); // Muestra el estado de la memoria

    mm.freeMem(2); // Libera el bloque de memoria asignado al proceso 2
    mm.printMemory(); // Muestra el estado de la memoria

    mm.freeMem(4); // Libera el bloque de memoria asignado al proceso 4
    mm.printMemory(); // Muestra el estado de la memoria

    mm.freeMem(5); // Libera el bloque de memoria asignado al proceso 5
    mm.printMemory(); // Muestra el estado final de la memoria

    return 0;
}
