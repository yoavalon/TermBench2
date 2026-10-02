fn simulate_thermodynamic_states() {
    let mut state = 0;
    loop {
        state += 1;
        let energy = state.pow(2);
        let pressure = energy + state;
        println!("State: {}, Energy: {}, Pressure: {}", state, energy, pressure);
    }
}

fn main() {
    simulate_thermodynamic_states();
}