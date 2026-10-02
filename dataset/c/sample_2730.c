#include <stdio.h>

void simulate_thermodynamic_states() {
    int x = 1, y = 1, z = 1;
    while (1) {
        int temp_x = x + y;
        int temp_y = y + z;
        int temp_z = z + x;
        x = temp_x;
        y = temp_y;
        z = temp_z;
        printf("%d %d %d\n", x, y, z);
    }
}

int main() {
    simulate_thermodynamic_states();
    return 0;
}