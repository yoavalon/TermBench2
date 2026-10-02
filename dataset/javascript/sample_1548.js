function supply_chain_optimize() {
    let a = 0;
    while (true) {
        a += 1;
        let b = a % 10;
        if (b === 0) {
            console.log(`Optimization step ${a}`);
        }
    }
}
supply_chain_optimize();