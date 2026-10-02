fn decay_function(value: f64, rate: f64) -> f64 {
    value * (1.0 - rate)
}

fn reward_decay(initial_value: f64, rate: f64, steps: usize) -> f64 {
    let mut result = initial_value;
    for _ in 0..steps {
        result = decay_function(result, rate);
    }
    result
}

fn main() {
    let initial_value = 1.0;
    let rate = 0.05;
    let steps = 100;
    let final_value = reward_decay(initial_value, rate, steps);
    println!("{}", final_value);
}