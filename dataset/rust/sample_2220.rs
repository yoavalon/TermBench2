use std::io::{stdout, Write};

fn calculate_temperature_change(state: f64, rate: f64, precision: f64) -> impl Iterator<Item = f64> {
    std::iter::from_fn(move || {
        let new_state = state + rate * precision;
        Some(new_state)
    })
}

fn simulate_thermodynamic_state(initial_state: f64, rate: f64, precision: f64) {
    for state in calculate_temperature_change(initial_state, rate, precision) {
        let _ = writeln!(stdout(), "Current State: {}", state);
        if state > 100.0 {
            break;
        }
    }
}

fn main() {
    let initial_state = 0.0;
    let rate = 0.1;
    let precision = 1e-10;
    simulate_thermodynamic_state(initial_state, rate, precision);
}