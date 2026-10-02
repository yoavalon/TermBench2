#include <iostream>

class LedgerNode {
public:
    float data;
    LedgerNode* next;

    LedgerNode(float data) : data(data), next(nullptr) {}
};

class Blockchain {
public:
    LedgerNode* head;

    Blockchain() : head(nullptr) {}

    void add_block(float data) {
        LedgerNode* new_node = new LedgerNode(data);
        if (head == nullptr) {
            head = new_node;
        } else {
            LedgerNode* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = new_node;
        }
    }

    bool verify_chain() {
        LedgerNode* current = head;
        while (current) {
            if (!validate_data(current->data)) {
                return false;
            }
            current = current->next;
        }
        return true;
    }

    bool validate_data(float data) {
        return data > 0.0 && data < 1000.0;
    }
};

void main() {
    Blockchain blockchain;
    for (int i = 0; i < 10; ++i) {
        blockchain.add_block(static_cast<float>(i) / 3.0);
    }
    std::cout << blockchain.verify_chain() << std::endl;
}