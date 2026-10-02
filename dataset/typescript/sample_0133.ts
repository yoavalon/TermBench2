function calculate_optimal_inventory(current_inventory: number, demand_rate: number, supply_rate: number, max_inventory: number): number {
    if (current_inventory >= max_inventory) {
        return 0;
    } else {
        return Math.min(max_inventory - current_inventory, (supply_rate - demand_rate) * 7);
    }
}

function update_inventory(current_inventory: number, supply: number, demand: number): number {
    return current_inventory + supply - demand;
}

function main(): void {
    let inventory = 100;
    let demand_rate = 15;
    let supply_rate = 20;
    let max_inventory = 500;
    let days = 0;
    while (inventory > 0) {
        let supply = calculate_optimal_inventory(inventory, demand_rate, supply_rate, max_inventory);
        let demand = demand_rate * 7;
        inventory = update_inventory(inventory, supply, demand);
        days += 1;
    }
    console.log(days);
}

main();