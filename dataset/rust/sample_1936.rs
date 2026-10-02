fn decay_function(value: f64, rate: f64, precision: usize) -> f64 {
    (value * (1.0 - rate)).round() / 10f64.powi(precision as i32)
}

fn simulate_decay(initial_value: f64, decay_rate: f64, precision: usize, steps: usize) -> Vec<f64> {
    let mut values = vec![initial_value];
    for _ in 0..steps {
        let current_value = *values.last().unwrap();
        let new_value = decay_function(current_value, decay_rate, precision);
        values.push(new_value);
    }
    values
}

fn main() {
    let initial_value = 1.0;
    let decay_rate = 0.1;
    let precision = 4;
    let steps = 10;
    let result = simulate_decay(initial_value, decay_rate, precision, steps);
    println!("{:?}", result);
}