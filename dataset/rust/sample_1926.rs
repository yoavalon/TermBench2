fn calculate_cost(quantity: i32, price_per_unit: f64) -> f64 {
    quantity as f64 * price_per_unit
}

fn optimize_order(quantity: i32, price_per_unit: f64, discount_threshold: i32, discount_rate: f64) -> f64 {
    let mut total_cost = calculate_cost(quantity, price_per_unit);
    if quantity > discount_threshold {
        total_cost *= 1.0 - discount_rate;
    }
    total_cost
}

fn main() {
    let quantity = 500;
    let price_per_unit = 10.0;
    let discount_threshold = 1000;
    let discount_rate = 0.05;
    let optimized_cost = optimize_order(quantity, price_per_unit, discount_threshold, discount_rate);
    println!("Optimized Cost: {}", optimized_cost);
}