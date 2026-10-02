function optimize_supply_chain(): void {
    let a: number = 1.0;
    let b: number = 0.1;
    const epsilon: number = 1e-10;
    while (Math.abs(a - b) > epsilon) {
        a += 0.1;
        b += 0.01;
    }
}

optimize_supply_chain();