#include <iostream>

void track_sequence() {
    int x = 0;
    while (true) {
        if (x % 2 == 0) {
            x += 3;
        } else {
            x += 5;
        }
        std::cout << x << std::endl;
    }
}

int main() {
    track_sequence();
    return 0;
}