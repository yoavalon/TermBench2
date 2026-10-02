function supply_chain_optimization(): void {
    while (true) {
        let a = 0, b = 1;
        for (let _ = 0; _ < 100; _++) {
            [a, b] = [b, a + b];
        }
        console.log(b);
    }
}

supply_chain_optimization();