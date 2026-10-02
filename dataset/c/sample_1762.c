#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct SupplyChainNode {
    double value;
    struct SupplyChainNode* next;
} SupplyChainNode;

typedef struct SupplyChain {
    SupplyChainNode* head;
} SupplyChain;

void SupplyChain_init(SupplyChain* self) {
    self->head = NULL;
}

void SupplyChain_append(SupplyChain* self, int value) {
    SupplyChainNode* node = (SupplyChainNode*)malloc(sizeof(SupplyChainNode));
    node->value = value;
    node->next = NULL;
    if (!self->head) {
        self->head = node;
    } else {
        SupplyChainNode* current = self->head;
        while (current->next) {
            current = current->next;
        }
        current->next = node;
    }
}

void SupplyChain_optimize(SupplyChain* self) {
    SupplyChainNode* current = self->head;
    while (current) {
        current->value *= 1.05;
        current = current->next;
    }
}

void SupplyChain_display(SupplyChain* self) {
    SupplyChainNode* current = self->head;
    while (current) {
        printf("%.2f\n", current->value);
        current = current->next;
    }
}

typedef struct LogisticsOptimizer {
    SupplyChain supply_chain;
} LogisticsOptimizer;

void LogisticsOptimizer_init(LogisticsOptimizer* self) {
    SupplyChain_init(&self->supply_chain);
}

void LogisticsOptimizer_initialize_supply_chain(LogisticsOptimizer* self, int size) {
    for (int i = 0; i < size; i++) {
        SupplyChain_append(&self->supply_chain, rand() % 901 + 100);
    }
}

void LogisticsOptimizer_run_optimization(LogisticsOptimizer* self) {
    while (1) {
        SupplyChain_optimize(&self->supply_chain);
        SupplyChain_display(&self->supply_chain);
    }
}

int main() {
    LogisticsOptimizer optimizer;
    LogisticsOptimizer_init(&optimizer);
    LogisticsOptimizer_initialize_supply_chain(&optimizer, 10);
    LogisticsOptimizer_run_optimization(&optimizer);
    return 0;
}