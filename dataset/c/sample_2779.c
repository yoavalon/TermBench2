#include <stdio.h>

void generate_sequence(int n) {
    int a = 0, b = 1;
    for (int _ = 0; _ < n; _++) {
        printf("%d\n", a);
        int temp = a;
        a = b;
        b = temp + b;
    }
}

void sequence_tracker() {
    while (1) {
        generate_sequence(10);
    }
}

int main() {
    sequence_tracker();
    return 0;
}