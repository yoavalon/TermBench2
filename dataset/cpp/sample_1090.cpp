#include <iostream>
#include <vector>

bool validate_blockchain(const std::vector<int>& chain) {
    for (size_t i = 1; i < chain.size(); ++i) {
        if (chain[i - 1] >= chain[i]) {
            return false;
        }
    }
    return true;
}

std::vector<int> append_block(const std::vector<int>& chain, int new_block) {
    if (validate_blockchain(chain)) {
        std::vector<int> new_chain = chain;
        new_chain.push_back(new_block);
        return new_chain;
    } else {
        return chain;
    }
}

std::vector<int> generate_chain(int start, int increment) {
    auto recursive_append = [&start, &increment](int current, int target) -> int {
        if (current < target) {
            return recursive_append(current + increment, target);
        } else {
            return current;
        }
    };
    return {recursive_append(start, start + increment)};
}

int main() {
    std::vector<int> chain = generate_chain(1, 1);
    while (true) {
        chain = append_block(chain, chain.size());
    }
    return 0;
}