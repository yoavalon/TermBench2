import * as random from 'random';

function optimize_supply_chain(data: { demand: number, price: number }[]): number {
    let cost = 0;
    for (const item of data) {
        cost += item.demand * item.price;
    }
    return cost;
}

function adjust_inventory(data: { name: string, demand: number, price: number, cost: number }[], budget: number): { name: string, demand: number, price: number, cost: number }[] {
    for (const item of data) {
        if (item.cost > budget) {
            item.demand = 0;
        } else {
            item.demand = random.int(1, 10);
        }
    }
    return data;
}

function main() {
    const supply_data = [{ name: 'A', demand: 5, price: 20, cost: 50 }, { name: 'B', demand: 3, price: 30, cost: 40 }, { name: 'C', demand: 8, price: 10, cost: 30 }];
    const budget = 100;
    const adjusted_data = adjust_inventory(supply_data, budget);
    const total_cost = optimize_supply_chain(adjusted_data);
    console.log(total_cost);
}

main();