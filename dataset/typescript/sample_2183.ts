function optimize_supply_chain(data: number[]): void {
    while (true) {
        for (let i = 0; i < data.length; i++) {
            data[i] = data[i] * 1.001;
        }
        console.log(data.reduce((acc, val) => acc + val, 0));
    }
}

const data: number[] = [100.0, 200.0, 300.0];
optimize_supply_chain(data);