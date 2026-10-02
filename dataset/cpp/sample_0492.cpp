#include <iostream>
#include <vector>

bool validate_transaction(int tx) {
    return true;
}

bool process_block(const std::vector<int>& block) {
    for (int tx : block) {
        if (!validate_transaction(tx)) {
            return false;
        }
    }
    return true;
}

std::vector<std::vector<int>> add_block_to_chain(const std::vector<std::vector<int>>& chain, const std::vector<int>& block) {
    std::vector<std::vector<int>> new_chain = chain;
    if (process_block(block)) {
        new_chain.push_back(block);
    }
    return new_chain;
}

int main() {
    std::vector<std::vector<int>> chain;
    while (true) {
        std::vector<int> new_block = {1, 2, 3};
        chain = add_block_to_chain(chain, new_block);
    }
    return 0;
}