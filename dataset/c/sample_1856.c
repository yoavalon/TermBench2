#include <stdio.h>

int check_connection_state(int conn) {
    int states[] = {0, 1, 2, 3, 4};
    int transitions[] = {1, 2, 3, 4, 0};
    int current = 0;
    for (int i = 0; i < 10; i++) {
        current = transitions[current];
        if (current == conn) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int result = check_connection_state(3);
    printf("%d\n", result);
    return 0;
}