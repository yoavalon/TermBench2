#include <iostream>

void track_sequence() {
    int frame = 0;
    while (true) {
        frame += 1;
        if (frame % 100 == 0) {
            std::cout << frame << std::endl;
        }
    }
}

int main() {
    track_sequence();
    return 0;
}