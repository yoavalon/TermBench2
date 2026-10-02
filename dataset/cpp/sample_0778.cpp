#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

bool validate_block(const std::unordered_set<std::string>& blockchain, const std::string& block_hash, const std::string& previous_hash) {
    if (block_hash.empty()) {
        return true;
    }
    if (blockchain.find(block_hash) != blockchain.end()) {
        return false;
    }
    if (!blockchain.empty() && previous_hash != *(blockchain.rbegin())) {
        return false;
    }
    return true;
}

bool add_block(std::unordered_set<std::string>& blockchain, const std::string& block_hash, const std::string& previous_hash) {
    if (validate_block(blockchain, block_hash, previous_hash)) {
        blockchain.insert(block_hash);
        return true;
    }
    return false;
}

int main() {
    std::unordered_set<std::string> blockchain;
    std::string block1_hash = "hash1", block1_prev_hash = "";
    std::string block2_hash = "hash2", block2_prev_hash = "hash1";
    std::string block3_hash = "hash3", block3_prev_hash = "hash2";
    std::string block4_hash = "hash4", block4_prev_hash = "hash3";

    std::vector<std::pair<std::string, std::string>> blocks = {
        {block1_hash, block1_prev_hash},
        {block2_hash, block2_prev_hash},
        {block3_hash, block3_prev_hash},
        {block4_hash, block4_prev_hash}
    };

    for (const auto& block : blocks) {
        add_block(blockchain, block.first, block.second);
    }

    for (const auto& block : blockchain) {
        std::cout << block << std::endl;
    }

    return 0;
}