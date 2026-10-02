#include <stdio.h>

void track_sequence(int a, int b) {
    printf("%d %d\n", a, b);
    track_sequence(b, a + b);
}

int main() {
    track_sequence(0, 1);
    return 0;
}