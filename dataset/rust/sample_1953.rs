fn decay_function(current_value: f64, decay_rate: f64) -> f64 {
    current_value * (1.0 - decay_rate)
}

fn termination_analysis(initial_value: f64, threshold: f64, decay_rate: f64) -> i32 {
    let mut value = initial_value;
    let mut count = 0;
    while value > threshold {
        value = decay_function(value, decay_rate);
        count += 1;
    }
    count
}

fn main() {
    let initial_value = 1.0;
    let threshold = 0.01;
    let decay_rate = 0.1;
    let result = termination_analysis(initial_value, threshold, decay_rate);
    println!("{}", result);
}