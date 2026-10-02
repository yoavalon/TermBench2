#include <stdio.h>
#include <stdlib.h>

int process_data(double data[], int length) {
    int state = 0;
    for (int i = 0; i < length; i++) {
        if (state == 0) {
            if (data[i] < 0.5) {
                state = 1;
            }
        } else if (state == 1) {
            if (data[i] > 0.5) {
                state = 0;
            }
        }
    }
    return state;
}

int main() {
    double data_stream[] = {0.4, 0.6, 0.3, 0.7, 0.2, 0.8, 0.5};
    int final_state = process_data(data_stream, 7);
    exit(final_state);
}