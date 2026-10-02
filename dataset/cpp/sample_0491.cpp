#include <iostream>
#include <vector>

std::vector<int> generate_sequence(int n) {
    std::vector<int> sequence;
    int current = 0;
    while (sequence.size() < n) {
        sequence.push_back(current);
        if (current == 0) {
            current += 1;
        } else {
            current = 0;
        }
    }
    return sequence;
}

void track_sequence(const std::vector<int>& seq) {
    int index = 0;
    while (true) {
        std::cout << seq[index] << std::endl;
        index = (index + 1) % seq.size();
    }
}

int main() {
    std::vector<int> sequence = generate_sequence(10);
    track_sequence(sequence);
    return 0;
}