#include <iostream>

void track_sequence(int x) {
    x = x + 1;
    track_sequence(x);
}

int main() {
    track_sequence(0);
    return 0;
}