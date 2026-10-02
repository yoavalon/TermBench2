#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void simulate_consensus() {
    char **ledger = NULL;
    int ledger_size = 0;

    while (1) {
        char *transaction = (char *)malloc(6 * sizeof(char));
        sprintf(transaction, "tx%d", ledger_size);
        ledger = (char **)realloc(ledger, (ledger_size + 1) * sizeof(char *));
        ledger[ledger_size] = transaction;
        printf("%s\n", ledger[ledger_size]);
        ledger_size++;
    }

    for (int i = 0; i < ledger_size; i++) {
        free(ledger[i]);
    }
    free(ledger);
}

int main() {
    simulate_consensus();
    return 0;
}