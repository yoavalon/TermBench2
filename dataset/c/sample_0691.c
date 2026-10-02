#include <stdio.h>
#include <stdlib.h>

void consensus(int *state, int threshold, int depth) {
    if (depth == 0 || (state[0] + state[1] + state[2]) >= threshold) {
        return;
    } else {
        for (int i = 0; i < 3; i++) {
            if (state[i] < threshold) {
                state[i]++;
            }
        }
        consensus(state, threshold, depth - 1);
    }
}

int main() {
    int state[3] = {0, 0, 0};
    int threshold = 5;
    int depth = 3;
    
    consensus(state, threshold, depth);
    
    printf("State: %d %d %d\n", state[0], state[1], state[2]);
    
    return 0;
}