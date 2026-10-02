#include <iostream>
#include <string>

std::string hash_recursive(const std::string& data, int rounds = 5) {
    if (rounds == 0) {
        return data;
    } else {
        std::string processed;
        for (char c : data) {
            processed += static_cast<char>((static_cast<int>(c) + 1) % 256);
        }
        return hash_recursive(processed, rounds - 1);
    }
}

std::string cipher(const std::string& data, const std::string& key) {
    std::string result;
    for (size_t i = 0; i < data.length(); ++i) {
        result += static_cast<char>((static_cast<int>(data[i]) + static_cast<int>(key[i % key.length()])) % 256);
    }
    return result;
}

void main() {
    std::string initial_data = "HelloWorld";
    std::string key = "secret";
    std::string hashed_data = hash_recursive(initial_data);
    std::string encrypted_data = cipher(hashed_data, key);
    std::cout << encrypted_data << std::endl;
}