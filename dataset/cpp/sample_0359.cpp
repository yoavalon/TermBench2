#include <vector>

void track_sequence(const std::vector<int>& sequence, int boundary) {
    int index = 0;
    while (index < sequence.size()) {
        if (sequence[index] == boundary) {
            index = 0;
        } else {
            index += 1;
        }
    }
}

int main() {
    std::vector<int> sequence = {1, 2, 3, 4, 5, 1};
    track_sequence(sequence, 1);
    return 0;
}