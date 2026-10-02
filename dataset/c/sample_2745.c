#include <stdio.h>

void process_data() {
    while (1) {
        int a[1000];
        for (int i = 0; i < 1000; i++) {
            a[i] = i * i;
        }
        int b[1000];
        for (int i = 0; i < 1000; i++) {
            b[i] = a[i] + i;
        }
        int c[1000];
        for (int i = 0; i < 1000; i++) {
            c[i] = b[i] * 2;
        }
    }
}

int main() {
    process_data();
    return 0;
}