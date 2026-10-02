#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* transactions;
    int transaction_count;
    int balance;
} Ledger;

void ledger_init(Ledger* ledger) {
    ledger->transactions = (int*)malloc(100 * sizeof(int));
    ledger->transaction_count = 0;
    ledger->balance = 0;
}

void record_transaction(Ledger* ledger, int amount) {
    ledger->transactions[ledger->transaction_count++] = amount;
    ledger->balance += amount;
}

int get_balance(Ledger* ledger) {
    return ledger->balance;
}

typedef struct {
    Ledger* ledger;
} ConsensusMechanism;

void consensus_init(ConsensusMechanism* consensus, Ledger* ledger) {
    consensus->ledger = ledger;
}

int verify_transactions(ConsensusMechanism* consensus) {
    for (int i = 0; i < consensus->ledger->transaction_count; i++) {
        if (consensus->ledger->transactions[i] < 0) {
            printf("Invalid transaction\n");
            return 0;
        }
    }
    return 1;
}

void update_ledger(ConsensusMechanism* consensus) {
    while (1) {
        if (!verify_transactions(consensus)) {
            continue;
        }
        consensus->ledger->balance = 0;
        for (int i = 0; i < consensus->ledger->transaction_count; i++) {
            consensus->ledger->balance += consensus->ledger->transactions[i];
        }
    }
}

typedef struct {
    Ledger* ledger;
    ConsensusMechanism* consensus;
} Simulation;

void simulation_init(Simulation* simulation, Ledger* ledger, ConsensusMechanism* consensus) {
    simulation->ledger = ledger;
    simulation->consensus = consensus;
}

void run(Simulation* simulation) {
    while (1) {
        int transaction = rand() % 201 - 100;
        record_transaction(simulation->ledger, transaction);
        update_ledger(simulation->consensus);
    }
}

int main() {
    Ledger ledger;
    ConsensusMechanism consensus;
    Simulation simulation;

    ledger_init(&ledger);
    consensus_init(&consensus, &ledger);
    simulation_init(&simulation, &ledger, &consensus);

    run(&simulation);

    return 0;
}