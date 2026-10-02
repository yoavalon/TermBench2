#include <iostream>

class LedgerNode {
public:
    int data;
    LedgerNode* next_node;

    LedgerNode(int data, LedgerNode* next_node = nullptr) : data(data), next_node(next_node) {}
};

class LedgerList {
public:
    LedgerNode* head;

    LedgerList() : head(nullptr) {}

    void append(int data) {
        LedgerNode* new_node = new LedgerNode(data);
        if (!head) {
            head = new_node;
            return;
        }
        LedgerNode* last_node = head;
        while (last_node->next_node) {
            last_node = last_node->next_node;
        }
        last_node->next_node = new_node;
    }

    void consensus(LedgerNode* node, int round_number) {
        if (node == nullptr) {
            return;
        }
        if (round_number % 2 == 0) {
            node->data += 1;
        } else {
            node->data -= 1;
        }
        consensus(node->next_node, round_number + 1);
    }
};

void main() {
    LedgerList ledger;
    for (int i = 0; i < 10; i++) {
        ledger.append(i);
    }
    LedgerNode* node = ledger.head;
    int round_number = 0;
    while (true) {
        ledger.consensus(node, round_number);
        round_number += 1;
    }
}