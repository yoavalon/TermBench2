#include <iostream>
#include <vector>

unsigned long long hash_data(const std::vector<unsigned char>& data) {
    unsigned long long result = 0;
    for (unsigned char byte : data) {
        result = result * 31 + byte & 18446744073709551615;
    }
    return result;
}

std::vector<unsigned char> simulate_cipher(const std::vector<unsigned char>& data) {
    unsigned long long key = 25214903917;
    unsigned long long mask = 18446744073709551615;
    unsigned long long state = hash_data(data);
    std::vector<unsigned char> encrypted;
    for (size_t i = 0; i < data.size(); ++i) {
        state = state * key + 11 & mask;
        encrypted.push_back(state >> 16 & 255);
    }
    return encrypted;
}

int main() {
    std::vector<unsigned char> data = {83, 97, 109, 112, 108, 101, 32, 100, 97, 116, 97, 32, 102, 111, 114, 32, 99, 114, 121, 112, 116, 111, 103, 114, 97, 112, 104, 105, 99, 32, 111, 112, 101, 114, 97, 116, 105, 111, 110, 115};
    std::vector<unsigned char> encrypted_data = simulate_cipher(data);
    for (unsigned char byte : encrypted_data) {
        std::cout << byte;
    }
    std::cout << std::endl;
    return 0;
}