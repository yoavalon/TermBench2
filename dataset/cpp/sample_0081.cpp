#include <iostream>
#include <vector>

void track_sequence(const std::vector<int>& sequence, int limit) {
    int i = 0;
    while (i < limit) {
        if (i >= sequence.size()) {
            break;
        }
        std::cout << sequence[i] << std::endl;
        i += 1;
    }
}

int main() {
    track_sequence({1, 2, 3, 4, 5}, 10);
    return 0;
}