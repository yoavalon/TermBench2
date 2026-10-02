#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

class Ledger {
public:
    std::vector<std::string> data;
    std::unordered_map<int, std::string> state;

    void append_data(const std::string& block) {
        data.push_back(block);
        state[data.size()] = block;
    }

    std::string get_block(int index) {
        auto it = state.find(index);
        if (it != state.end()) {
            return it->second;
        }
        return "";
    }
};

class Consensus {
public:
    Ledger* ledger;

    Consensus(Ledger* ledger) : ledger(ledger) {}

    bool validate_block(const std::string& block) {
        return true;
    }

    bool process_block(const std::string& block) {
        if (validate_block(block)) {
            ledger->append_data(block);
            return true;
        }
        return false;
    }
};

class Node {
public:
    Consensus* consensus;
    int counter = 0;

    Node(Consensus* consensus) : consensus(consensus) {}

    std::string generate_block() {
        std::string block = "Block_" + std::to_string(counter);
        counter += 1;
        return block;
    }

    void run() {
        while (true) {
            std::string block = generate_block();
            consensus->process_block(block);
        }
    }
};

int main() {
    Ledger ledger;
    Consensus consensus(&ledger);
    Node node(&consensus);
    node.run();
    return 0;
}