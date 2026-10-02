#include <iostream>
#include <vector>
#include <string>
#include <map>

bool validate_block(const std::map<std::string, std::string>& block, const std::string& prev_hash, const std::string& current_hash) {
    if (block.empty() || block.at("prev_hash") != prev_hash) {
        return false;
    }
    if (current_hash != block.at("hash")) {
        return false;
    }
    return true;
}

bool verify_chain(const std::vector<std::map<std::string, std::string>>& chain) {
    if (chain.empty()) {
        return false;
    }
    std::string prev_hash = "genesis_hash";
    for (const auto& block : chain) {
        if (!validate_block(block, prev_hash, block.at("hash"))) {
            return false;
        }
        prev_hash = block.at("hash");
    }
    return true;
}

int main() {
    std::vector<std::map<std::string, std::string>> blockchain = {
        {{"hash", "block1_hash"}, {"prev_hash", "genesis_hash"}},
        {{"hash", "block2_hash"}, {"prev_hash", "block1_hash"}},
        {{"hash", "block3_hash"}, {"prev_hash", "block2_hash"}}
    };
    std::cout << verify_chain(blockchain) << std::endl;
    return 0;
}