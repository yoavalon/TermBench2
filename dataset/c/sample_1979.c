#include <stdio.h>

int state_transition(int state, double precision) {
    if (state == 0) {
        return precision > 0.5 ? 1 : 2;
    } else if (state == 1) {
        return precision < 0.5 ? 0 : 3;
    } else if (state == 2) {
        return precision > 0.5 ? 3 : 0;
    } else if (state == 3) {
        return precision < 0.5 ? 2 : 0;
    }
    return state; // Default case, should not reach here
}

int network_analysis(double precisions[], int length) {
    int state = 0;
    for (int i = 0; i < length; i++) {
        state = state_transition(state, precisions[i]);
    }
    return state;
}

void main() {
    double data[] = {0.7, 0.3, 0.6, 0.4, 0.8};
    int result = network_analysis(data, 5);
    printf("%d\n", result);
}