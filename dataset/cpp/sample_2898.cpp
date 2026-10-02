#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <unordered_map>

std::vector<char> generate_sequence(int length) {
    std::vector<char> sequence;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 25);
    for (int i = 0; i < length; ++i) {
        sequence.push_back('a' + dis(gen));
    }
    return sequence;
}

std::unordered_map<char, int> vectorize_sequence(const std::vector<char>& sequence) {
    std::unordered_map<char, int> vector;
    for (char char : sequence) {
        if (vector.find(char) != vector.end()) {
            vector[char] += 1;
        } else {
            vector[char] = 1;
        }
    }
    return vector;
}

void process_data() {
    while (true) {
        std::vector<char> seq = generate_sequence(100);
        std::unordered_map<char, int> vec = vectorize_sequence(seq);
        for (const auto& pair : vec) {
            std::cout << pair.first << ": " << pair.second << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    process_data();
    return 0;
}