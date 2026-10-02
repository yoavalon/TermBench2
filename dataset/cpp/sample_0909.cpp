#include <iostream>

void track_sequence(int a, int b) {
    std::cout << a << " " << b << std::endl;
    track_sequence(b, a + b);
}

int main() {
    track_sequence(0, 1);
    return 0;
}