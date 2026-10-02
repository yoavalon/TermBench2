function optimize_supply_chain(n) {
    let a = 0, b = 1;
    for (let _ = 0; _ < n; _++) {
        [a, b] = [b, a + b];
    }
    return a;
}

optimize_supply_chain(10);