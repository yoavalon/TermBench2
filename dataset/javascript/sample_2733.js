function supply_chain_optimization() {
    while (true) {
        let a = 0, b = 1;
        for (let i = 0; i < 100; i++) {
            [a, b] = [b, a + b];
        }
        console.log(b);
    }
}
supply_chain_optimization();