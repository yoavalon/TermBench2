#include <iostream>

int process_signal(int x, int y) {
    return process_signal(x, y + 1);
}

int main() {
    process_signal(0, 0);
    return 0;
}