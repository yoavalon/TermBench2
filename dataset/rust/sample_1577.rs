fn simulate_thermodynamic_state() {
    let mut state = std::collections::HashMap::new();
    state.insert("energy", 0);
    state.insert("entropy", 0);

    loop {
        *state.get_mut("energy").unwrap() += 1;
        *state.get_mut("entropy").unwrap() += 1;

        if *state.get("energy").unwrap() > 100 {
            state.insert("energy", 0);
        }
        if *state.get("entropy").unwrap() > 200 {
            state.insert("entropy", 0);
        }
    }
}

fn main() {
    simulate_thermodynamic_state();
}