#include <iostream>
using namespace std;

void RetirarDinero(int cantidad);
void Patron(int cantidad);
int Factorial(int numero);
int Fibonacci(int numero);
void MultiploComun(int A, int B, int C);
void PotenciaDeUnNumero(int numero);
bool esPrimo(int num);
int MCD(int A, int B);
int CalcularMCM(int A, int B);
void EsPalindromo(int A, int B);

int main()
{
    short int opcion = 1, cantidad, mes, dia, hora1, hora2, numero, A, B, resultado = 1;
    float E = 1.0;

    cout << "*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *" << endl;
    cout << "*  Bienvenido a esta practica #1 del laboratorio.  *" << endl;
    cout << "*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *" << endl;
    cout << "\nA continuacion vera los tipos de problemas a resolver." << endl;

    while (opcion != 0) {
        cout << "\nIngresa una de las siguientes opciones." << endl;
        cout << endl;
        cout << "1. Retirar dinero." << endl;
        cout << "2. Validar fecha." << endl;
        cout << "3. Calcular hora." << endl;
        cout << "4. Crear patron." << endl;
        cout << "5. Hallar un valor aproximado de euler." << endl;
        cout << "6. Hallar la suma de los numeros par de La secuencia de Fibonacci hasta un numero (n)." << endl;
        cout << "7. Hallar la suma de los multiplos de dos numeros hasta un limite (n)." << endl;
        cout << "8. Hallar la suma de cada digito de un numero elevado a si mismo como potencia." << endl;
        cout << "9. Calcular el enesimo numero primo." << endl;
        cout << "10. Calcular el minimo comun multiplo que hay desde 1 hasta un N numero ingresado." << endl;
        cout << "13. Calcular un numero palindromo de la multiplicacion de dos numeros." << endl;
        cout << "0. Salir." << endl;
        cout << "Ingresa la opcion aca: "; cin >> opcion;
        cout << endl;
        cout << "Cargando la opcion " << opcion << "..." << endl;

        switch (opcion) {
        case 1:
            cout << "Ingrese la cantidad a retirar: "; cin >> cantidad;
            RetirarDinero(cantidad);
            break;
        case 2:
            cout << "Ingresa un mes del año: "; cin >> mes;
            if (mes > 12)
                cout << mes << " es un mes invalido" << endl;
            else
            {
                cout << "Ingrese un dia del mes " << mes << " : "; cin >> dia;
                if (dia > 31)
                    cout << dia << " es un dia invalido." << endl;
                else if (dia > 29 && mes == 2)
                    cout << dia << "/" << mes << " es una fecha invalida." << endl;
                else if (mes == 2 && dia == 29)
                    cout << dia << "/" << mes << " es valida en bisiesto." << endl;
                else if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
                    cout << dia << "/" << mes << " es una fecha valida." << endl;
                else
                    cout << dia << "/" << mes << " es una fecha valida." << endl;
            }
            break;
        case 3:
            cout << "Ingrese la primer hora: "; cin >> hora1;
            if (hora1 >= 2400 || hora1 % 100 >= 60)
                cout << hora1 << " es un tiempo invalido." << endl;
            else {
                cout << "Ingrese la segunda hora: "; cin >> hora2;
                if (hora2 >= 2400 || hora2 % 100 >= 60)
                    cout << hora2 << " es un tiempo invalido." << endl;
                else {
                    int horas = hora1 / 100 + hora2 / 100;
                    int minutos = hora1 % 100 + hora2 % 100;
                    if (minutos >= 60) {
                        horas += minutos / 60;
                        minutos %= 60;
                    }
                    int resultado = horas * 100 + minutos;
                    if (resultado >= 2400 || resultado % 100 >= 60)
                        cout << "La suma de los tiempos es invalida." << endl;
                    else
                        cout << "La hora es: " << resultado << endl;
                }
            }
            break;
        case 4:
            cout << "Ingrese la longitud del patron (debe ser impar): "; cin >> cantidad;
            Patron(cantidad);
            cout << endl;
            break;
        case 5:
            cout << "Ingrese el numero de elementos deseados para dar una aproximacion de euler: ";
            cin >> numero;
            for (int i = 1; i <= numero; i++){
                E += 1.0 / Factorial(i);
            }
            cout << "El valor aproximado de euler es: " << E << endl;
            break;
        case 6:
            cout << "Ingrese un numero limite para hallar dicha suma en la secuencia: ";
            cin >> numero;
            cout << Fibonacci(numero);
            break;
        case 7:
            cout << "Ingrese el primer numero: "; cin >> A;
            cout << "Ingrese el segundo numero: "; cin >> B;
            cout << "Ingrese el numero hasta el cual desea que se sumen los multiplos: "; cin >> numero;
            MultiploComun(A, B, numero);
            break;
        case 8:
            cout << "Ingrese el numero para hallar dicha suma: "; cin >> numero;
            PotenciaDeUnNumero(numero);
            break;
        case 9:
            cout << "Ingrese el numero n primo que desea hallar: "; cin >> A;
            cantidad = 0;
            B = 2;
            while (true) {
                if (esPrimo(B)) {
                    cantidad++;
                    if (cantidad == A) {
                        cout << "El primo numero " << A << " es: " << B << endl;
                        break;
                    }
                }
                B++;
            }
            break;
        case 10:
            cout << "Ingrese el numero deseado para calcular los MCM desde el 1 hasta dicho numero: ";
            cin >> numero;
            for (int i = 1; i <= numero; i++)
                resultado = CalcularMCM(resultado, i);
            cout << "El minimo comun multiplo es: " << resultado;
            break;
        case 11:
            cout << "Hola mundo";
            break;
        case 13:
            cout << "Ingrese el primer numero para calcular: "; cin >> A;
            cout << "Ingrese el segundo numero para calcular: "; cin >> B;
            EsPalindromo(A, B);
            break;
        case 0:
            cout << "Gracias por usar el programa de la practica 1, tenga un feliz dia" << endl;
            cout << endl;
            break;
        default:
            cout << "Opcion no valida."  << endl;
            break;
        }
    }
    return 0;
}

