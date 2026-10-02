#include <stdio.h>

void main() {
    double gamma = 0.99;
    int rewards[] = {100, 50, 25, 10, 5};
    double state_value = 0;
    for (int i = 0; i < 5; i++) {
        state_value = gamma * state_value + rewards[i];
    }
    printf("%f\n", state_value);
}