#include <iostream>
#include <cstdlib>
#include <ctime>

constexpr int N = 10;
constexpr int MAXVAL = 9;

static void stampa_array(const char* label, const int x[], int n) {
    std::cout << label;
    for (int i = 0; i < n; i++) std::cout << x[i] << " ";
    std::cout << "\n";
}

static bool arrays_equal(const int a[], const int b[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

int main() {
    int a[N];
    int r[MAXVAL + 1];
    long long iterazioni = 0;

    std::srand(static_cast<unsigned>(std::time(nullptr)));

    while (true) {
        iterazioni++;

        // 1) Popola array random con numeri 0..9
        for (int i = 0; i < N; i++) {
            a[i] = std::rand() % (MAXVAL + 1);
        }

        // 2) Azzera r e calcola conteggi
        for (int i = 0; i <= MAXVAL; i++) r[i] = 0;

        for (int i = 0; i < N; i++) {
            if (a[i] < 0 || a[i] > MAXVAL) {
                std::cerr << "ERRORE: valore fuori range (0..9) trovato: a[" 
                          << i << "] = " << a[i] << "\n";
                return 1;
            }
            r[a[i]]++;
        }

        // 3) Verifica coerenza somma conteggi = N
        int somma = 0;
        for (int i = 0; i <= MAXVAL; i++) somma += r[i];
        if (somma != N) {
            std::cerr << "INCONGRUENZA: somma dei conteggi = " 
                      << somma << ", ma dovrebbe essere " << N << "\n";
            return 1;
        }

        // 4) Condizione di arresto: a == r (array auto-descrittivo)
        if (arrays_equal(a, r, N)) {
            std::cout << "\n>>> SOLUZIONE TROVATA <<<\n";
            std::cout << "Numero di iterazioni (array generati): " 
                      << iterazioni << "\n";
            stampa_array("Array a: ", a, N);
            stampa_array("Array r: ", r, N);
            break;
        }

        // stampa di progresso ogni tot iterazioni
        if (iterazioni % 1'000'000LL == 0) {
            std::cout << "Iterazioni: " << iterazioni 
                      << " (ancora in ricerca...)\n";
        }
    }

    return 0;
}