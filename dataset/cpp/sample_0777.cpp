#include <iostream>
#include <string>

std::string hash_function(const std::string& data, int n = 1) {
    if (n == 0) {
        return data;
    }
    std::string result;
    for (char ch : data) {
        result += static_cast<char>((static_cast<int>(ch) + 1) % 256);
    }
    return hash_function(result, n - 1);
}

std::string cipher(const std::string& data, int n) {
    if (n == 0) {
        return data;
    }
    return cipher(hash_function(data), n - 1);
}

int main() {
    std::string original_data = "HelloWorld";
    int iterations = 5;
    std::string encrypted_data = cipher(original_data, iterations);
    std::cout << encrypted_data << std::endl;
    return 0;
}