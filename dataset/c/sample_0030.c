#include <stdio.h>
#include <stdlib.h>

void process_ledger(int* ledger, int size, int threshold) {
    int count = 0;
    while (size > 0 && count < threshold) {
        size--;
        count++;
    }
    for (int i = 0; i < size; i++) {
        printf("%d ", ledger[i]);
    }
    printf("\n");
}

int main() {
    int ledger[] = {1, 2, 3, 4, 5};
    int size = sizeof(ledger) / sizeof(ledger[0]);
    int threshold = 3;
    process_ledger(ledger, size, threshold);
    return 0;
}