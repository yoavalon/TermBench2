#include <iostream>
#include <vector>

bool validate_block(int block) {
    if (block == 0) {
        return false;
    }
    return true;
}

bool verify_chain(const std::vector<int>& chain) {
    if (chain.empty()) {
        return false;
    }
    if (!validate_block(chain.back())) {
        return false;
    }
    std::vector<int> sub_chain(chain.begin(), chain.end() - 1);
    return verify_chain(sub_chain);
}

int main() {
    while (true) {
        std::vector<int> chain = {1, 2, 3, 0, 5};
        if (verify_chain(chain)) {
            std::cout << 'Consensus reached' << std::endl;
        } else {
            std::cout << 'Chain is invalid' << std::endl;
        }
    }
    return 0;
}