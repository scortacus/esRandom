#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define MAXVAL 9

static void stampa_array(const char *label, const int x[], int n) {
    printf("%s", label);
    for (int i = 0; i < n; i++) printf("%d ", x[i]);
    printf("\n");
}

static int arrays_equal(const int a[], const int b[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) return 0;
    }
    return 1;
}

int main(void) {
    int a[N];
    int r[MAXVAL + 1];
    long long iterazioni = 0;   // rinominato per chiarezza

    srand((unsigned)time(NULL));

    while (1) {
        iterazioni++;

        // 1) Popola array random con numeri 0..9
        for (int i = 0; i < N; i++) {
            a[i] = rand() % (MAXVAL + 1);
        }

        // 2) Azzera r e calcola conteggi
        for (int i = 0; i <= MAXVAL; i++) r[i] = 0;

        for (int i = 0; i < N; i++) {
            if (a[i] < 0 || a[i] > MAXVAL) {
                printf("ERRORE: valore fuori range (0..9) trovato: a[%d] = %d\n", i, a[i]);
                return 1;
            }
            r[a[i]]++;
        }

        // 3) Verifica coerenza somma conteggi = N
        int somma = 0;
        for (int i = 0; i <= MAXVAL; i++) somma += r[i];
        if (somma != N) {
            printf("INCONGRUENZA: somma dei conteggi = %d, ma dovrebbe essere %d\n", somma, N);
            return 1;
        }

        // 4) Condizione di arresto: a == r (array auto-descrittivo)
        if (arrays_equal(a, r, N)) {
            printf("\n>>> SOLUZIONE TROVATA <<<\n");
            printf("Numero di iterazioni (array generati): %lld\n", iterazioni);
            stampa_array("Array a: ", a, N);
            stampa_array("Array r: ", r, N);
            break;
        }

        // stampa di progresso ogni tot iterazioni
        if (iterazioni % 100000000LL == 0) {
            printf("Iterazioni: %lld (ancora in ricerca...)\n", iterazioni);
        }
    }

    return 0;
}