// Constructor que inicializa la memoria con un tamaño especificado
MemoryManagement::MemoryManagement(int size) {
    capacity = size;
    used = 0;
    memory.push_back(Block(-1, size)); // Crea un bloque libre con el tamaño total de la memoria
}

// Función que asigna un bloque de memoria a un proceso usando un algoritmo dado
void MemoryManagement::memAlloc(int processID, int size, string algorithm) {
    if (used + size > capacity) { // Si no hay suficiente memoria disponible
        cout << "No hay suficiente memoria para asignar al proceso " << processID << endl;
        return;
    }
    int index = -1; // Índice del bloque elegido para asignar
    if (algorithm == "First-fit") { // Si se usa el algoritmo First-fit
        for (int i = 0; i < memory.size(); i++) { // Recorre los bloques de memoria
            if (memory[i].id == -1 && memory[i].size >= size) { // Si encuentra un bloque libre y suficientemente grande
                index = i; // Guarda el índice del bloque encontrado
                break; // Termina el bucle
            }
        }
    }
    else if (algorithm == "Best-fit") { // Si se usa el algoritmo Best-fit
        int minSize = INT_MAX; // Tamaño mínimo del bloque encontrado hasta ahora
        for (int i = 0; i < memory.size(); i++) { // Recorre los bloques de memoria
            if (memory[i].id == -1 && memory[i].size >= size && memory[i].size < minSize) { // Si encuentra un bloque libre y suficientemente grande y menor que el mínimo actual
                index = i; // Guarda el índice del bloque encontrado
                minSize = memory[i].size; // Actualiza el tamaño mínimo
            }
        }
    }
    else if (algorithm == "Worst-fit") { // Si se usa el algoritmo Worst-fit
        int maxSize = 0; // Tamaño máximo del bloque encontrado hasta ahora
        for (int i = 0; i < memory.size(); i++) { // Recorre los bloques de memoria
            if (memory[i].id == -1 && memory[i].size >= size && memory[i].size > maxSize) { // Si encuentra un bloque libre y suficientemente grande y mayor que el máximo actual
                index = i; // Guarda el índice del bloque encontrado
                maxSize = memory[i].size; // Actualiza el tamaño máximo
            }
        }
    }
    else { // Si se usa un algoritmo desconocido
        cout << "Algoritmo inválido" << endl;
        return;
    }
    if (index == -1) { // Si no se encontró ningún bloque adecuado
        cout << "No se encontró ningún bloque adecuado para asignar al proceso " << processID << endl;
        return;
    }
    else { // Si se encontró un bloque adecuado
        cout << "Asignando " << size << " bytes al proceso " << processID << " en el bloque " << index << endl;
        if (memory[index].size == size) { // Si el bloque tiene el mismo tamaño que el solicitado
            memory[index].id = processID; // Asigna el bloque al proceso
        }
        else { // Si el bloque tiene un tamaño mayor que el solicitado
            Block newBlock(processID, size); // Crea un nuevo bloque con el ID y el tamaño del proceso
            memory[index].size -= size; // Reduce el tamaño del bloque original
            memory.insert(memory.begin() + index, newBlock); // Inserta el nuevo bloque antes del original
        }
        used += size; // Incrementa la cantidad de memoria usada
    }
}

// Función que libera el bloque de memoria asignado a un proceso
void MemoryManagement::freeMem(int processID) {
    int index = -1; // Índice del bloque asignado al proceso
    for (int i = 0; i < memory.size(); i++) { // Recorre los bloques de memoria
        if (memory[i].id == processID) { // Si encuentra el bloque asignado al proceso
            index = i; // Guarda el índice del bloque encontrado
            break; // Termina el bucle
        }
    }
    if (index == -1) { // Si no se encontró ningún bloque asignado al proceso
        cout << "No se encontró ningún bloque asignado al proceso " << processID << endl;
        return;
    }
    else { // Si se encontró un bloque asignado al proceso
        cout << "Liberando " << memory[index].size << " bytes del proceso " << processID << " en el bloque " << index << endl;
        memory[index].id = -1; // Marca el bloque como libre
        used -= memory[index].size; // Decrementa la cantidad de memoria usada
        if (index > 0 && memory[index - 1].id == -1) { // Si hay un bloque libre anterior al actual
            memory[index - 1].size += memory[index].size; // Fusiona los dos bloques libres
            memory.erase(memory.begin() + index); // Elimina el bloque actual
            index--; // Actualiza el índice del bloque fusionado
        }
        if (index < memory.size() - 1 && memory[index + 1].id == -1) { // Si hay un bloque libre posterior al actual
            memory[index].size += memory[index + 1].size; // Fusiona los dos bloques libres
            memory.erase(memory.begin() + index + 1); // Elimina el bloque posterior
        }
    }
}

// Función que muestra el estado actual de la memoria
void MemoryManagement::printMemory() {
    cout << "Estado de la memoria:" << endl;
    cout << "Capacidad: " << capacity << " bytes" << endl;
    cout << "Usados: " << used << " bytes" << endl;
    cout << "Libres: " << capacity - used << " bytes" << endl;
    cout << "Bloques:" << endl;
    for (int i = 0; i < memory.size(); i++) { // Recorre los bloques de memoria
        cout << "Bloque " << i << ": ";
        if (memory[i].id == -1) { // Si el bloque está libre
            cout << "Libre, ";
        }
        else { // Si el bloque está asignado a un proceso
            cout << "Proceso " << memory[i].id << ", ";
        }
        cout << "Tamaño: " << memory[i].size << " bytes" << endl;
    }
}
