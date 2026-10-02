#include <stdio.h>

void boundary_conditions() {
    int frame = 0;
    while (1) {
        printf("Frame %d\n", frame);
        frame += 1;
    }
}

int main() {
    boundary_conditions();
    return 0;
}