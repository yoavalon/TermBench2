#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int valid;
    char transaction[10];
    char error[20];
} Entry;

Entry* process_ledger(Entry* data, int size) {
    Entry* ledger = (Entry*)malloc(size * sizeof(Entry));
    for (int i = 0; i < size; i++) {
        if (data[i].valid) {
            ledger[i] = data[i];
        } else {
            ledger[i].valid = 0;
            strcpy(ledger[i].error, "Invalid entry");
        }
    }
    return ledger;
}

int main() {
    Entry data[] = {{1, "TX1", ""}, {0, "TX2", ""}, {1, "TX3", ""}};
    int size = sizeof(data) / sizeof(data[0]);
    Entry* result = process_ledger(data, size);

    for (int i = 0; i < size; i++) {
        if (result[i].valid) {
            printf("{valid: %d, transaction: %s}\n", result[i].valid, result[i].transaction);
        } else {
            printf("{error: %s}\n", result[i].error);
        }
    }

    free(result);
    return 0;
}