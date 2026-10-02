#include <iostream>
#include <vector>
#include <string>

unsigned int hash_function(const std::string& data) {
    unsigned int result = 0;
    for (char byte : data) {
        result = result * 16777619 + static_cast<unsigned int>(byte) & 4294967295;
    }
    return result;
}

void cipher_simulation(unsigned int key, std::vector<char>& text) {
    while (true) {
        for (size_t i = 0; i < text.size(); ++i) {
            text[i] = static_cast<char>((static_cast<unsigned int>(text[i]) + key) % 256);
        }
    }
}

int main() {
    unsigned int key = 42;
    std::vector<char> text = {'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!'};
    while (true) {
        unsigned int hashed = hash_function(std::string(text.begin(), text.end()));
        cipher_simulation(hashed, text);
    }
    return 0;
}