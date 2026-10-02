#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double* transactions;
    int size;
    int precision;
} Ledger;

typedef struct {
    Ledger* ledger;
} ConsensusMechanism;

typedef struct {
    Ledger* ledger;
    ConsensusMechanism* consensus_mechanism;
} Network;

void ledger_init(Ledger* ledger, int precision) {
    ledger->transactions = (double*)malloc(precision * sizeof(double));
    ledger->size = 0;
    ledger->precision = precision;
}

void ledger_add_transaction(Ledger* ledger, double amount) {
    if (ledger->size >= ledger->precision) {
        for (int i = 0; i < ledger->precision - 1; i++) {
            ledger->transactions[i] = ledger->transactions[i + 1];
        }
        ledger->size--;
    }
    ledger->transactions[ledger->size++] = amount;
}

double ledger_get_average_transaction(Ledger* ledger) {
    if (ledger->size == 0) {
        return 0;
    }
    double sum = 0;
    for (int i = 0; i < ledger->size; i++) {
        sum += ledger->transactions[i];
    }
    return sum / ledger->size;
}

void consensus_mechanism_init(ConsensusMechanism* cm, Ledger* ledger) {
    cm->ledger = ledger;
}

void consensus_mechanism_update_ledger(ConsensusMechanism* cm, double new_amount) {
    ledger_add_transaction(cm->ledger, new_amount);
}

int consensus_mechanism_validate_transaction(ConsensusMechanism* cm, double amount) {
    double avg_transaction = ledger_get_average_transaction(cm->ledger);
    return abs(amount - avg_transaction) < cm->ledger->precision;
}

void network_init(Network* network, int precision) {
    network->ledger = (Ledger*)malloc(sizeof(Ledger));
    ledger_init(network->ledger, precision);
    network->consensus_mechanism = (ConsensusMechanism*)malloc(sizeof(ConsensusMechanism));
    consensus_mechanism_init(network->consensus_mechanism, network->ledger);
}

int network_process_transaction(Network* network, double amount) {
    if (consensus_mechanism_validate_transaction(network->consensus_mechanism, amount)) {
        consensus_mechanism_update_ledger(network->consensus_mechanism, amount);
        return 1;
    }
    return 0;
}

void main() {
    Network network;
    network_init(&network, 5);
    double amounts[] = {10.1, 10.2, 10.3, 10.4, 10.5, 10.6, 10.7, 10.8, 10.9, 11.0};
    for (int i = 0; i < 10; i++) {
        if (!network_process_transaction(&network, amounts[i])) {
            printf("Transaction %.1f rejected\n", amounts[i]);
        } else {
            printf("Transaction %.1f accepted\n", amounts[i]);
        }
    }
    free(network.ledger->transactions);
    free(network.ledger);
    free(network.consensus_mechanism);
}