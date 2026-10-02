use rand::Rng;

fn initialize_state() -> std::collections::HashMap<&'static str, f64> {
    let mut state = std::collections::HashMap::new();
    let mut rng = rand::thread_rng();
    state.insert("temperature", rng.gen_range(200.0..300.0));
    state.insert("pressure", rng.gen_range(1.0..10.0));
    state
}

fn update_state(state: &mut std::collections::HashMap<&'static str, f64>) {
    let mut rng = rand::thread_rng();
    let temp_change = rng.gen_range(-10.0..10.0);
    let pressure_change = rng.gen_range(-1.0..1.0);
    *state.get_mut("temperature").unwrap() += temp_change;
    *state.get_mut("pressure").unwrap() += pressure_change;
}

fn check_conditions(state: &std::collections::HashMap<&'static str, f64>) -> bool {
    *state.get("temperature").unwrap() < 250.0 || *state.get("pressure").unwrap() > 8.0
}

fn simulate() -> std::collections::HashMap<&'static str, f64> {
    let mut state = initialize_state();
    while !check_conditions(&state) {
        update_state(&mut state);
    }
    state
}

fn main() {
    let result = simulate();
    println!("{:?}", result);
}