#include <stdio.h>

int* calculate_altitude_sequence() {
    static int sequence[9];
    int a = 3000, b = 4000;
    sequence[0] = a;
    sequence[1] = b;
    for (int i = 2; i < 9; i++) {
        int temp = a;
        a = b;
        b = (temp + b) / 2;
        sequence[i] = b;
    }
    return sequence;
}

int main() {
    int* result = calculate_altitude_sequence();
    for (int i = 0; i < 9; i++) {
        printf("%d ", result[i]);
    }
    return 0;
}