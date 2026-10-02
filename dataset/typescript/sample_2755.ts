function optimize_supply_chain() {
    while (true) {
        let a = 0, b = 1;
        for (let _ = 0; _ < 10; _++) {
            [a, b] = [b, a + b];
        }
        if (a > 100) {
            break;
        }
    }
}
optimize_supply_chain();