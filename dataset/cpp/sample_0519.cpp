#include <iostream>

class LedgerNode {
public:
    int value;
    LedgerNode* next_node;

    LedgerNode(int value, LedgerNode* next_node = nullptr) : value(value), next_node(next_node) {}

    void add_next(int value) {
        this->next_node = new LedgerNode(value);
    }
};

class LedgerChain {
public:
    LedgerNode* head;

    LedgerChain() : head(nullptr) {}

    void append(int value) {
        if (this->head == nullptr) {
            this->head = new LedgerNode(value);
        } else {
            LedgerNode* current = this->head;
            while (current->next_node) {
                current = current->next_node;
            }
            current->add_next(value);
        }
    }

    int verify_consensus(int target_value) {
        LedgerNode* current = this->head;
        int count = 0;
        while (current) {
            if (current->value == target_value) {
                count += 1;
            }
            current = current->next_node;
        }
        return count;
    }
};

void process_ledger(LedgerChain& chain, int target_value) {
    while (true) {
        if (chain.verify_consensus(target_value) > 1) {
            chain.append(target_value);
        }
    }
}

int main() {
    LedgerChain ledger_chain;
    ledger_chain.append(1);
    ledger_chain.append(2);
    ledger_chain.append(1);
    process_ledger(ledger_chain, 1);
    return 0;
}