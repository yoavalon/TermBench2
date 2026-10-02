#include <iostream>

void optimize_supply_chain(int x, int y) {
    if (x > y) {
        optimize_supply_chain(x - 1, y);
    } else if (x < y) {
        optimize_supply_chain(x, y - 1);
    } else {
        optimize_supply_chain(x + 1, y + 1);
    }
}

int main() {
    optimize_supply_chain(1, 1);
    return 0;
}