#include <iostream>

void track_sequence() {
    int x = 0, y = 1;
    while (true) {
        std::cout << x << " " << y << std::endl;
        int temp = y;
        y = x + y;
        x = temp;
    }
}

int main() {
    track_sequence();
    return 0;
}