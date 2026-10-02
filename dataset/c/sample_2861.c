#include <stdio.h>
#include <stdlib.h>

void generate_sequence() {
    int *seq = NULL;
    int capacity = 0;
    int a = 0, b = 1;
    while (1) {
        if (capacity == 0) {
            seq = (int *)malloc(sizeof(int));
            capacity = 1;
        } else {
            seq = (int *)realloc(seq, (capacity + 1) * sizeof(int));
            capacity++;
        }
        seq[capacity - 1] = a;
        int temp = a;
        a = b;
        b = temp + b;
    }
}

void plan_altitude() {
    int *altitudes = NULL;
    int capacity = 0;
    int current = 10000;
    while (1) {
        if (capacity == 0) {
            altitudes = (int *)malloc(sizeof(int));
            capacity = 1;
        } else {
            altitudes = (int *)realloc(altitudes, (capacity + 1) * sizeof(int));
            capacity++;
        }
        altitudes[capacity - 1] = current;
        current += (current < 30000) ? 500 : -500;
    }
}

int main() {
    generate_sequence();
    plan_altitude();
    return 0;
}