#include <iostream> // Para entrada y salida
#include <string>   // Para trabajar con cadenas de texto

// Función creada para cifrar texto utilizando el método César usando el tecto para cifrar y la clave para descifrar
std::string cifrarCesar(const std::string& texto, int clave) {
    std::string textoCifrado = ""; // Almacena el texto cifrado aqui

    // Recorremos cada carácter del texto original en un loop
    for (char c : texto) {
        if (isalpha(c)) { // Verificamos si el carácter es una letra con el isalpha
            char base = islower(c) ? 'a' : 'A'; // Determinamos si es minúscula o mayúscula (Esto es como un for loop pero en mimniatura compara lo que esta antes del punto y si es false hace lo que esta despues)
            // Aplicamos el desplazamiento manteniendo el carácter dentro del rango del alfabeto
            c = (c - base + clave) % 26 + base;//base es el valor base de los characteres y clave es el numero de veces que va a cambiar el character a la derecha, llamamos a esto clave
        }
        // Agregamos el carácter cifrado al texto cifrado
        textoCifrado += c;//en esta variable se almacena el texto mas el character usando += que es un prefijo, c representa el character cifrado
    }

    return textoCifrado; // Devolvemos el texto cifrado
}

// Función para descifrar texto cifrado utilizando el método César
std::string descifrarCesar(const std::string& texto, int clave) {
    // Para descifrar, usamos la clave negativa (movemos en dirección contraria)
    return cifrarCesar(texto, 26 - (clave % 26));//para descifrar pones la variable donde esta almacenada el tecto y la restas entre la variable donde esta almacenada la clave
}

//AHORA QUE TENEMOS PARA CIFRAR Y DESCIFRAR EMPEZAREMOS LA FUNCION PRINCIPAL
int main() {
    std::string textoOriginal; // Almacena el texto ingresado por el usuario
    int clave;                 // Clave numérica para el cifrado
    int opcion;                // Opción elegida por el usuario (cifrar/descifrar)

    // Pedimos al usuario que elija entre cifrar o descifrar
    std::cout << "\nElige una opción:\n1. Cifrar texto\n2. Descifrar texto\nOpción: ";
    std::cin >> opcion;//aqui almacenamos lo que escribio el usuario en una variable para usarla despues
    std::cin.ignore(); // Limpia el buffer de entrada para evitar problemas al leer el texto

    // Pedimos al usuario que ingrese el texto para cifrar o descifrar
    std::cout << "Ingresa el texto: ";
    std::getline(std::cin, textoOriginal);

    // Pedimos al usuario la clave de cifrado/descifrado
    std::cout << "Ingresa la clave numérica: ";
    std::cin >> clave; //aqui almacenamos la clave

    // Variable para almacenar el resultado (cifrado o descifrado)
    std::string resultado;

    if (opcion == 1) {//AQUI USAMOS UN IF STATEMENT PARA VER COMO CONTINUAR DEPENDIENDO DEL INPUT DEL USUARIO
        // Opción 1: Cifrar el texto con las funciones previamente creadas 
        resultado = cifrarCesar(textoOriginal, clave);
        std::cout << "Texto cifrado: " << resultado << "\n";
    } else if (opcion == 2) {
        // Opción 2: Descifrar el texto
        resultado = descifrarCesar(textoOriginal, clave);
        std::cout << "Texto descifrado: " << resultado << "\n";
    } else {
        // Opción inválida
        std::cout << "Opción no válida.\n";
    }

    return 0; // Finalizamos el programa
}
