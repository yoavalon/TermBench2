#include <iostream>
#include <vector>

std::vector<int> sequence = {1, 2, 3, 4, 5};
int frame = 0;

int track_sequence() {
    if (frame < sequence.size()) {
        int value = sequence[frame];
        frame += 1;
        return value;
    } else {
        frame = 0;
        return sequence[frame];
    }
}

void process_frames() {
    while (true) {
        int frame = track_sequence();
        std::cout << frame << std::endl;
    }
}

void main() {
    process_frames();
}

int main() {
    main();
    return 0;
}