void RetirarDinero(int cantidad) {
    int billetes[] = {50000, 20000, 10000, 5000, 2000, 1000};
    int monedas[] = {500, 200, 100, 50};

    int billetesUsados[6] = {0, 0, 0, 0, 0, 0};
    int monedasUsadas[4] = {0, 0, 0, 0};
    int residuo = cantidad;

    for (int i = 0; i < 6; i++){
        billetesUsados[i] = residuo / billetes[i];
        residuo %= billetes[i];
    }

    for (int i = 0; i < 4; i++){
        monedasUsadas[i] = residuo / monedas[i];
        residuo %= monedas[i];
    }

    cout << "50.000$ : " << billetesUsados[0] << endl;
    cout << "20.000$ : " << billetesUsados[1] << endl;
    cout << "10.000$ : " << billetesUsados[2] << endl;
    cout << "5.000$ : " << billetesUsados[3] << endl;
    cout << "2.000$ : " << billetesUsados[4] << endl;
    cout << "1.000$ : " << billetesUsados[5] << endl;
    cout << "500$ : " << monedasUsadas[0] << endl;
    cout << "200$ : " << monedasUsadas[1] << endl;
    cout << "100$ : " << monedasUsadas[2] << endl;
    cout << "50$ : " << monedasUsadas[3] << endl;

    if (residuo > 0)
        cout << "Faltante: " << residuo << endl;
}

void Patron(int cantidad) {
    if (cantidad % 2 == 0) {
        cout << "El numero no es impar." << endl;
    }
    else {
        for (int i = 1; i <= cantidad; i++){
            for (int j = 1; j < cantidad - i; j++){
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
        for (int i = cantidad - 1; i >= 1; i--){
            for (int j = 0; j < cantidad - i; j++){
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

int Factorial(int numero){
    int resultado = 1;
    if (numero == 0)
        resultado = resultado;
    else {
        for (int i = 1; i <= numero; i++)
            resultado *= i;
    }
    return resultado;
}

int Fibonacci(int numero) {
    int a = 1, b = 1, c = 0, suma = 0;
    while (c < numero) {
        c = a + b;
        a = b;
        b = c;
        if (c % 2 == 0 && c < numero)
            suma += c;
    }
    return suma;
}

void MultiploComun(int A, int B, int C) {
    short int suma = 0, aux1, aux2, aux3[C], i = 0, aux4, K = 1, L = 1;
    aux1 = A;
    aux2 = B;
    while (A < C){
        suma += A;
        cout << "m" << K << L << " + ";
        aux3[i] = A;
        A += aux1;
        i++;
        K += 1;
    }
    aux4 = i;
    K = 1;
    while (B < C){
        bool esComun = false;
        for (i = 0; i < aux4; i++)
            if (B == aux3[i]) {
                esComun = true;
                break;
            }
        if (!esComun) {
            suma += B;
            cout << "m" << K << L << " + ";
        }
        B += aux2;
        L += 1;
    }
    cout << "\b\b = " << suma << endl;;
}

void PotenciaDeUnNumero(int numero) {
    int suma = 0, digito, potencia;
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

bool esPrimo(int num) {
    if (num <= 1)
        return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int MCD(int A, int B) {
    int C;
    while (B != 0) {
        C = B;
        B = A % B;
        A = C;
    }
    return A;
}

int CalcularMCM(int A, int B) {
    return A * B / MCD(A, B);
}

void EsPalindromo(int A, int B) {
    int aux = A * B;
    int auxInicial = aux;
    int auxFinal = 0;

    while (aux != 0) {
        auxFinal = auxFinal * 10 + aux % 10;
        aux /= 10;
    }

    cout << A << " * " << B << " = " << A * B << endl;
    if (auxInicial == auxFinal) {
        cout << "Por lo tanto es palindromo." << endl;
    } else {
        cout << "Por lo tanto no es palindromo." << endl;
    }
}
