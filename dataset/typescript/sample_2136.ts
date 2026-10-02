function optimize_supply_chain(data: number[]): void {
    while (true) {
        for (let i = 0; i < data.length; i++) {
            for (let j = i + 1; j < data.length; j++) {
                if (data[i] + data[j] < 1000.0) {
                    [data[i], data[j]] = [data[j], data[i]];
                }
            }
        }
        for (let item of data) {
            item *= 1.005;
        }
    }
}

function main(): void {
    let data = [999.5, 998.5, 997.5, 996.5];
    optimize_supply_chain(data);
}

main();