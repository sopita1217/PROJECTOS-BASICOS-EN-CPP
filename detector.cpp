#include <iostream>           // Biblioteca para entrada/salida (std::cout, std::cerr)
#include <windows.h>          // Biblioteca para interactuar con la API de Windows
#include <psapi.h>            // Biblioteca para enumerar procesos y obtener información sobre ellos
#pragma comment(lib, "psapi.lib") // Vincula el programa con la biblioteca Psapi.lib (necesaria para algunas funciones)

int main() {
    // Declarar un array para almacenar los Process IDs (PIDs)
    DWORD processes[1024];
    // Declarar una variable para almacenar el número de procesos encontrados
    DWORD bytesReturned;

    // Llama a EnumProcesses para obtener los PIDs de los procesos activos
    if (!EnumProcesses(processes, sizeof(processes), &bytesReturned)) {
        // Si falla, muestra un mensaje de error y termina el programa
        std::cerr << "Error al enumerar procesos." << std::endl;
        return 1;
    }

    // Calcula el número de procesos activos dividiendo los bytes devueltos entre el tamaño de DWORD
    DWORD processCount = bytesReturned / sizeof(DWORD);

    std::cout << "Procesos activos:" << std::endl;

    // Iterar por todos los PIDs obtenidos
    for (DWORD i = 0; i < processCount; i++) {
        // Ignorar PIDs no válidos (por ejemplo, PID 0)
        if (processes[i] == 0) {
            continue;
        }

        // Abre el proceso con permisos para consultar información
        HANDLE processHandle = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processes[i]);

        // Si el proceso no pudo ser abierto, continuar con el siguiente
        if (!processHandle) {
            continue;
        }

        // Declarar un buffer para almacenar el nombre del proceso
        TCHAR processName[MAX_PATH] = TEXT("<desconocido>");

        // Intentar obtener el nombre del módulo principal del proceso
        if (GetModuleBaseName(processHandle, NULL, processName, sizeof(processName) / sizeof(TCHAR))) {
            // Imprimir el PID y el nombre del proceso
            std::cout << "PID: " << processes[i] << " - Nombre: " << processName << std::endl;
        }

        // Cierra el handle del proceso para liberar recursos
        CloseHandle(processHandle);
    }

    return 0; // Finaliza el programa
}
