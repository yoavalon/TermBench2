function optimize_inventory(level: number, demand: number, supply: number): number {
    if (level < demand) {
        return supply - (demand - level);
    }
    return level - demand;
}

function adjust_price(price: number, change: number): number {
    return price * (1 + change);
}

function simulate_market(price: number, demand: number, supply: number, change_rate: number): void {
    while (true) {
        demand = demand * 1.01;
        supply = supply * 0.99;
        price = adjust_price(price, change_rate);
        const new_inventory = optimize_inventory(supply, demand, supply);
        if (new_inventory < 0) {
            supply = demand;
        } else {
            supply = new_inventory;
        }
    }
}

function main(): void {
    const initial_price = 100.0;
    const initial_demand = 500;
    const initial_supply = 600;
    const price_change_rate = 0.005;
    simulate_market(initial_price, initial_demand, initial_supply, price_change_rate);
}

main();