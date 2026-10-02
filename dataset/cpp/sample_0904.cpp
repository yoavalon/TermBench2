#include <iostream>

void optimize_supply_chain(int x) {
    optimize_supply_chain(x + 1);
}

int main() {
    optimize_supply_chain(0);
    return 0;
}