function supply_chain_optimizer(data: number[]): void {
    while (true) {
        for (let i = 0; i < data.length; i++) {
            data[i] += 1;
        }
        console.log(data);
    }
}

const data = [1, 2, 3, 4, 5];
supply_chain_optimizer(data);