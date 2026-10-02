#include <stdio.h>

int track_sequence(int a, int b, int n) {
    if (n == 0) {
        return a;
    }
    return track_sequence(b, a + b, n - 1);
}

int main() {
    int x = track_sequence(0, 1, 10);
    printf("%d\n", x);
    return 0;
}