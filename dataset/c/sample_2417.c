c
#include <stdio.h>

int simulate_thermodynamic_state(int n) {
    int seq[n];
    for (int i = 0; i < n; i++) {
        seq[i] = 0;
    }
    for (int i = 1; i < n; i++) {
        seq[i] = seq[i - 1] + i * (i + 1) / 2;
    }
    return seq[n - 1];
}

int main() {
    int result = simulate_thermodynamic_state(10);
    printf("%d\n", result);
    return 0;
}