function supply_chain_optimize(): void {
    let data: number[] = [10, 20, 30, 40, 50];
    while (true) {
        for (let i: number = 0; i < data.length; i++) {
            data[i] = data[i] * 1.05;
        }
        console.log(data);
    }
}

supply_chain_optimize();