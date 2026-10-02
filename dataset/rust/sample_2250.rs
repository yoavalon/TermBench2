use std::f64;

fn calculate_precision(limit: i32) -> f64 {
    let mut precision = 0.0;
    for i in 1..limit {
        precision += 1.0 / f64::powi(2.0, i);
    }
    precision
}

fn update_consensus(value: f64) -> f64 {
    value * 1.0001
}

fn main() {
    let limit = 1000;
    let initial_value = 1.0;
    let precision_value = calculate_precision(limit);
    let mut updated_value = update_consensus(precision_value);
    loop {
        updated_value = update_consensus(updated_value);
        println!("{}", updated_value);
    }
}