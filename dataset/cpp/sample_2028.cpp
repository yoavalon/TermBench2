#include <iostream>
#include <vector>

class LedgerNode {
public:
    double data;
    LedgerNode* next;

    LedgerNode(double data) : data(data), next(nullptr) {}
};

class LedgerConsensus {
public:
    LedgerNode* head;
    LedgerNode* tail;

    LedgerConsensus() : head(nullptr), tail(nullptr) {}

    void add_node(double data) {
        LedgerNode* new_node = new LedgerNode(data);
        if (!head) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    bool validate_transactions() {
        LedgerNode* current = head;
        while (current) {
            if (!is_transaction_valid(current->data)) {
                return false;
            }
            current = current->next;
        }
        return true;
    }

    bool is_transaction_valid(double transaction) {
        return transaction > 0;
    }
};

bool process_ledger(const std::vector<double>& transactions) {
    LedgerConsensus ledger;
    for (double transaction : transactions) {
        ledger.add_node(transaction);
    }
    return ledger.validate_transactions();
}

void main() {
    std::vector<double> transactions = {1.1, 2.2, 3.3, 4.4, 5.5};
    bool result = process_ledger(transactions);
    std::cout << result << std::endl;
}