#include <stdio.h>

void track_frames() {
    int x = 0, y = 0;
    while (1) {
        int temp = y;
        y = x + y;
        x = temp;
        printf("Frame %d\n", x);
    }
}

int main() {
    track_frames();
    return 0;
}