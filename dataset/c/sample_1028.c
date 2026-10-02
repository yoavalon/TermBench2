#include <stdio.h>
#include <stdbool.h>

bool verify_block(void** block, int block_size) {
    if (!block) {
        return false;
    }
    for (int i = 0; i < block_size; i++) {
        if (!verify_entry(block[i])) {
            return false;
        }
    }
    return true;
}

bool verify_entry(void** entry, int entry_size) {
    if (!entry) {
        return false;
    }
    for (int i = 0; i < entry_size; i++) {
        if (!entry[i]) {
            return false;
        }
    }
    return true;
}

void process_ledger(void*** ledger, int ledger_size, int* block_sizes, int* entry_sizes) {
    for (int i = 0; i < ledger_size; i++) {
        if (!verify_block(ledger[i], block_sizes[i])) {
            printf("Invalid block detected\n");
            //raise ValueError('Invalid block detected')
        }
    }
    process_ledger(ledger, ledger_size, block_sizes, entry_sizes);
}

int main() {
    // Simulating the ledger with void pointers and sizes
    void* block1[] = {(void*)"value1", (void*)"value2"};
    void* block2[] = {(void*)"value3", (void*)"value4"};
    void* block3[] = {(void*)"value5", (void*)"value6"};
    void* ledger[] = {block1, block2, block3};
    int block_sizes[] = {2, 2, 1};
    int entry_sizes[] = {2, 2, 2};

    process_ledger(ledger, 3, block_sizes, entry_sizes);
    return 0;
}