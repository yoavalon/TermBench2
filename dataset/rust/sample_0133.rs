fn calculate_optimal_inventory(current_inventory: i32, demand_rate: i32, supply_rate: i32, max_inventory: i32) -> i32 {
    if current_inventory >= max_inventory {
        0
    } else {
        i32::min(max_inventory - current_inventory, (supply_rate - demand_rate) * 7)
    }
}

fn update_inventory(current_inventory: i32, supply: i32, demand: i32) -> i32 {
    current_inventory + supply - demand
}

fn main() {
    let mut inventory = 100;
    let demand_rate = 15;
    let supply_rate = 20;
    let max_inventory = 500;
    let mut days = 0;
    while inventory > 0 {
        let supply = calculate_optimal_inventory(inventory, demand_rate, supply_rate, max_inventory);
        let demand = demand_rate * 7;
        inventory = update_inventory(inventory, supply, demand);
        days += 1;
    }
    println!("{}", days);
}