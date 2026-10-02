#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LedgerNode {
    int data;
    struct LedgerNode* next_node;
} LedgerNode;

typedef struct LedgerChain {
    LedgerNode* head;
} LedgerChain;

LedgerNode* create_node(int data) {
    LedgerNode* new_node = (LedgerNode*)malloc(sizeof(LedgerNode));
    new_node->data = data;
    new_node->next_node = NULL;
    return new_node;
}

LedgerChain* create_ledger_chain() {
    LedgerChain* ledger = (LedgerChain*)malloc(sizeof(LedgerChain));
    ledger->head = NULL;
    return ledger;
}

void add_data(LedgerChain* ledger, int data) {
    LedgerNode* new_node = create_node(data);
    if (!ledger->head) {
        ledger->head = new_node;
    } else {
        LedgerNode* current = ledger->head;
        while (current->next_node) {
            current = current->next_node;
        }
        current->next_node = new_node;
    }
}

int* consensus_check(LedgerChain* ledger, int* consensus_data) {
    LedgerNode* current = ledger->head;
    int index = 0;
    while (current) {
        consensus_data[index++] = current->data;
        current = current->next_node;
    }
    return consensus_data;
}

int check_majority(int* data_list, int length) {
    int* counter = (int*)calloc(1000, sizeof(int)); // Assuming data values are between 0 and 999
    for (int i = 0; i < length; i++) {
        counter[data_list[i]]++;
    }
    int majority_value = -1;
    int majority_count = 0;
    for (int i = 0; i < 1000; i++) {
        if (counter[i] > length / 2) {
            majority_value = i;
            majority_count = counter[i];
            break;
        }
    }
    free(counter);
    return majority_value;
}

int main() {
    LedgerChain* ledger = create_ledger_chain();
    add_data(ledger, 1);
    add_data(ledger, 2);
    add_data(ledger, 1);
    add_data(ledger, 1);
    add_data(ledger, 3);
    add_data(ledger, 1);
    int consensus_data[1000]; // Assuming a maximum of 1000 entries
    int* result_data = consensus_check(ledger, consensus_data);
    int result = check_majority(result_data, 1000);
    printf("%d\n", result);
    free(ledger);
    return 0;
}