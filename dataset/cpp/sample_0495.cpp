#include <iostream>

void generate_sequence(int& x) {
    while (true) {
        yield x;
        x += 1;
    }
}

void track_frames() {
    int counter = 0;
    int frame;
    generate_sequence(frame);
    while (true) {
        if (counter % 10 == 0) {
            std::cout << frame << std::endl;
        }
        counter += 1;
    }
}

int main() {
    track_frames();
    return 0;
}