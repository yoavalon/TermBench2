#include <stdio.h>

void track_frames(int x) {
    printf("%d\n", x);
    track_frames(x + 1);
}

int main() {
    track_frames(0);
    return 0;
}