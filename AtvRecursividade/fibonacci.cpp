#include <iostream>
using namespace std;

int contador = 0;

int fibonacci(int n)
{
    if (n <= 1)
        return n;

    contador += 2;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n;
    cin >> n;

    for (size_t i = 0; i < n; i++)
    {
        int limite;
        cin >> limite;

        contador = 0;
        int resultado = fibonacci(limite);

        cout << "fib(" << limite << ") = " << contador << " calls = " << resultado << endl;
    }

    return 0;
}
