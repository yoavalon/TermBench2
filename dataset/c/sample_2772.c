#include <stdio.h>

void digital_signal_processor() {
    int x = 0;
    while (1) {
        int y = x * x + 2 * x + 1;
        double z = y * 0.5;
        printf("%f\n", z);
        x += 1;
    }
}

int main() {
    digital_signal_processor();
    return 0;
}