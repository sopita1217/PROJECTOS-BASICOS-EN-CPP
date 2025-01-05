#include <iostream>
#include <cmath>
int main(){
char op;
double num1, num2;
double result;

std::cout << "INGRESA EL PRIMER NUMERO\n";
std::cin >> num1;

std::cout << "ingresa que operacion quieres hacer (-+*/)\n";
std::cin >> op;

std::cout << "INGRESA EL SEGUNDO NUMERO\n";
std::cin >> num2;

switch (op){ //ES COMO UN IF STATEMENT PERO MEJOR PQ PUEDES DETERMINAR VARIOS CASOS MAS FACILMENTE
     case '+':
        result = num1 + num2;
        std::cout << result << '\n';
        break;
     case '-':
        result = num1 - num2;
        std::cout << result << '\n';
        break;
    case '*':
        result = num1 * num2;
        std::cout << result << '\n';
        break;
    case '/':
        result = num1 / num2;
        std::cout << result << '\n';
        break;
    default:
        std::cout << "no es un operador valido\n";
        break;
}
}
