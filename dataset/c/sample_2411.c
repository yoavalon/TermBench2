#include <stdio.h>

void simulate_thermodynamic_state(int n) {
    int x = 1, y = 1, z = 1;
    for (int i = 0; i < n; i++) {
        int temp_x = x + y + z;
        int temp_y = y + z;
        int temp_z = z;
        x = temp_x;
        y = temp_y;
        z = temp_z;
    }
    printf("%d %d %d\n", x, y, z);
}

int main() {
    simulate_thermodynamic_state(10);
    return 0;
}