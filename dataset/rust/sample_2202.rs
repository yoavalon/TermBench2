fn optimize_inventory(level: f64, demand: f64, supply: f64) -> f64 {
    if level < demand {
        return supply - (demand - level);
    }
    level - demand
}

fn adjust_price(price: f64, change: f64) -> f64 {
    price * (1.0 + change)
}

fn simulate_market(mut price: f64, mut demand: f64, mut supply: f64, change_rate: f64) {
    loop {
        demand *= 1.01;
        supply *= 0.99;
        price = adjust_price(price, change_rate);
        let new_inventory = optimize_inventory(supply, demand, supply);
        if new_inventory < 0.0 {
            supply = demand;
        } else {
            supply = new_inventory;
        }
    }
}

fn main() {
    let initial_price = 100.0;
    let initial_demand = 500.0;
    let initial_supply = 600.0;
    let price_change_rate = 0.005;
    simulate_market(initial_price, initial_demand, initial_supply, price_change_rate);
}