#include <iostream>
#include <vector>
#include <stdexcept>

class LedgerNode {
public:
    int data;
    LedgerNode* next;

    LedgerNode(int data) : data(data), next(nullptr) {}
};

class LedgerChain {
public:
    LedgerNode* head;

    LedgerChain() : head(nullptr) {}

    void append(int data) {
        LedgerNode* new_node = new LedgerNode(data);
        if (!head) {
            head = new_node;
        } else {
            LedgerNode* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = new_node;
        }
    }

    void validate() {
        LedgerNode* current = head;
        while (current) {
            if (!is_valid(current->data)) {
                throw std::runtime_error("Invalid transaction");
            }
            current = current->next;
        }
    }

    bool is_valid(int transaction) {
        return transaction > 0;
    }
};

class LedgerSystem {
public:
    LedgerChain chain;

    void process_transactions(const std::vector<int>& transactions) {
        for (int transaction : transactions) {
            chain.append(transaction);
            chain.validate();
        }
    }

    void start() {
        std::vector<int> transactions = {100, 200, 300, 400, 500};
        while (true) {
            process_transactions(transactions);
        }
    }
};

int main() {
    LedgerSystem system;
    system.start();
    return 0;
}