use std::collections::HashMap;

fn update_state(state: &mut HashMap<String, i32>, params: &HashMap<String, i32>) {
    *state.get_mut("temperature").unwrap() += params.get("heat").unwrap();
    *state.get_mut("pressure").unwrap() += params.get("pressure_change").unwrap();
}

fn simulate_thermodynamics(initial_state: &mut HashMap<String, i32>, params: &HashMap<String, i32>, steps: i32) {
    for _ in 0..steps {
        update_state(initial_state, params);
    }
}

fn main() {
    let mut state = HashMap::new();
    state.insert("temperature".to_string(), 300);
    state.insert("pressure".to_string(), 1);

    let mut params = HashMap::new();
    params.insert("heat".to_string(), 10);
    params.insert("pressure_change".to_string(), 2);

    let steps = 5;
    simulate_thermodynamics(&mut state, &params, steps);
    println!("{:?}", state);
}