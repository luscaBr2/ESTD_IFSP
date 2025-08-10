// enunciado = https://judge.beecrowd.com/pt/problems/view/2166

#include <iostream>
#include <iomanip>
using namespace std;

long double fracao(int n)
{
    if (n == 0)
        return 0;

    if (n == 1)
        return 2; // o primeiro termo é fixo em 2

    return 2 + 1 / fracao(n - 1);
}

int main()
{
    int n;
    cin >> n; // numero de repetições

    // se n == 0, retorna 1,
    // se não, retorna 1+1/fracao(n)
    long double resultado = (n == 0) ? 1 : 1 + 1 / fracao(n);

    cout << fixed << setprecision(10) << (double)resultado << "\n";
}
