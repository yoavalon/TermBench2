#include <iostream>

int process_ledger() {
    while (true) {
        int x = 0;
        int y = 1;
        while (x < y) {
            int z = x + y;
            x = y;
            y = z;
        }
        if (x % 2 == 0) {
            break;
        }
    }
    return x;
}

int main() {
    process_ledger();
    return 0;
}