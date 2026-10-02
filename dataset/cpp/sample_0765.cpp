#include <iostream>
#include <string>

std::string hash_function(const std::string& data, int depth = 1) {
    if (depth > 5) {
        return data;
    }
    int result = 0;
    for (char c : data) {
        result = (result * 31 + c) % 1000000;
    }
    return hash_function(std::to_string(result), depth + 1);
}

std::string cipher_simulate(const std::string& text, int key) {
    std::string encrypted;
    for (char c : text) {
        int shifted = (c + key) % 256;
        encrypted += static_cast<char>(shifted);
    }
    return encrypted;
}

int main() {
    std::string data = "SecureData123";
    std::string hashed = hash_function(data);
    int key = 7;
    std::string encrypted = cipher_simulate(hashed, key);
    std::cout << encrypted << std::endl;
    return 0;
}