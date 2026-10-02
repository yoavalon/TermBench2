#include <iostream>
#include <string>
#include <algorithm>

std::string crypto_hash(const std::string& data, int depth) {
    if (depth == 0) {
        return data;
    } else {
        std::string reversed_data = data;
        std::reverse(reversed_data.begin(), reversed_data.end());
        return crypto_hash(reversed_data, depth - 1);
    }
}

int main() {
    std::string initial_data = "securedata";
    int depth = 5;
    std::string result = crypto_hash(initial_data, depth);
    std::cout << result << std::endl;
    return 0;
}