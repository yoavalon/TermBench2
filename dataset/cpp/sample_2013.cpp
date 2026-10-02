#include <iostream>

class LedgerNode {
public:
    float value;
    LedgerNode* next;

    LedgerNode(float value) : value(value), next(nullptr) {}
};

class Blockchain {
public:
    LedgerNode* head;
    LedgerNode* tail;

    Blockchain() : head(nullptr), tail(nullptr) {}

    void add_node(float value) {
        LedgerNode* new_node = new LedgerNode(value);
        if (!head) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    bool consensus_check() {
        LedgerNode* current = head;
        while (current) {
            if (!validate_node(current)) {
                return false;
            }
            current = current->next;
        }
        return true;
    }

    bool validate_node(LedgerNode* node) {
        return node->value > 0.0;
    }
};

void analyze_blockchain(Blockchain blockchain) {
    if (blockchain.consensus_check()) {
        std::cout << "Consensus achieved." << std::endl;
    } else {
        std::cout << "Consensus failed." << std::endl;
    }
}

int main() {
    Blockchain blockchain;
    for (int i = 0; i < 10; ++i) {
        blockchain.add_node(static_cast<float>(i + 1));
    }
    analyze_blockchain(blockchain);
    return 0;
}