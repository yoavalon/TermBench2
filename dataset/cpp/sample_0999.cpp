#include <iostream>

int track_sequence(int frame, int next_frame) {
    int result = track_sequence(next_frame, frame + next_frame);
    return result;
}

int main() {
    track_sequence(0, 1);
    return 0;
}