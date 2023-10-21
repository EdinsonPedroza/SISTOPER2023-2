#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "MemoryManagement.h" // Incluye la clase MemoryManagement creada anteriormente
using namespace std;

// Clase que representa el lector de archivos
class Reader {
    private:
        string fileName; // Nombre del archivo a leer
        ifstream file; // Objeto para leer el archivo
        MemoryManagement *mm; // Puntero a un objeto de la clase MemoryManagement
    public:
        Reader(string fileName); // Constructor que recibe el nombre del archivo
        ~Reader(); // Destructor que cierra el archivo y libera la memoria
        void readData(); // Función que lee los datos del archivo y los procesa
};

// Constructor que recibe el nombre del archivo
Reader::Reader(string fileName) {
    this->fileName = fileName; // Guarda el nombre del archivo
    file.open(fileName); // Abre el archivo para leer
    if (file.is_open()) { // Si el archivo se abrió correctamente
        cout << "Archivo " << fileName << " abierto correctamente." << endl;
    }
    else { // Si hubo un error al abrir el archivo
        cout << "Error al abrir el archivo " << fileName << "." << endl;
    }
}

// Destructor que cierra el archivo y libera la memoria
Reader::~Reader() {
    file.close(); // Cierra el archivo
    cout << "Archivo " << fileName << " cerrado correctamente." << endl;
    delete mm; // Libera la memoria del objeto MemoryManagement
}

// Función que lee los datos del archivo y los procesa
void Reader::readData() {
    string line; // Variable para almacenar cada línea del archivo
    int memorySize; // Variable para almacenar el tamaño de la memoria
    int segments; // Variable para almacenar la cantidad de segmentos o particiones
    vector<int> partitionSizes; // Vector para almacenar los tamaños de las particiones
    int algorithm; // Variable para almacenar el algoritmo a usar: 1) First-fit, 2) Best-fit, 3) Worst-fit
    int processID; // Variable para almacenar el ID del proceso
    int processSize; // Variable para almacenar el tamaño del proceso

    while (getline(file, line)) { // Mientras haya líneas por leer en el archivo
        if (line[0] == '#') { // Si la línea empieza con '#', es un comentario y se ignora
            continue;
        }
        else if (line == "") { // Si la línea está vacía, se ignora
            continue;
        }
        else { // Si la línea tiene datos, se procesan según el caso
            if (!mm) { // Si aún no se ha creado el objeto MemoryManagement, se lee el tamaño de la memoria y se crea
                memorySize = stoi(line); // Convierte la línea a un entero que representa el tamaño de la memoria en bytes
                cout << "Tamaño de la memoria: " << memorySize << " bytes." << endl;
                mm = new MemoryManagement(memorySize); // Crea un nuevo objeto MemoryManagement con ese tamaño de memoria
            }
            else if (partitionSizes.size() < segments) { // Si ya se creó el objeto MemoryManagement, pero aún no se han leído todos los tamaños de las particiones, se lee el siguiente tamaño y se agrega al vector
                partitionSizes.push_back(stoi(line)); // Convierte la línea a un entero que representa el tamaño de una partición en bytes y lo agrega al vector
                cout << "Tamaño de la partición " << partitionSizes.size() << ": " << line << " bytes." << endl;
            }
            else if (!algorithm) { // Si ya se leyeron todos los tamaños de las particiones, pero aún no se ha leído el algoritmo a usar, se lee el algoritmo y se guarda en la variable correspondiente
                algorithm = stoi(line); // Convierte la línea a un entero que representa el algoritmo a usar: 1) First-fit, 2) Best-fit, 3) Worst-fit
                cout << "Algoritmo: ";
                switch (algorithm) { // Según el valor del algoritmo, se muestra su nombre
                    case 1: cout << "First-fit"; break;
                    case 2: cout << "Best-fit"; break;
                    case 3: cout << "Worst-fit"; break;
                    default: cout << "Inválido"; break;
                }
                cout << endl;
            }
            else { // Si ya se leyó el algoritmo a usar, se asume que las siguientes líneas son pares de valores que representan el ID y el tamaño de los procesos a asignar
                size_t pos = line.find(','); // Busca la posición de la coma que separa los valores
                if (pos != string::npos) { // Si se encontró la coma
                    processID = stoi(line.substr(0, pos)); // Convierte el primer valor a un entero que representa el ID del proceso
                    processSize = stoi(line.substr(pos + 1)); // Convierte el segundo valor a un entero que representa el tamaño del proceso en bytes
                    cout << "Proceso " << processID << " solicita " << processSize << " bytes." << endl;
                    string alg; // Variable para guardar el nombre del algoritmo según el valor de la variable algorithm
                    switch (algorithm) {
                        case 1: alg = "First-fit"; break;
                        case 2: alg = "Best-fit"; break;
                        case 3: alg = "Worst-fit"; break;
                        default: alg = "Inválido"; break;
                    }
                    mm->memAlloc(processID, processSize, alg); // Llama a la función memAlloc del objeto MemoryManagement para asignar memoria al proceso usando el algoritmo indicado
                    mm->printMemory(); // Muestra el estado de la memoria después de la asignación
                }
                else { // Si no se encontró la coma, se ignora la línea
                    continue;
                }
            }
        }
    }
}
