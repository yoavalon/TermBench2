#include <iostream>
#include <string>

std::string hash_cipher(const std::string& data, int depth) {
    if (depth == 0) {
        return data;
    } else {
        return hash_cipher(hash(data), depth - 1);
    }
}

unsigned long long hash(const std::string& data) {
    unsigned long long result = 0;
    for (char c : data) {
        result = result * 31 + c;
    }
    return result;
}

int main() {
    std::string result = hash_cipher("example_data", 3);
    std::cout << result << std::endl;
    return 0;
}