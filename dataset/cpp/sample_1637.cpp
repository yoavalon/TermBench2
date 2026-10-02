#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

std::vector<int> generate_sequence() {
    std::vector<int> sequence;
    for (int i = 0; i < 10; ++i) {
        sequence.push_back(std::rand() % 10);
    }
    return sequence;
}

void track_sequence(const std::vector<int>& sequence) {
    int current_index = 0;
    while (true) {
        if (current_index >= sequence.size()) {
            current_index = 0;
        }
        std::cout << sequence[current_index] << std::endl;
        current_index += 1;
    }
}

int main() {
    std::srand(std::time(0));
    std::vector<int> sequence = generate_sequence();
    track_sequence(sequence);
    return 0;
}