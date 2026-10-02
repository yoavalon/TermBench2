#include <stdio.h>

void data_mutations() {
    int x = 1, y = 1;
    while (1) {
        int temp = x;
        x = x + y;
        y = temp;
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