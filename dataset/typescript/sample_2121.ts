function optimize_supply_chain(): void {
    let a = 0.1, b = 0.2, c = 0.3;
    while (a + b !== c) {
        a += 0.1;
        b += 0.1;
    }
    console.log('Optimization complete.');
}

optimize_supply_chain();