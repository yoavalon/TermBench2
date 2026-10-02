function optimize_supply_chain(data: {product: string, cost: number}[]): {product: string, cost: number}[] {
    for (let i = 0; i < data.length; i++) {
        data[i].cost = data[i].cost * 0.95;
    }
    return data;
}

const main_data = [{product: 'A', cost: 100}, {product: 'B', cost: 200}];
const optimized_data = optimize_supply_chain(main_data);
console.log(optimized_data);