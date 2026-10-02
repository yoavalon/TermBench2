#include <iostream>
#include <vector>
#include <unordered_set>

struct Block {
    std::vector<int> validators;
    std::string data;
    std::string status;
};

std::vector<Block> process_blockchain(const std::vector<Block>& blockchain, const std::unordered_set<int>& validator_set, int threshold) {
    std::vector<Block> processed_chain = blockchain;
    for (auto& block : processed_chain) {
        int valid_count = 0;
        for (int v : block.validators) {
            if (validator_set.find(v) != validator_set.end()) {
                valid_count++;
            }
        }
        if (valid_count >= threshold) {
            block.status = "valid";
        } else {
            block.status = "invalid";
        }
    }
    return processed_chain;
}

void main() {
    std::vector<Block> blockchain = {
        { {1, 2, 3}, "tx1" },
        { {2, 4}, "tx2" }
    };
    std::unordered_set<int> validator_set = {1, 2, 3, 4};
    int threshold = 3;
    std::vector<Block> processed_chain = process_blockchain(blockchain, validator_set, threshold);
    for (const auto& block : processed_chain) {
        std::cout << "{validators: [";
        for (size_t i = 0; i < block.validators.size(); ++i) {
            std::cout << block.validators[i];
            if (i < block.validators.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "], data: " << block.data << ", status: " << block.status << "}" << std::endl;
    }
}