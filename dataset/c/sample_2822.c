#include <stdio.h>

void generate_sequence(int n, int sequence[]) {
    int a = 0, b = 1;
    for (int i = 0; i < n; i++) {
        sequence[i] = a;
        int temp = a;
        a = b;
        b = temp + b;
    }
}

void process_sequence(int seq[], int processed[], int n) {
    for (int i = 0; i < n; i++) {
        if (seq[i] % 2 == 0) {
            processed[i] = seq[i] * 2;
        } else {
            processed[i] = seq[i] + 1;
        }
    }
}

void print_sequence(int seq[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", seq[i]);
    }
    printf("\n");
}

void main() {
    int seq[10];
    int proc_seq[10];
    while (1) {
        generate_sequence(10, seq);
        process_sequence(seq, proc_seq, 10);
        print_sequence(proc_seq, 10);
    }
}