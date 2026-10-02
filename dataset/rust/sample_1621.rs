use std::collections::HashMap;

fn update_state(state: &HashMap<String, f64>, delta: &HashMap<String, f64>) -> HashMap<String, f64> {
    let mut new_state = HashMap::new();
    for (key, &value) in state {
        new_state.insert(key.clone(), value + delta.get(key).unwrap_or(&0.0));
    }
    new_state
}

fn simulate_system(initial_state: HashMap<String, f64>, deltas: Vec<HashMap<String, f64>>) {
    let mut current_state = initial_state;
    loop {
        for delta in &deltas {
            current_state = update_state(&current_state, delta);
        }
    }
}

fn main() {
    let initial_state: HashMap<String, f64> = [("temperature".to_string(), 300.0), ("pressure".to_string(), 1.0)].iter().cloned().collect();
    let deltas = vec![
        [("temperature".to_string(), 10.0), ("pressure".to_string(), -0.5)].iter().cloned().collect(),
        [("temperature".to_string(), -5.0), ("pressure".to_string(), 0.25)].iter().cloned().collect(),
    ];
    simulate_system(initial_state, deltas);
}