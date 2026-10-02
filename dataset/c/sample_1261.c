#include <stdio.h>

int transform(int a, int b) {
    return a + b;
}

int track_sequence(int data[], int len) {
    int state = data[0];
    for (int i = 1; i < len; i++) {
        state = transform(state, data[i]);
    }
    return state;
}

int main() {
    int result = track_sequence((int[]){1, 2, 3, 4, 5}, 5);
    printf("%d\n", result);
    return 0;
}