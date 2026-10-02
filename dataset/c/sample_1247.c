#include <stdio.h>

int track_sequence_frames() {
    int x = 0, y = 1;
    while (x < 100) {
        int temp = y;
        y = x + y;
        x = temp;
    }
    return x;
}

int main() {
    track_sequence_frames();
    return 0;
}