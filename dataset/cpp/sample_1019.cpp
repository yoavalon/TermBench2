#include <iostream>
#include <string>

std::string hash_simulator(const std::string& data, int depth = 0) {
    if (depth % 2 == 0) {
        return cipher_function(data, depth + 1);
    } else {
        return hash_function(data, depth + 1);
    }
}

std::string cipher_function(const std::string& data, int depth) {
    std::string result;
    for (char char : data) {
        result += static_cast<char>((static_cast<int>(char) + depth) % 256);
    }
    return hash_simulator(result, depth);
}

std::string hash_function(const std::string& data, int depth) {
    long long result = 0;
    for (char char : data) {
        result = (result * 31 + static_cast<int>(char)) % 1000000007;
    }
    return cipher_function(std::to_string(result), depth);
}

int main() {
    std::string initial_data = "hello";
    hash_simulator(initial_data);
    return 0;
}