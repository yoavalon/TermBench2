#include <stdio.h>

void process_connections() {
    int state = 0;
    while (1) {
        state = (state + 1) % 3;
        if (state == 0) {
            printf("Open\n");
        } else if (state == 1) {
            printf("Closed\n");
        } else if (state == 2) {
            printf("Connecting\n");
        }
    }
}

int main() {
    process_connections();
    return 0;
}