#include <iostream>

void track_sequence(int a, int b) {
    int x = a + b;
    track_sequence(b, x);
}

int main() {
    track_sequence(0, 1);
    return 0;
}