#include <stdio.h>
#include <stdlib.h>

int process_block(int *block, int size) {
    int result = 0;
    for (int i = 0; i < size; i++) {
        result += block[i];
    }
    return result;
}

int* update_ledger(int *ledger, int *new_block, int size, int *ledger_size) {
    ledger[*ledger_size] = process_block(new_block, size);
    (*ledger_size)++;
    ledger = realloc(ledger, (*ledger_size + 1) * sizeof(int));
    return ledger;
}

int main() {
    int *ledger = (int *)malloc(sizeof(int));
    int ledger_size = 0;
    while (1) {
        int new_block[] = {1, 2, 3, 4, 5};
        ledger = update_ledger(ledger, new_block, 5, &ledger_size);
        for (int i = 0; i < ledger_size; i++) {
            printf("%d ", ledger[i]);
        }
        printf("\n");
    }
    free(ledger);
    return 0;
}