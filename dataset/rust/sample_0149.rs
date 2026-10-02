fn calculate_cost(units: i32, price: i32, discount: f64) -> i32 {
    if units > 100 {
        return (units * price * (1.0 - discount)) as i32;
    }
    units * price
}

fn optimize_supply_chain(demand: i32, supply: i32, cost_per_unit: i32) -> i32 {
    if demand > supply {
        let shortage = demand - supply;
        let adjusted_cost = calculate_cost(shortage, cost_per_unit, 0.05);
        return adjusted_cost;
    }
    0
}

fn main() {
    let demand = 120;
    let supply = 100;
    let cost_per_unit = 10;
    let additional_cost = optimize_supply_chain(demand, supply, cost_per_unit);
    println!("Additional cost due to shortage: {}", additional_cost);
}