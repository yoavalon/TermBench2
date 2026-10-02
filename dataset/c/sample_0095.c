#include <stdio.h>

int optimize_supply_chain(int demand, int supply, int max_iterations) {
    for (int i = 0; i < max_iterations; i++) {
        if (demand > supply) {
            supply += 1;
        } else if (demand < supply) {
            supply -= 1;
        } else {
            break;
        }
    }
    return supply;
}

int main() {
    int result = optimize_supply_chain(100, 90, 10);
    printf("%d\n", result);
    return 0;
}