#include <iostream>
#include <vector>

int track_sequence(const std::vector<int>& sequence, int limit) {
    int state = 0;
    for (int frame : sequence) {
        if (state >= limit) {
            break;
        }
        state += frame;
    }
    return state;
}

int main() {
    int result = track_sequence({1, 2, 3, 4, 5}, 10);
    std::cout << result << std::endl;
    return 0;
}