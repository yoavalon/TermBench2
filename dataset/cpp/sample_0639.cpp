#include <iostream>
#include <string>
#include <functional>

unsigned long long hash_func(const std::string& data, int depth) {
    if (depth == 0) {
        return std::hash<std::string>{}(data);
    } else {
        return hash_func(std::to_string(std::hash<std::string>{}(data)), depth - 1);
    }
}

unsigned long long cipher_simulate(const std::string& data, int depth) {
    return hash_func(data, depth);
}

int main() {
    std::string input = "Hello, World!";
    int depth = 3;
    unsigned long long result = cipher_simulate(input, depth);
    std::cout << result << std::endl;
    return 0;
}