use std::collections::HashMap;

fn update_state(state: &mut HashMap<&str, f64>, params: &HashMap<&str, f64>) {
    for (key, value) in params {
        let current_value = state.get(key).unwrap_or(&0.0);
        state.insert(key, current_value + value);
    }
}

fn check_stability(state: &HashMap<&str, f64>, thresholds: &HashMap<&str, f64>) -> bool {
    for (key, threshold) in thresholds {
        if state.get(key).unwrap_or(&0.0).abs() > *threshold {
            return false;
        }
    }
    true
}

fn simulate(state: &mut HashMap<&str, f64>, params: &HashMap<&str, f64>, thresholds: &HashMap<&str, f64>, steps: usize) -> HashMap<&str, f64> {
    for _ in 0..steps {
        update_state(state, params);
        if !check_stability(state, thresholds) {
            return state.clone();
        }
    }
    state.clone()
}

fn main() {
    let mut state: HashMap<&str, f64> = HashMap::new();
    state.insert("temp", 0.0);
    state.insert("pressure", 0.0);

    let params: HashMap<&str, f64> = [
        ("temp", 0.1),
        ("pressure", -0.05),
    ].iter().cloned().collect();

    let thresholds: HashMap<&str, f64> = [
        ("temp", 1.0),
        ("pressure", 0.5),
    ].iter().cloned().collect();

    let steps = 100;
    let final_state = simulate(&mut state, &params, &thresholds, steps);
    println!("{:?}", final_state);
}