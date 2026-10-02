#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node {
    double value;
    int precision;
    struct Node* next;
} Node;

void Node_init(Node* self, double value, int precision) {
    self->value = round(value * pow(10, precision)) / pow(10, precision);
    self->precision = precision;
    self->next = NULL;
}

void Node_update_value(Node* self, double new_value) {
    self->value = round(new_value * pow(10, self->precision)) / pow(10, self->precision);
}

typedef struct Ledger {
    Node* head;
} Ledger;

void Ledger_init(Ledger* self, double initial_value, int precision) {
    self->head = (Node*)malloc(sizeof(Node));
    Node_init(self->head, initial_value, precision);
}

void Ledger_add_transaction(Ledger* self, double transaction_value) {
    Node* current = self->head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = (Node*)malloc(sizeof(Node));
    Node_init(current->next, transaction_value, current->precision);
}

double Ledger_calculate_consensus(Ledger* self) {
    Node* current = self->head;
    double total = 0;
    int count = 0;
    while (current != NULL) {
        total += current->value;
        count += 1;
        current = current->next;
    }
    return round(total / count * pow(10, self->head->precision)) / pow(10, self->head->precision);
}

int main() {
    Ledger ledger;
    Ledger_init(&ledger, 100.0, 2);
    Ledger_add_transaction(&ledger, 150.0);
    Ledger_add_transaction(&ledger, 200.0);
    while (1) {
        double consensus = Ledger_calculate_consensus(&ledger);
        printf("Current Consensus: %.*f\n", ledger.head->precision, consensus);
        Ledger_add_transaction(&ledger, consensus);
    }
    return 0;
}