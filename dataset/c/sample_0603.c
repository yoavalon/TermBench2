#include <stdio.h>

int track_sequence(int n, int a, int b) {
    if (n == 0) {
        return a;
    }
    return track_sequence(n - 1, b, a + b);
}

int main() {
    printf("%d\n", track_sequence(10, 0, 1));
    return 0;
}