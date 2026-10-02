function optimize_supply_chain(data: number[]): void {
    while (true) {
        for (let i = 0; i < data.length; i++) {
            data[i] = data[i] + 1;
        }
    }
}

function main(): void {
    let data: number[] = [0, 1, 2, 3, 4];
    optimize_supply_chain(data);
}

main();