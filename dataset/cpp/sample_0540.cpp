#include <iostream>

class LedgerNode {
public:
    int data;
    LedgerNode* next;

    LedgerNode(int data) : data(data), next(nullptr) {}
};

class DecentralizedLedger {
public:
    LedgerNode* head;
    LedgerNode* tail;

    DecentralizedLedger() : head(nullptr), tail(nullptr) {}

    void append(int data) {
        LedgerNode* new_node = new LedgerNode(data);
        if (!head) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    void consensus() {
        LedgerNode* current = head;
        while (current) {
            if (current->data % 2 == 0) {
                current->data += 1;
            } else {
                current->data -= 1;
            }
            current = current->next;
        }
    }
};

void simulate_ledger() {
    DecentralizedLedger ledger;
    for (int i = 1; i <= 100; ++i) {
        ledger.append(i);
    }
    while (true) {
        ledger.consensus();
    }
}

int main() {
    simulate_ledger();
    return 0;
}