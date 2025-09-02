#include <iostream>

using namespace std;

void Problema1();
void Problema2();
void Problema3();
void Problema4();
void Problema5();
void Problema6();
void Problema7();
void Problema8();
void Problema9();
void Problema10();
void Problema11();
void Problema12();
void Problema13();
void Problema14();
void Problema15();
void Problema16();
void Problema17();

//Funciones extras
int Factorial(int numero);
bool esPrimo(int num);
int MCD(int a, int b);
int MCM(int a, int b);
bool esPalindromo(int numero);
int TerminosCollatz(int n);
void Serie(int n);
void encontrarSerieCollatz(int k);
int numeroTriangular(int n);
int contarDivisores(int num);

int main()
{
    cout << "Hola, Bienvenido a la Practica #1 de LAB." << endl;
    cout << "\nA continuacion tendras los problemas a resolver." << endl;

    int opcion = 1;

    while(opcion != 0) {
        cout << "\n1. Verificar si un caracter es vocal, consonate o ninguna de las dos." << endl;
        cout << "2. Determinar la minima cantidad de billetes y monedas necesarias para una cantidad determinada." << endl;
        cout << "3. Validar una fecha." << endl;
        cout << "4. Validar y calcular una hora." << endl;
        cout << "5. Imprimir un patron." << endl;
        cout << "6. Hallar el valor aprocimado de euler." << endl;
        cout << "7. Hallar la suma de todos los numeros pares de la serie de fibonacci hasta un numero n." << endl;
        cout << "8. Calcular la suma de todos los multimos de 2 numeros menores a un numero n" << endl;
        cout << "9. Calcular la suma de todos los digitos de un numero n elevados a si mismos." << endl;
        cout << "10. Hallar el enesimo numero primo." << endl;
        cout << "11. Calcular el minimo comun multiplo de todos los numeros enteros entre 1 y un numero ingresado." << endl;
        cout << "12. Calcular el maximo factor primo de un numero n." << endl;
        cout << "13. Calcular la suma de todos los numeros primos menores a un numero ingresado." << endl;
        cout << "14. Calcular el maximo palindromo." << endl;
        cout << "15. Calcular la suma de los numeros de la diagonal de una espiral." << endl;
        cout << "16. Hallar la semilla inicial con la serie mas larga en la serie de collatz menor a un numero k." << endl;
        cout << "17. Calcular el numero triangular que tiene mas de k divisores." << endl;
        cout << "0. Salir del programa." << endl;

        cout << "\n Por favor, ingrese la opcion deseada: " << endl;
        cin >> opcion;

        if (opcion == 0) {
            cout << "Gracias por usar mi programa, que tengas un feliz dia." << endl;
            break;
        }

        switch(opcion) {
        case 1:
            Problema1();
            break;
        case 2:
            Problema2();
            break;
        case 3:
            Problema3();
            break;
        case 4:
            Problema4();
            break;
        case 5:
            Problema5();
            break;
        case 6:
            Problema6();
            break;
        case 7:
            Problema7();
            break;
        case 8:
            Problema8();
            break;
        case 9:
            Problema9();
            break;
        case 10:
            Problema10();
            break;
        case 11:
            Problema11();
            break;
        case 12:
            Problema12();
            break;
        case 13:
            Problema13();
            break;
        case 14:
            Problema14();
            break;
        case 15:
            Problema15();
            break;
        case 16:
            Problema16();
            break;
        case 17:
            Problema17();
            break;
        default:
            cout << "La opcion no es valida." << endl;
            break;
        }
    }
    return 0;
}

//Problema #1 identificar caracter
void Problema1() {
    char caracter;
    cout << "Por favor, ingrese un caracter: "; cin >> caracter;

    if (caracter == 'A' || caracter == 'E' || caracter == 'I'
        || caracter == 'O' || caracter == 'U') {
        cout << caracter << " es una vocal" << endl;
    } else if (caracter == 'a' || caracter == 'e' || caracter == 'i'
               || caracter == 'o' || caracter == 'u') {
        cout << caracter << " es una vocal" << endl;
    } else if (caracter >= 65 && caracter <= 90 || caracter >= 97 && caracter <= 122) {
        cout << caracter << " es una consonante" << endl;
    } else {
        cout << "No es una letra" << endl;
    }
}

