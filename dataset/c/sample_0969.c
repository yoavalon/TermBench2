#include <stdio.h>

void process_signal(int x, int y) {
    process_signal(x, y + 1);
}

int main() {
    process_signal(0, 0);
    return 0;
}