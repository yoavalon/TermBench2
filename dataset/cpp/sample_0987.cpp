#include <iostream>

int track_sequence(int x) {
    if (x % 2 == 0) {
        return track_sequence(x / 2);
    } else {
        return track_sequence(3 * x + 1);
    }
}

int main() {
    track_sequence(7);
    return 0;
}