//Problema #2 Determinar minima cantidad de billetes
void Problema2() {
    int cantidad;
    cout << "Por favor, ingrese la cantidad calcular: "; cin >> cantidad;
    int residuo = cantidad;

    int billete50000 = residuo / 50000;
    residuo %= 50000;

    int billete20000 = residuo / 20000;
    residuo %= 20000;

    int billete10000 = residuo / 10000;
    residuo %= 10000;

    int billete5000 = residuo / 5000;
    residuo %= 5000;

    int billete2000 = residuo / 2000;
    residuo %= 2000;

    int billete1000 = residuo / 1000;
    residuo %= 1000;

    int monedas500 = residuo / 500;
    residuo %= 500;

    int monedas200 = residuo / 200;
    residuo %= 200;

    int monedas100 = residuo / 100;
    residuo %= 100;

    int monedas50 = residuo / 50;
    residuo %= 50;

    cout << "$50.000 : " << billete50000 << endl;
    cout << "$20.000 : " << billete20000 << endl;
    cout << "$10.000 : " << billete10000 << endl;
    cout << "$5.000 : " << billete5000 << endl;
    cout << "$2.000 : " << billete2000 << endl;
    cout << "$1.000 : " << billete1000 << endl;
    cout << "$500 : " << monedas500 << endl;
    cout << "$200 : " << monedas200 << endl;
    cout << "$100 : " << monedas100 << endl;
    cout << "$50 : " << monedas50 << endl;

    if (residuo > 0)
        cout << "Faltante: " << residuo << endl;
}

//Problema #3 validar fecha
void Problema3() {
    int mes, dia;

    cout << "Por favor, Ingrese el mes: "; cin >> mes;
    if (mes >= 1 && mes <= 12){
        cout << "Por favor, Ingrese un dia de el mes " << mes << ": ";
        cin >> dia;

        if (dia >= 1 && dia <= 31){
            if (mes == 2 && dia == 29){
                cout << dia << "/" << mes << " es valida en bisiesto." << endl;
            } else if (mes == 2 && dia <= 28) {
                cout << dia << "/" << mes << " es una fecha valida" << endl;
            } else if (mes == 2 && dia >= 30) {
                cout << dia << "/" << mes << " es una fecha invalida" << endl;
            } else if ((mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) && dia <= 31){
                cout << dia << "/" << mes << " es una fecha valida" << endl;
            } else if (dia <= 30) {
                cout << dia << "/" << mes << " es una fecha valida" << endl;
            } else {
                cout << dia << "/" << mes << " es una fecha invalida" << endl;
            }
        } else {
            cout << dia << " es un dia invalido" << endl;
        }
    } else {
        cout << mes << " es un mes invalido" << endl;
    }
}

//Problma #4 calcular hora

void Problema4() {
    int hora1, hora2, sumHoras, minutos;

    cout << "Por favor, Ingresa la primer hora: "; cin >> hora1;
    if(hora1 >= 2400 || hora1 % 100 >= 60){
        cout << hora1 << " es un tiempo invalido";
    } else {
        cout << "Por favor, Ingresa la segunda hora: "; cin >> hora2;
        if (hora2 >= 2400 || hora2 % 100 >= 60){
            cout << hora2 << " es un tiempo invalido";
        } else {
            sumHoras = hora1 / 100 + hora2 / 100;
            minutos = hora1 % 100 + hora2 % 100;
            if (minutos >= 60){
                sumHoras += minutos / 60;
                minutos %= 60;
            }
            sumHoras = sumHoras * 100 + minutos;
            if (sumHoras >= 2400 || sumHoras % 100 >= 60) {
                cout << "La suma de los tiempos es invalida." << endl;
            } else {
                cout << "La hora es: " << sumHoras << endl;
            }
        }

    }
}

//Problema #5 Crear patron

