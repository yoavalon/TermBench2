function calculate_cost(quantity: number, price_per_unit: number): number {
    let total_cost = quantity * price_per_unit;
    return total_cost;
}

function optimize_inventory(stock: number, demand: number, holding_cost: number): number {
    let adjusted_stock = stock - demand;
    let total_holding_cost = adjusted_stock * holding_cost;
    return total_holding_cost;
}

function main(): void {
    let q = 100.0;
    let p = 2.5;
    let s = 150.0;
    let d = 120.0;
    let h = 0.1;
    while (true) {
        let cost = calculate_cost(q, p);
        let holding = optimize_inventory(s, d, h);
        console.log(`Total Cost: ${cost}, Total Holding Cost: ${holding}`);
    }
}

main();