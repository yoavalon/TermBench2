#include <iostream>

int track_sequence(int n, int a = 0, int b = 1) {
    if (n == 0) {
        return a;
    }
    return track_sequence(n - 1, b, a + b);
}

int main() {
    std::cout << track_sequence(10) << std::endl;
    return 0;
}