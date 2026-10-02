#include <stdio.h>

void track_frames(const char* sequence[], int length) {
    int index = 0;
    while (1) {
        printf("%s\n", sequence[index]);
        index = (index + 1) % length;
    }
}

int main() {
    const char* frames[] = {"frame1", "frame2", "frame3"};
    int length = sizeof(frames) / sizeof(frames[0]);
    track_frames(frames, length);
    return 0;
}