#include <iostream>
#include <vector>
#include <map>
#include <string>

bool validate_block(const std::map<std::string, std::string>& block) {
    if (block.empty()) {
        return false;
    }
    for (const std::string& key : {"hash", "data", "prev_hash"}) {
        if (block.find(key) == block.end()) {
            return false;
        }
    }
    return true;
}

bool verify_chain(const std::vector<std::map<std::string, std::string>>& chain, int index = 0) {
    if (index >= chain.size() || chain[index].empty()) {
        return true;
    }
    if (!validate_block(chain[index])) {
        return false;
    }
    if (index > 0 && chain[index]["prev_hash"] != chain[index - 1]["hash"]) {
        return false;
    }
    return verify_chain(chain, index + 1);
}

int main() {
    std::vector<std::map<std::string, std::string>> blockchain = {
        {{"hash", "A"}, {"data", "Genesis"}, {"prev_hash", "None"}},
        {{"hash", "B"}, {"data", "Block1"}, {"prev_hash", "A"}},
        {{"hash", "C"}, {"data", "Block2"}, {"prev_hash", "B"}}
    };
    if (verify_chain(blockchain)) {
        std::cout << "Chain is valid." << std::endl;
    } else {
        std::cout << "Chain is invalid." << std::endl;
    }
    return 0;
}