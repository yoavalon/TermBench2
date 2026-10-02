fn initialize_system() -> std::collections::HashMap<&'static str, f64> {
    let mut state = std::collections::HashMap::new();
    state.insert("temperature", 300.0);
    state.insert("pressure", 1.0);
    state.insert("energy", 500.0);
    state
}

fn update_state(state: &mut std::collections::HashMap<&'static str, f64>, time_step: f64) {
    *state.get_mut("temperature").unwrap() += 0.1 * time_step;
    *state.get_mut("pressure").unwrap() += 0.01 * time_step;
    *state.get_mut("energy").unwrap() -= 10.0 * time_step;
}

fn check_termination(state: &std::collections::HashMap<&'static str, f64>) -> bool {
    *state.get("energy").unwrap() <= 0.0
}

fn simulate() -> std::collections::HashMap<&'static str, f64> {
    let mut state = initialize_system();
    let time_step = 1.0;
    while !check_termination(&state) {
        update_state(&mut state, time_step);
    }
    state
}

fn main() {
    let final_state = simulate();
    println!("{:?}", final_state);
}