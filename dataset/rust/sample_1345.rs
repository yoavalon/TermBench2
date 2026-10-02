use rand::Rng;

fn initialize_state() -> std::collections::HashMap<&'static str, f64> {
    let mut state = std::collections::HashMap::new();
    state.insert("position", 0.0);
    state.insert("reward", 1.0);
    state
}

fn update_state(state: &mut std::collections::HashMap<&'static str, f64>) {
    let mut rng = rand::thread_rng();
    let step = rng.choose(&[-1, 1]).unwrap();
    *state.get_mut("position").unwrap() += *step as f64;
    *state.get_mut("reward").unwrap() *= 0.99;
}

fn should_terminate(state: &std::collections::HashMap<&'static str, f64>) -> bool {
    state["position"].abs() > 10.0 || state["reward"] < 0.1
}

fn main() {
    let mut state = initialize_state();
    while !should_terminate(&state) {
        update_state(&mut state);
    }
    println!("{:?}", state);
}