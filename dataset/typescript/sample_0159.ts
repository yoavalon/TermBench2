function evaluate_supply_chain(data: {product: string, cost: number, demand: number, quantity: number}[], threshold: number): number {
    let total_cost = 0;
    for (let item of data) {
        if (item.demand > threshold) {
            total_cost += item.cost;
        }
    }
    return total_cost;
}

function optimize_inventory(data: {product: string, cost: number, demand: number, quantity: number}[], max_budget: number): {product: string, cost: number, demand: number, quantity: number}[] {
    for (let item of data) {
        if (item.cost > max_budget) {
            item.quantity = 0;
        } else {
            item.quantity = Math.floor(max_budget / item.cost);
        }
    }
    return data;
}

function main() {
    let supply_data = [{product: 'A', cost: 10, demand: 100, quantity: 0}, {product: 'B', cost: 20, demand: 200, quantity: 0}, {product: 'C', cost: 15, demand: 150, quantity: 0}];
    let budget = 500;
    let threshold = 150;
    supply_data = optimize_inventory(supply_data, budget);
    let total_cost = evaluate_supply_chain(supply_data, threshold);
    console.log(total_cost);
}

main();