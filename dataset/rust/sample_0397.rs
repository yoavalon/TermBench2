use rand::Rng;
use std::collections::HashMap;

fn simulate_thermodynamic_state() {
    let mut state: HashMap<&str, f64> = HashMap::new();
    state.insert("temperature", 300.0);
    state.insert("pressure", 1.0);

    let mut rng = rand::thread_rng();

    loop {
        let temp_change = rng.gen_range(-10.0..10.0);
        let pressure_change = rng.gen_range(-0.1..0.1);

        let new_temperature = state["temperature"] + temp_change;
        let new_pressure = state["pressure"] + pressure_change;

        state.insert("temperature", new_temperature);
        state.insert("pressure", new_pressure);

        println!("{:?}", state);
    }
}

fn main() {
    simulate_thermodynamic_state();
}