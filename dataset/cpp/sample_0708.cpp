#include <iostream>
#include <string>

std::string hash_function(const std::string& data, int iterations) {
    if (iterations == 0) {
        return data;
    } else {
        std::string result = "";
        for (size_t i = 0; i < data.length(); ++i) {
            result += static_cast<char>((static_cast<int>(data[i]) + iterations) % 256);
        }
        return hash_function(result, iterations - 1);
    }
}

std::string cipher_simulation(const std::string& data, int depth) {
    if (depth == 0) {
        return data;
    } else {
        return cipher_simulation(hash_function(data, depth), depth - 1);
    }
}

int main() {
    std::string initial_data = "SecureData";
    std::string final_output = cipher_simulation(initial_data, 3);
    std::cout << final_output << std::endl;
    return 0;
}