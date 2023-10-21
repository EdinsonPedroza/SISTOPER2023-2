// Constructor que recibe la capacidad de la memoria y los tamaños de las particiones
Memory::Memory(int capacity, vector<int> partitionSizes) {
    this->capacity = capacity;
    used = 0;
    for (int size : partitionSizes) { // Recorre los tamaños de las particiones
        segments.push_back(Segment(-1, size, true)); // Crea un segmento libre con el tamaño indicado y lo agrega al vector
    }
}

// Función que asigna memoria a un segmento usando First-Fit
void Memory::memAlloc(int processID, int size) {
    if (used + size > capacity) { // Si no hay suficiente memoria disponible
        cout << "No hay suficiente memoria para asignar al proceso " << processID << endl;
        return;
    }
    int index = -1; // Índice del segmento elegido para asignar
    for (int i = 0; i < segments.size(); i++) { // Recorre los segmentos de memoria
        if (segments[i].free && segments[i].size >= size) { // Si encuentra un segmento libre y suficientemente grande
            index = i; // Guarda el índice del segmento encontrado
            break; // Termina el bucle
        }
    }
    if (index == -1) { // Si no se encontró ningún segmento adecuado
        cout << "No se encontró ningún segmento adecuado para asignar al proceso " << processID << endl;
        return;
    }
    else { // Si se encontró un segmento adecuado
        cout << "Asignando " << size << " bytes al proceso " << processID << " en el segmento " << index << endl;
        segments[index].id = processID; // Asigna el segmento al proceso
        segments[index].free = false; // Marca el segmento como ocupado
        used += size; // Incrementa la cantidad de memoria usada
    }
}

// Función que libera el segmento asignado a un proceso
void Memory::freeMem(int processID) {
    int index = -1; // Índice del segmento asignado al proceso
    for (int i = 0; i < segments.size(); i++) { // Recorre los segmentos de memoria
        if (segments[i].id == processID) { // Si encuentra el segmento asignado al proceso
            index = i; // Guarda el índice del segmento encontrado
            break; // Termina el bucle
        }
    }
    if (index == -1) { // Si no se encontró ningún segmento asignado al proceso
        cout << "No se encontró ningún segmento asignado al proceso " << processID << endl;
        return;
    }
    else { // Si se encontró un segmento asignado al proceso
        cout << "Liberando " << segments[index].size << " bytes del proceso " << processID << " en el segmento " << index << endl;
        segments[index].id = -1; // Marca el segmento como libre
        segments[index].free = true; // Cambia el estado del segmento a libre
        used -= segments[index].size; // Decrementa la cantidad de memoria usada
    }
}

// Función que muestra el estado actual de la memoria
void Memory::printMemory() {
    cout << "Estado de la memoria:" << endl;
    cout << "Capacidad: " << capacity << " bytes" << endl;
    cout << "Usados: " << used << " bytes" << endl;
    cout << "Libres: " << capacity - used << " bytes" << endl;
    cout << "Segmentos:" << endl;
    for (int i = 0; i < segments.size(); i++) { // Recorre los segmentos de memoria
        cout << "Segmento " << i << ": ";
        if (segments[i].free) { // Si el segmento está libre
            cout << "Libre, ";
        }
        else { // Si el segmento está asignado a un proceso
            cout << "Proceso " << segments[i].id << ", ";
        }
        cout << "Tamaño: " << segments[i].size << " bytes" << endl;
    }
}
