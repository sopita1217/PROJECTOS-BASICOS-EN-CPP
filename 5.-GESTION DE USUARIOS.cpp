/*Proyecto: Sistema básico de gestión de usuarios
Crea un programa que permita gestionar usuarios.
Cada usuario tendrá un nombre, una edad y un correo electrónico. 
El sistema debe permitir agregar usuarios, ver una lista de todos los usuarios y buscar un usuario por su correo.
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Estructura para almacenar los datos de un usuario
struct Usuario {
    string nombre;
    int edad;
    string correo;
};
// Función para agregar un usuario al archivo
void agregarUsuario();
// Función para ver la lista de usuarios
void verUsuarios();
// Función para buscar un usuario por correo
void buscarUsuario();
int main() {
    int opcion;

    do {
        cout << "\n--- Sistema de Gestion de Usuarios ---\n";
        cout << "1. Agregar usuario\n";
        cout << "2. Ver lista de usuarios\n";
        cout << "3. Buscar usuario por correo\n";
        cout << "4. Salir\n";
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarUsuario();
                break;
            case 2:
                verUsuarios();
                break;
            case 3:
                buscarUsuario();
                break;
            case 4:
                eliminarUsuarios();
                break;
            case 5:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opcion invalida. Intenta de nuevo.\n";
        }
    } while (opcion != 5);

    return 0;
}
//FUNCION PARA AGREGAR USUARIOS
void agregarUsuario() {
    Usuario nuevoUsuario;
    cout << "Ingresa el nombre del usuario: ";
    cin.ignore();
    getline(cin, nuevoUsuario.nombre);
    cout << "Ingresa la edad del usuario: ";
    cin >> nuevoUsuario.edad;
    cout << "Ingresa el correo del usuario: ";
    cin >> nuevoUsuario.correo;

    // Guardar en el archivo
    ofstream archivo("usuarios.txt", ios::app);
    if (archivo.is_open()) {
        archivo << nuevoUsuario.nombre << "," << nuevoUsuario.edad << "," << nuevoUsuario.correo << endl;
        archivo.close();
        cout << "Usuario agregado exitosamente.\n";
    } else {
        cout << "Error al abrir el archivo.\n";
    }
}
// Función para ver la lista de usuarios
void verUsuarios() {
    ifstream archivo("usuarios.txt");
    string linea;
    cout << "Lista de usuarios:\n";
    if (archivo.is_open()) {
        while (getline(archivo, linea)) {
            stringstream ss(linea);
            string nombre, edad, correo;

            getline(ss, nombre, ',');
            getline(ss, edad, ',');
            getline(ss, correo, ',');

            cout << "Nombre: " << nombre << ", Edad: " << edad << ", Correo: " << correo << endl;
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo.\n";
    }
}
//FUNCION PARA BUSCAR USUARIOS
void buscarUsuario() {
    ifstream archivo("usuarios.txt");
    string correoBuscado;
    cout << "Ingresa el correo del usuario a buscar: ";
    cin >> correoBuscado;

    string linea;
    bool encontrado = false;
    if (archivo.is_open()) {
        while (getline(archivo, linea)) {
            stringstream ss(linea);
            string nombre, edad, correo;

            getline(ss, nombre, ',');
            getline(ss, edad, ',');
            getline(ss, correo, ',');

            if (correo == correoBuscado) {
                cout << "Usuario encontrado:\n";
                cout << "Nombre: " << nombre << ", Edad: " << edad << ", Correo: " << correo << endl;
                encontrado = true;
                break;
            }
        }
        archivo.close();
        if (!encontrado) {
            cout << "Usuario no encontrado.\n";
        }
    } else {
        cout << "No se pudo abrir el archivo.\n";
    }
}
//FUNCION PARA ELIMINAR USUARIOS
void eliminarUsuarios(){
    
}
