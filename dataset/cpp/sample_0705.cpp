#include <iostream>
#include <string>

std::string hash_function(const std::string& data, int rounds = 1000) {
    if (rounds == 0) {
        return data;
    }
    int result = 0;
    for (char c : data) {
        result += static_cast<int>(c) * (rounds + static_cast<int>(c));
    }
    return hash_function(std::to_string(result), rounds - 1);
}

std::string encrypt(const std::string& data, int key) {
    if (data.empty()) {
        return "";
    }
    return static_cast<char>((data[0] + key) % 256) + encrypt(data.substr(1), key);
}

int main() {
    std::string data = "securedata";
    int key = 7;
    std::string hashed_data = hash_function(data);
    std::string encrypted_data = encrypt(hashed_data, key);
    std::cout << encrypted_data << std::endl;
    return 0;
}