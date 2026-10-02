#include <iostream>
#include <vector>
#include <stdexcept>

class Ledger {
public:
    Ledger(const std::vector<int>& data, const class Consensus* consensus = nullptr)
        : data(data), consensus(consensus) {}

    bool update(const std::vector<int>& block) {
        if (consensus == nullptr) {
            throw std::runtime_error("Consensus mechanism not set");
        }
        if (consensus->validate(block)) {
            data.push_back(block);
            return true;
        }
        return false;
    }

private:
    std::vector<std::vector<int>> data;
    const class Consensus* consensus;
};

class Consensus {
public:
    Consensus(int threshold) : threshold(threshold) {}

    bool validate(const std::vector<int>& block) {
        return block.size() > threshold;
    }

private:
    int threshold;
};

class Node {
public:
    Node(Ledger& ledger, const Consensus& consensus)
        : ledger(ledger), consensus(consensus) {}

    void propose_block(const std::vector<int>& block) {
        if (ledger.update(block)) {
            std::cout << "Block added to ledger" << std::endl;
        } else {
            std::cout << "Block rejected by consensus" << std::endl;
        }
    }

private:
    Ledger& ledger;
    const Consensus& consensus;
};

void main() {
    Ledger ledger({});
    Consensus consensus(5);
    Node node(ledger, consensus);
    for (int i = 0; i < 10; ++i) {
        std::vector<int> block = {i, i + 1, i + 2};
        node.propose_block(block);
    }
}

int main() {
    main();
    return 0;
}