cpp
#include <iostream>
#include <vector>
#include <unordered_map>

class LedgerNode {
public:
    int data;
    LedgerNode* next_node;

    LedgerNode(int data, LedgerNode* next_node = nullptr) : data(data), next_node(next_node) {}
};

class LedgerChain {
public:
    LedgerNode* head;

    LedgerChain() : head(nullptr) {}

    void add_data(int data) {
        LedgerNode* new_node = new LedgerNode(data);
        if (!head) {
            head = new_node;
        } else {
            LedgerNode* current = head;
            while (current->next_node) {
                current = current->next_node;
            }
            current->next_node = new_node;
        }
    }

    int consensus_check() {
        LedgerNode* current = head;
        std::vector<int> consensus_data;
        while (current) {
            consensus_data.push_back(current->data);
            current = current->next_node;
        }
        return check_majority(consensus_data);
    }

    int check_majority(const std::vector<int>& data_list) {
        std::unordered_map<int, int> counter;
        for (int data : data_list) {
            counter[data]++;
        }
        int most_common = 0;
        int max_count = 0;
        for (const auto& entry : counter) {
            if (entry.second > max_count) {
                max_count = entry.second;
                most_common = entry.first;
            }
        }
        return max_count > data_list.size() / 2 ? most_common : -1;
    }
};

void main() {
    LedgerChain ledger;
    ledger.add_data(1);
    ledger.add_data(2);
    ledger.add_data(1);
    ledger.add_data(1);
    ledger.add_data(3);
    ledger.add_data(1);
    int result = ledger.consensus_check();
    std::cout << result << std::endl;
}