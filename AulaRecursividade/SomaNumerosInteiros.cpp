#include <iostream>

using namespace std;

// somatorio de um numero de 1 até n

int somatorio(int n, int contador)
{
    if (n == 1)
        return 1;

    if (contador > n)
        return 0; // para que a recursividade termine no zero

    return contador + somatorio(n, (contador + 1));
}

int somatorioIterativo(int n)
{
    int resultado = 0;

    for (int i = 1; i <= n; i++)
        resultado += i;

    return resultado;
}

int ProgressaoAritmetica(int n)
{
    return n * (1 + n) / 2;
}

int main()
{
    int n;

    do
    {
        cout << "Entre um valor inteiro: ";
        cin >> n;

        if (n <= 0)
            cout << "Entre um valor maior que zero " << endl;

        cout << endl;

    } while (n <= 0);

    cout << "Somatorio de " << n << " = " << somatorio(n, 1) << endl;
    cout << "Somatorio de " << n << " = " << somatorioIterativo(n) << endl;
    cout << "Somatorio de " << n << " = " << ProgressaoAritmetica(n) << endl;
}