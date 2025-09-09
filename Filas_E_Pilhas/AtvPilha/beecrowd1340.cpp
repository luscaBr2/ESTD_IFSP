#include <iostream>
using namespace std;

/* ---------------- Pilha (array) ---------------- */
int pilha[1000];
int topo = 0;


void inserirPilha(int x) {
    if (topo < 1000) {
        pilha[topo] = x;
        topo++;
    }
}

int removerPilha() {
    if (topo == 0) { 
        return -1; 
    }
    topo--;
    return pilha[topo];
}

/* --------------- Fila (array circular) --------- */
int fila[1000];
int inicio, fim;

void inserirFila(int x) {
    if (fim < 1000) {
        fila[fim] = x;
        fim++;
    }
}

int removerFila() {
    if (fim == 0) { 
        return -1; 
    }
    
    int v = fila[inicio];
    inicio ++;
    return v;
}

/* ----------- Fila de Prioridade (heap máx) ----- */
int filaFP[1000];
int fimFP = 0;

void inserirFP(int x) {
    if (fim < 1000) {
        filaFP[fimFP] = x;
        fimFP++;
    }
}

int removerFP() {
    if (fimFP == 0) { 
        return -1; 
    }
    
    int maior = filaFP[0];
    int maiorId = 0;

    for (int i = 1; i < fimFP; i++)
    {
        if (maior < filaFP[i])
        {
            maior = filaFP[i];
            maiorId = i;
        }
    }

    filaFP[maiorId] = -1;
    return maior;
}

int main() {
    int n;
    while (cin >> n) {
        // reset das três estruturas
        topo = 0;
        inicio = 0; 
        fim = 0;
        fimFP = 0;

        int isPilha = 1, isFila = 1, isFP = 1;

        for (int i = 0; i < n; ++i) {
            int t, x;
            cin >> t >> x;
            if (t == 1) {
                // inserir em todas
                inserirPilha(x);
                inserirFila(x);
                inserirFP(x);
            } else {
                int v;
                
                if (isPilha) {
                    v = removerPilha();
                    if (v == -1 || v != x) 
                        isPilha = 0;
                }

                if (isFila) {
                    v = removerFila();
                    if (v == -1 || v != x) 
                        isFila = 0;
                }

                if (isFP) {
                    v = removerFP();
                    if (v == -1 || v != x) 
                        isFP = 0;
                }
            }
        }

        int cnt = isPilha + isFila + isFP;
        if (cnt == 0)        cout << "impossible\n";
        else if (cnt > 1)    cout << "not sure\n";
        else if (isPilha)   cout << "stack\n";
        else if (isFila)   cout << "queue\n";
        else                 cout << "priority queue\n";
    }

    return 0;
}
