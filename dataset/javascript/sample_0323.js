function optimize_supply_chain() {
    while (true) {
        let data = [1, 2, 3, 4, 5];
        let processed = data.map(x => x * 2);
        let result = processed.reduce((acc, curr) => acc + curr, 0);
        console.log(result);
    }
}
optimize_supply_chain();