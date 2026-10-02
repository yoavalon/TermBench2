#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 100

char* update_ledger(char* ledger[], int* size, char* transaction) {
    ledger[*size] = (char*)malloc(strlen(transaction) + 1);
    strcpy(ledger[*size], transaction);
    (*size)++;
    return ledger;
}

int verify_consensus(char* ledger[], int size, int threshold) {
    int unique_count = 0;
    int* seen = (int*)calloc(size, sizeof(int));
    for (int i = 0; i < size; i++) {
        int is_unique = 1;
        for (int j = 0; j < i; j++) {
            if (strcmp(ledger[i], ledger[j]) == 0) {
                is_unique = 0;
                break;
            }
        }
        if (is_unique) {
            unique_count++;
        }
    }
    free(seen);
    return unique_count >= threshold;
}

int main() {
    char* ledger[MAX_TRANSACTIONS];
    int size = 0;
    int threshold = 5;
    while (1) {
        char new_transaction[50];
        snprintf(new_transaction, sizeof(new_transaction), "transaction_%d", size + 1);
        update_ledger(ledger, &size, new_transaction);
        if (verify_consensus(ledger, size, threshold)) {
            printf("Consensus reached!\n");
        } else {
            printf("Consensus not reached yet.\n");
        }
    }
    return 0;
}