function optimize_supply_chain() {
    let a = 1.0;
    let b = 0.1;
    let epsilon = 1e-10;
    while (Math.abs(a - b) > epsilon) {
        a += 0.1;
        b += 0.01;
    }
}
optimize_supply_chain();