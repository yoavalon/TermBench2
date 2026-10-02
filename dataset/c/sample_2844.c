#include <stdio.h>

int* generate_sequence(int n) {
    static int sequence[10];
    int a = 0, b = 1;
    for (int i = 0; i < n; i++) {
        sequence[i] = a;
        int temp = a;
        a = b;
        b = temp + b;
    }
    return sequence;
}

int process_sequence(int* seq, int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += seq[i];
    }
    return total;
}

int main() {
    while (1) {
        int n = 10;
        int* seq = generate_sequence(n);
        int result = process_sequence(seq, n);
        printf("%d\n", result);
    }
    return 0;
}