void Problema5() {
    int numero;

    cout << "Por favor, Ingrese un numero impar: "; cin >> numero;

    if (numero % 2 == 0) {
        cout << "El numero no es impar." << endl;
    }
    else {
        for (int i = 1; i <= numero; i++){
            for (int j = 1; j < numero - i; j++){
                cout << ' ';
                j++;
            }
            for (int l = 0; l < 2 * i - 1; l++){
                cout << "*";
                l++;
            }
            cout<<endl;
            i++;
        }
        for (int i = numero - 1; i >= 1; i--){
            for (int j = 0; j < numero - i; j++){
                cout << ' ';
                j++;
            }
            for (int k = 0; k < 2 * i - 2; k++) {
                cout << '*';
                k++;
            }
            cout << endl;
            i--;
        }
    }

}

//Problema #6 Calcular valor aproximado de euler

void Problema6() {
    int numero;
    float euler = 0.0;

    cout << "Por favor, Ingresa el numero de elementos a usar en la aproximacion: "; cin >> numero;

    for (int i = 0; i < numero; i++) {
        euler += 1.0 / Factorial(i);
    }

    cout << "e es aproximadamente: " << euler << endl;
}

//Problema #7 serie de fibonacci

void Problema7() {
    int a = 1, b = 1, c = 0, suma = 0, numero;
    cout << "Por favor, Ingrese el numero limite: "; cin >> numero;
    while (c < numero) {
        c = a + b;
        a = b;
        b = c;
        if (c % 2 == 0 && c < numero)
            suma += c;
    }

    cout << "El resultado de la suma es: " << suma << endl;
}

//Practica #8 Suma de multiplos

void Problema8() {
    int a, b, c, sumaM = 0;

    cout << "Por favor, ingrese el primer numero: ";
    cin >> a;
    cout << "Por favor, ingrese el segundo numero: ";
    cin >> b;
    cout << "Por favor, ingrese el tercer numero para el limite: ";
    cin >> c;

    int i = a, l = 1;

    while (i < c) {
        cout << "m1" << l << " + ";
        sumaM += i;
        i += a;
        l++;
    }

    i = b;
    l = 1;

    while (i < c) {
        if (i % a != 0) {
            cout << "m2" << l << " + ";
            sumaM += i;
            l++;
        }
        i += b;
    }

    cout << "\b\b\b = " << sumaM << endl;
}

//Problema #9 Potecia de un numero

void Problema9() {
    int suma = 0, digito, potencia, numero;

    cout << "Por favor, ingrese un numero: "; cin >> numero;

    while (numero > 0) {
        digito = numero % 10;
        potencia = 1;
        for (int i = 0; i < digito; i++) {
            potencia *= digito;
        }
        suma += potencia;
        numero /= 10;
    }
    cout << "El resultado de la suma es: " << suma << endl;
}

//Problema #10 Hallar numero primo

void Problema10() {
    int numero, B = 2, cantidad = 0;
    cout << "Por favor, ingrese un numero: "; cin >> numero;

    while (true) {
        if (esPrimo(B)) {
            cantidad++;
            if (cantidad == numero) {
                cout << "El primo numero " << numero << " es: " << B << endl;
                break;
            }
        }
        B++;
    }
}

//Problema #11 Calcular minimo comun multiplo entre dos numeros

void Problema11() {
    int n;

    cout << "Ingrese un numero: "; cin >> n;

    int resultado = 1;

    for (int i = 2; i <= n; i++) {
        resultado = MCM(resultado, i);
    }

    cout << "El minimo comun multiplo es: " << resultado << endl;
}

//Problema #12 mayor factor primo

void Problema12() {
    int max_primo = 0, numero, numero_original;

    cout << "Por favor, ingrese un numero: "; cin >> numero_original;
    numero = numero_original;
    while (numero % 2 == 0) {
        max_primo = 2;
        numero /= 2;
    }
    for (int i = 3; i * i <= numero; i += 2) {
        if (esPrimo(i)) {
            while (numero % i == 0) {
                max_primo = i;
                numero /= i;
            }
        }
    }
    if (numero > 2) {
        max_primo = numero;
    }

    cout << "El mayor factor primo de " << numero_original << " es: " << max_primo << endl;
}

//Problema #13 suma numeros primos

void Problema13() {
    int numero, A, suma = 0;
    A = 2;
    cout << "Por favor, ingrese un numero: "; cin >> numero;
    while (A < numero) {
        if (esPrimo(A)) {
            suma += A;
        }
        A++;
    }
    cout << "El resultado de la suma es: " << suma << endl;
}

