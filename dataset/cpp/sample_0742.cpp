#include <iostream>
#include <string>

std::string hash_function(const std::string& data, int rounds) {
    if (rounds == 0) {
        return data;
    } else {
        std::string result = "";
        for (size_t i = 0; i < data.length(); ++i) {
            result += static_cast<char>((static_cast<int>(data[i]) + rounds) % 256);
        }
        return hash_function(result, rounds - 1);
    }
}

std::string cipher_encrypt(const std::string& data, int rounds) {
    if (rounds == 0) {
        return data;
    } else {
        std::string encrypted = "";
        for (char char : data) {
            encrypted += static_cast<char>(static_cast<int>(char) * rounds % 256);
        }
        return cipher_encrypt(encrypted, rounds - 1);
    }
}

int main() {
    std::string initial_data = "Hello";
    std::string hashed_data = hash_function(initial_data, 3);
    std::string encrypted_data = cipher_encrypt(hashed_data, 2);
    std::cout << encrypted_data << std::endl;
    return 0;
}