#include <iostream>
#include <cstdlib>
#include <ctime>

class SupplyChainNode {
public:
    double value;
    SupplyChainNode* next;

    SupplyChainNode(double val) : value(val), next(nullptr) {}
};

class SupplyChain {
public:
    SupplyChainNode* head;

    SupplyChain() : head(nullptr) {}

    void append(double value) {
        if (!head) {
            head = new SupplyChainNode(value);
        } else {
            SupplyChainNode* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = new SupplyChainNode(value);
        }
    }

    void optimize() {
        SupplyChainNode* current = head;
        while (current) {
            current->value *= 1.05;
            current = current->next;
        }
    }

    void display() {
        SupplyChainNode* current = head;
        while (current) {
            std::cout << current->value << std::endl;
            current = current->next;
        }
    }
};

class LogisticsOptimizer {
public:
    SupplyChain supply_chain;

    LogisticsOptimizer() {}

    void initialize_supply_chain(int size) {
        for (int i = 0; i < size; ++i) {
            supply_chain.append(rand() % 901 + 100);
        }
    }

    void run_optimization() {
        while (true) {
            supply_chain.optimize();
            supply_chain.display();
        }
    }
};

int main() {
    srand(time(0));
    LogisticsOptimizer optimizer;
    optimizer.initialize_supply_chain(10);
    optimizer.run_optimization();
    return 0;
}