//Problema #14 numero palindromo

void Problema14() {
    int palindromoMaximo = 0, limite;
    int numero1 = 0, numero2 = 0;

    cout << "Por favor, ingrese el numero limite de 3 digitos para hallar el maximo palindromo: "; cin >> limite;

    for (int i = 100; i < limite; i++) {
        for (int j = 100; j < limite; j++) {
            int producto = i * j;
            if (esPalindromo(producto) && producto > palindromoMaximo) {
                palindromoMaximo = producto;
                numero1 = i;
                numero2 = j;
            }
        }
    }

    cout << numero1 << " * " << numero2 << " = " << palindromoMaximo << endl;
}

//Problema #15 suma diagonal

void Problema15() {
    int B;
    int suma = 0;
    int i = 1;
    int k = 2;
    int num = 3;

    cout << "Por favor, ingrese el tamano de la espiral: "; cin >> B;

    while (i <= B * B) {
        suma += i;
        i += k;

        if (i > num * num) {
            i += 2;
            num += 2;
            k += 2;
        }
    }
    cout << "En una espiral de " << B << " * " << B << " la suma es: " << suma << endl;
}

//Problema #16 serie de collatz

void Problema16() {
    int k;

    cout << "Por favor, Ingrese el numero K de la serie: "; cin >> k;

    encontrarSerieCollatz(k);
}

//Problema #17 numero triangular

void Problema17() {
    int k, numT = 0, n = 1, divisores = 0;

    cout << "Por favor, ingrese el numero K: "; cin >> k;
    while (true) {
        numT = numeroTriangular(n);
        divisores = contarDivisores(numT);
        if (divisores > k) {
            cout << "El numero k con mas de " << k << " divisores es: " << numT << endl;
            break;
        }
        n++;
    }
}


/* Funciones Extras */

// calcular factorial
int Factorial(int numero) {
    int factorial = 1;
    for (int i = 1; i < numero; i++) {
        factorial = factorial * (i + 1);
        if (i + 1 == numero)
            i++;
    }

    return factorial;
}

// Validar numero primo
bool esPrimo(int num) {
    if (num <= 1)
        return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

//calcular el maximo comun divisor
int MCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

//calcular el minimo comun multiplo
int MCM(int a, int b) {
    return a * b / MCD(a, b);
}

//Verificar si es palindromo
bool esPalindromo(int numero) {
    int numOriginal = numero, numInvertido = 0;

    while (numero > 0) {
        numInvertido = numInvertido * 10 + (numero % 10);
        numero /= 10;
    }

    return numOriginal == numInvertido;
}

//Contar terminos de la serie de collatz
int TerminosCollatz(int n) {
    int terminos = 1;
    while (n != 1) {
        if (n % 2 == 0)
            n /= 2;
        else
            n = 3 * n + 1;

        terminos++;
    }
    return terminos;
}

//Mostrar la serie de collatz
void Serie(int n) {
    while (n != 1) {
        cout << n << ' ';
        if (n % 2 == 0)
            n /= 2;
        else
            n = 3 * n + 1;
    }
    cout << " 1." << endl;
}

//Encontrar la serie mas larga de collatz
void encontrarSerieCollatz(int k) {
    int longitud_max = 0, semilla_max, longitud_actual;

    for (int j = 1; j < k; j++) {
        longitud_actual = TerminosCollatz(j);
        if (longitud_actual > longitud_max) {
            longitud_max = longitud_actual;
            semilla_max = j;
        }
    }

    cout << "La serie mas larga es con la semilla: " << semilla_max << " teniendo " << longitud_max << " terminos.";
    cout << endl;
    cout << "La serie es: ";
    Serie(semilla_max);
}

//calcular el numero triangular
int numeroTriangular(int n) {
    return n * (n + 1) / 2;
}

//contar divisores del numero triangular
int contarDivisores(int num) {
    int contador = 0;
    for (int i = 1; i * i <= num; i++) {
        if (num % i == 0) {
            if (i * i == num) {
                contador += 1;
            } else {
                contador += 2;
            }
        }
    }
    return contador;
}
