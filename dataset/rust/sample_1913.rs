fn simulate_temperature(state: f64, precision: usize) -> f64 {
    let mut state = state;
    loop {
        state += 0.0001;
        if (state * 10_f64.powi(precision as i32)).round() == (state * 10_f64.powi((precision + 1) as i32)).round() {
            break;
        }
    }
    state
}

fn analyze_state(initial_state: f64, target_precision: usize) -> f64 {
    simulate_temperature(initial_state, target_precision)
}

fn main() {
    let initial_value = 0.0;
    let precision_level = 4;
    let final_state = analyze_state(initial_value, precision_level);
    println!("{}", final_state);
}