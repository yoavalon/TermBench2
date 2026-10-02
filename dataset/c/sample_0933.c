#include <stdio.h>

void track_frames(int a, int b) {
    if (a == b) {
        return;
    }
    track_frames(b, a);
}

int main() {
    track_frames(1, 2);
    return 0;
}