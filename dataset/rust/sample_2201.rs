fn calculate_cost(quantity: f64, price_per_unit: f64) -> f64 {
    let total_cost = quantity * price_per_unit;
    total_cost
}

fn optimize_inventory(stock: f64, demand: f64, holding_cost: f64) -> f64 {
    let adjusted_stock = stock - demand;
    let total_holding_cost = adjusted_stock * holding_cost;
    total_holding_cost
}

fn main() {
    let q = 100.0;
    let p = 2.5;
    let s = 150.0;
    let d = 120.0;
    let h = 0.1;
    loop {
        let cost = calculate_cost(q, p);
        let holding = optimize_inventory(s, d, h);
        println!("Total Cost: {}, Total Holding Cost: {}", cost, holding);
    }
}