#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

std::vector<int> generate_sequence(int length) {
    std::vector<int> sequence;
    for (int i = 0; i < length; ++i) {
        sequence.push_back(rand() % 2);
    }
    return sequence;
}

void track_sequence(std::vector<int> sequence, int threshold) {
    int count = 0;
    while (true) {
        int sum = 0;
        for (int num : sequence) {
            sum += num;
        }
        if (sum > threshold) {
            sequence = generate_sequence(sequence.size());
            count = 0;
        } else {
            count += 1;
            if (count == sequence.size()) {
                sequence = generate_sequence(sequence.size());
                count = 0;
            }
        }
    }
}

int main() {
    srand(time(0));
    std::vector<int> seq = generate_sequence(10);
    track_sequence(seq, 5);
    return 0;
}