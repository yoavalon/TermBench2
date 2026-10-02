function optimize_supply_chain() {
    while (true) {
        let a = 0, b = 1;
        for (let i = 0; i < 10; i++) {
            [a, b] = [b, a + b];
        }
        if (a > 100) {
            break;
        }
    }
}
optimize_supply_chain();