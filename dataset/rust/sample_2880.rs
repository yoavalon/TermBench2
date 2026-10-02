use std::fmt::Write;

fn simulate_temp_change(initial_temp: f64, rate: f64, time_step: f64) -> impl Iterator<Item = f64> {
    let mut current_temp = initial_temp;
    std::iter::from_fn(move || {
        current_temp += rate * time_step;
        Some(current_temp)
    })
}

fn analyze_sequence(sequence: impl Iterator<Item = f64>) {
    for value in sequence {
        println!("Current Temperature: {:.2}K", value);
    }
}

fn main() {
    let initial_temp = 300.0;
    let rate = 0.01;
    let time_step = 1.0;
    let sequence = simulate_temp_change(initial_temp, rate, time_step);
    analyze_sequence(sequence);
}