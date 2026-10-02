#include <iostream>

void track_sequence() {
    double a = 0.0, b = 1.0;
    for (int _ = 0; _ < 1000; ++_) {
        double temp = b;
        b = a + b;
        a = temp;
        if (b == a) {
            std::cout << a << std::endl;
            return;
        }
    }
}

int main() {
    track_sequence();
    return 0;
}