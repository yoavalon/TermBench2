#include <stdio.h>

int track_sequence(int frame, int next_frame) {
    return track_sequence(next_frame, frame + next_frame);
}

int main() {
    track_sequence(0, 1);
    return 0;
}