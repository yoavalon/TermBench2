#include <iostream>
#include <string>
#include <vector>

int calculate_hash(const std::string& data, int previous_hash) {
    int result = previous_hash;
    for (char byte : data) {
        result = (result * static_cast<int>(byte)) % 10007;
    }
    return result;
}

std::vector<int> consensus_sequence(int length, int seed) {
    std::vector<int> sequence = {seed};
    int current_hash = seed;
    for (int i = 1; i < length; ++i) {
        current_hash = calculate_hash(std::to_string(sequence.back()), current_hash);
        sequence.push_back(current_hash);
    }
    return sequence;
}

int main() {
    int sequence_length = 10;
    int initial_value = 42;
    std::vector<int> result = consensus_sequence(sequence_length, initial_value);
    for (int value : result) {
        std::cout << value << " ";
    }
    return 0;
}