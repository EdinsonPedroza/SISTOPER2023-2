// Constructor que recibe la capacidad de la memoria y el tamaño de las páginas
Memory::Memory(int capacity, int pageSize) {
    this->capacity = capacity;
    used = 0;
    int numPages = capacity / pageSize; // Calcula el número de páginas que caben en la memoria
    for (int i = 0; i < numPages; i++) { // Recorre el número de páginas
        pages.push_back(Page(-1, pageSize, true)); // Crea una página libre con el tamaño indicado y la agrega al vector
    }
}

// Función que asigna memoria a una página
void Memory::memAlloc(int processID, int size) {
    if (used + size > capacity) { // Si no hay suficiente memoria disponible
        cout << "No hay suficiente memoria para asignar al proceso " << processID << endl;
        return;
    }
    int index = -1; // Índice de la página elegida para asignar
    for (int i = 0; i < pages.size(); i++) { // Recorre las páginas de memoria
        if (pages[i].free && pages[i].size >= size) { // Si encuentra una página libre y suficientemente grande
            index = i; // Guarda el índice de la página encontrada
            break; // Termina el bucle
        }
    }
    if (index == -1) { // Si no se encontró ninguna página adecuada
        cout << "No se encontró ninguna página adecuada para asignar al proceso " << processID << endl;
        return;
    }
    else { // Si se encontró una página adecuada
        cout << "Asignando " << size << " bytes al proceso " << processID << " en la página " << index << endl;
        pages[index].id = processID; // Asigna la página al proceso
        pages[index].free = false; // Marca la página como ocupada
        used += size; // Incrementa la cantidad de memoria usada
    }
}

// Función que libera la página asignada a un proceso
void Memory::freeMem(int processID) {
    int index = -1; // Índice de la página asignada al proceso
    for (int i = 0; i < pages.size(); i++) { // Recorre las páginas de memoria
        if (pages[i].id == processID) { // Si encuentra la página asignada al proceso
            index = i; // Guarda el índice de la página encontrada
            break; // Termina el bucle
        }
    }
    if (index == -1) { // Si no se encontró ninguna página asignada al proceso
        cout << "No se encontró ninguna página asignada al proceso " << processID << endl;
        return;
    }
    else { // Si se encontró una página asignada al proceso
        cout << "Liberando " << pages[index].size << " bytes del proceso " << processID << " en la página " << index << endl;
        pages[index].id = -1; // Marca la página como libre
        pages[index].free = true; // Cambia el estado de la página a libre
        used -= pages[index].size; // Decrementa la cantidad de memoria usada
    }
}

// Función que muestra el estado actual de la memoria
void Memory::printMemory() {
    cout << "Estado de la memoria:" << endl;
    cout << "Capacidad: " << capacity << " bytes" << endl;
    cout << "Usados: " << used << " bytes" << endl;
    cout << "Libres: " << capacity - used << " bytes" << endl;
    cout << "Páginas:" << endl;
    for (int i = 0; i < pages.size(); i++) { // Recorre las páginas de memoria
        cout << "Página " << i << ": ";
        if (pages[i].free) { // Si la página está libre
            cout << "Libre, ";
        }
        else { // Si la página está asignada a un proceso
            cout << "Proceso " << pages[i].id << ", ";
        }
        cout << "Tamaño: " << pages[i].size << " bytes" << endl;
    }
}
