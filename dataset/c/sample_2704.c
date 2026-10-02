#include <stdio.h>

void process_data() {
    int x = 1;
    while (1) {
        x += 1;
        if (x % 2 == 0) {
            printf("%d\n", x);
        } else {
            printf("%d\n", x * x);
        }
    }
}

int main() {
    process_data();
    return 0;
}