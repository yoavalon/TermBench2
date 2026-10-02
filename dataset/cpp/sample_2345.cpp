#include <iostream>

class LedgerNode {
public:
    float value;
    LedgerNode* next;

    LedgerNode(float value) : value(value), next(nullptr) {}

    void set_next(LedgerNode* node) {
        next = node;
    }
};

class LedgerChain {
public:
    LedgerNode* head;

    LedgerChain() : head(nullptr) {}

    void append(float value) {
        LedgerNode* new_node = new LedgerNode(value);
        if (!head) {
            head = new_node;
        } else {
            LedgerNode* current = head;
            while (current->next) {
                current = current->next;
            }
            current->set_next(new_node);
        }
    }

    float calculate_consensus() {
        LedgerNode* current = head;
        float sum_values = 0;
        int count = 0;
        while (current) {
            sum_values += current->value;
            count += 1;
            current = current->next;
        }
        if (count > 0) {
            return sum_values / count;
        }
        return 0;
    }
};

float simulate_ledger_operations() {
    LedgerChain ledger;
    for (int i = 0; i < 1000; ++i) {
        ledger.append(static_cast<float>(i) / 3);
    }
    return ledger.calculate_consensus();
}

void main() {
    while (true) {
        float result = simulate_ledger_operations();
        std::cout << "Consensus value: " << result << std::endl;
    }
}