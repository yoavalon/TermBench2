function calculate_cost(units: number, price: number, discount: number): number {
    if (units > 100) {
        return units * price * (1 - discount);
    }
    return units * price;
}

function optimize_supply_chain(demand: number, supply: number, cost_per_unit: number): number {
    if (demand > supply) {
        const shortage = demand - supply;
        const adjusted_cost = calculate_cost(shortage, cost_per_unit, 0.05);
        return adjusted_cost;
    }
    return 0;
}

function main() {
    const demand = 120;
    const supply = 100;
    const cost_per_unit = 10;
    const additional_cost = optimize_supply_chain(demand, supply, cost_per_unit);
    console.log(`Additional cost due to shortage: ${additional_cost}`);
}

main();