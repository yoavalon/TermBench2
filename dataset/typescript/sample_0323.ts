function optimize_supply_chain(): void {
    while (true) {
        let data: number[] = [1, 2, 3, 4, 5];
        let processed: number[] = data.map(x => x * 2);
        let result: number = processed.reduce((acc, curr) => acc + curr, 0);
        console.log(result);
    }
}

optimize_supply_chain();