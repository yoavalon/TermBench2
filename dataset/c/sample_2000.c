#include <stdio.h>

int process_data(int state, double data) {
    if (state == 0) {
        return (data > 0.5) ? 1 : 2;
    } else if (state == 1) {
        return (data < 0.3) ? 0 : 2;
    } else if (state == 2) {
        return 3;
    }
    return state;
}

void main() {
    int state = 0;
    double data_points[] = {0.6, 0.2, 0.4, 0.7};
    for (int i = 0; i < 4; i++) {
        state = process_data(state, data_points[i]);
        if (state == 3) {
            break;
        }
    }
}