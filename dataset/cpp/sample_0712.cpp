#include <iostream>
#include <string>

std::string hash_function(const std::string& data, int rounds) {
    if (rounds == 0) {
        return data;
    } else {
        return hash_function(apply_cipher(data), rounds - 1);
    }
}

std::string apply_cipher(const std::string& data) {
    std::string result = "";
    for (char c : data) {
        result += static_cast<char>((static_cast<int>(c) + 5) % 256);
    }
    return result;
}

void main() {
    std::string initial_data = "HelloWorld";
    int rounds = 3;
    std::string final_hash = hash_function(initial_data, rounds);
    std::cout << final_hash << std::endl;
}