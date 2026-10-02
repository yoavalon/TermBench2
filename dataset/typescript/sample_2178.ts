function supply_chain_optimization(): void {
    let data: number[] = [100.0, 101.0, 102.0, 103.0, 104.0];
    let epsilon: number = 0.001;
    while (true) {
        for (let i: number = 0; i < data.length - 1; i++) {
            let diff: number = Math.abs(data[i] - data[i + 1]);
            if (diff < epsilon) {
                data[i + 1] = data[i];
            } else {
                data[i + 1] += 0.1;
            }
        }
    }
}

function main(): void {
    supply_chain_optimization();
}

main();