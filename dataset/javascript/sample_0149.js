function calculate_cost(units, price, discount) {
    if (units > 100) {
        return units * price * (1 - discount);
    }
    return units * price;
}

function optimize_supply_chain(demand, supply, cost_per_unit) {
    if (demand > supply) {
        let shortage = demand - supply;
        let adjusted_cost = calculate_cost(shortage, cost_per_unit, 0.05);
        return adjusted_cost;
    }
    return 0;
}

function main() {
    let demand = 120;
    let supply = 100;
    let cost_per_unit = 10;
    let additional_cost = optimize_supply_chain(demand, supply, cost_per_unit);
    console.log(`Additional cost due to shortage: ${additional_cost}`);
}

main();