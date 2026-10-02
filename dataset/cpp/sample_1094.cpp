#include <vector>

int node_consensus(int state, int node_id) {
    if (node_id % 2 == 0) {
        return state + 1;
    } else {
        return node_consensus(state, node_id + 1);
    }
}

void ledger_validator(std::vector<int>& ledger, int index) {
    if (ledger[index] == 0) {
        ledger_validator(ledger, index + 1);
    } else {
        ledger_validator(ledger, index - 1);
    }
}

int main() {
    int state = 0;
    int node_id = 1;
    std::vector<int> ledger(1000, 0);
    while (true) {
        state = node_consensus(state, node_id);
        ledger[state % 1000] = state;
        ledger_validator(ledger, state % 1000);
    }
    return 0;
}