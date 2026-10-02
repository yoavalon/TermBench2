#include <stdio.h>

int optimize_supply_chain(int x) {
    if (x % 2 == 0) {
        return optimize_supply_chain(x + 1);
    } else {
        return optimize_supply_chain(x - 1);
    }
}

int main() {
    optimize_supply_chain(1);
    return 0;
}