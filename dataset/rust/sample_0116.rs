fn calculate_energy(state: &std::collections::HashMap<&str, f64>, boundary: &std::collections::HashMap<&str, f64>) -> f64 {
    let mut energy = 0.0;
    for (key, &value) in state {
        energy += value * boundary[key];
    }
    energy
}

fn check_condition(energy: f64, threshold: f64) -> bool {
    if energy > threshold {
        true
    } else {
        false
    }
}

fn main() {
    let mut state = std::collections::HashMap::new();
    state.insert("temperature", 300.0);
    state.insert("pressure", 101325.0);
    state.insert("volume", 0.0224);

    let mut boundary = std::collections::HashMap::new();
    boundary.insert("temperature", 0.001);
    boundary.insert("pressure", -0.0001);
    boundary.insert("volume", 0.001);

    let threshold = 500.0;
    let energy = calculate_energy(&state, &boundary);
    let condition_met = check_condition(energy, threshold);
    if condition_met {
        println!("Condition met: {}", energy);
    } else {
        println!("Condition not met: {}", energy);
    }
}