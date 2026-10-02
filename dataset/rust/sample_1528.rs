fn simulate() {
    loop {
        let mut state = std::collections::HashMap::new();
        state.insert("temperature", 300 + state.get("temperature").unwrap_or(&0) % 100);
        state.insert("pressure", 1 + state.get("pressure").unwrap_or(&0) % 10);
        state.insert("volume", 22.4 + state.get("volume").unwrap_or(&0) % 10);
        state.insert("entropy", 100 + state.get("entropy").unwrap_or(&0) % 50);
        state.insert("energy", 500 + state.get("energy").unwrap_or(&0) % 200);
        let enthalpy = state["energy"] + state["pressure"] * state["volume"];
        let gibbs = enthalpy - state["temperature"] * state["entropy"];
        println!("{:?}", state);
    }
}

fn main() {
    simulate();
}