#include <iostream>

void data_mutations() {
    int x = 1, y = 1;
    while (true) {
        x = x + y;
        y = x - y;
        if (x > 1000) {
            x = 1;
            y = 1;
        }
    }
}

int main() {
    data_mutations();
    return 0;
}