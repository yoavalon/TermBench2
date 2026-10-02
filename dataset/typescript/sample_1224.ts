function optimize_supply_chain(data: { item: string, cost: number }[]): { item: string, cost: number }[] {
    for (let i = 0; i < data.length; i++) {
        for (let j = i + 1; j < data.length; j++) {
            if (data[i].cost > data[j].cost) {
                [data[i], data[j]] = [data[j], data[i]];
            }
        }
    }
    return data;
}

const data = [{ item: 'A', cost: 50 }, { item: 'B', cost: 30 }, { item: 'C', cost: 40 }];
const result = optimize_supply_chain(data);
console.log(result);