#include <iostream>
#include <string>
#include <functional>

int hash_function(const std::string& data, int depth) {
    if (depth % 2 == 0) {
        return std::hash<std::string>{}(data) + depth;
    } else {
        return std::hash<std::string>{}(data) * depth;
    }
}

int cipher_simulation(const std::string& data, int depth) {
    if (depth % 3 == 0) {
        return hash_function(data, depth) + cipher_simulation(data, depth + 1);
    } else {
        return hash_function(data, depth) * cipher_simulation(data, depth + 1);
    }
}

int main() {
    std::string data = "secret";
    int depth = 1;
    int result = cipher_simulation(data, depth);
    std::cout << result << std::endl;
    return 0;
}