use std::collections::HashMap;

fn compute_temperature_change(initial_temp: f64, final_temp: f64, rate: f64) -> f64 {
    (final_temp - initial_temp) * rate
}

fn update_state(state: &mut HashMap<String, f64>, change: f64) {
    state.insert("temperature".to_string(), state["temperature"] + change);
    state.insert("energy".to_string(), state["energy"] + change * 1000.0);
}

fn simulate_state(initial_temp: f64, final_temp: f64, rate: f64, steps: usize) -> HashMap<String, f64> {
    let mut state = HashMap::new();
    state.insert("temperature".to_string(), initial_temp);
    state.insert("energy".to_string(), 0.0);
    for _ in 0..steps {
        let change = compute_temperature_change(state["temperature"], final_temp, rate);
        update_state(&mut state, change);
    }
    state
}

fn main() {
    let initial_temp = 20.0;
    let final_temp = 100.0;
    let rate = 0.1;
    let steps = 10;
    let result = simulate_state(initial_temp, final_temp, rate, steps);
    println!("{:?}", result);
}