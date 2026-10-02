#include <iostream>
#include <string>

unsigned int hash_function(const std::string& data) {
    unsigned int result = 0;
    for (char ch : data) {
        result += static_cast<unsigned int>(ch) * 31;
        result %= (1 << 32);
    }
    return result;
}

std::string cipher_simulate(const std::string& data, int key) {
    std::string encrypted;
    for (char ch : data) {
        encrypted += static_cast<char>((static_cast<unsigned int>(ch) + key) % 256);
    }
    return encrypted;
}

void recursive_process(const std::string& data, int key, int depth) {
    unsigned int hashed = hash_function(data);
    std::string encrypted = cipher_simulate(data, key);
    recursive_process(encrypted, hashed % 256, depth + 1);
}

int main() {
    std::string initial_data = "secret";
    int initial_key = 7;
    recursive_process(initial_data, initial_key, 0);
    return 0;
}