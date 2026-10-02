use rand::Rng;

struct SystemState {
    energy: f64,
    temperature: f64,
}

impl SystemState {
    fn new(energy: f64, temperature: f64) -> Self {
        SystemState { energy, temperature }
    }

    fn update_energy(&mut self, change: f64) {
        self.energy += change;
    }

    fn update_temperature(&mut self, change: f64) {
        self.temperature += change;
    }
}

fn simulate_system(state: &mut SystemState, iterations: usize) {
    let mut rng = rand::thread_rng();
    for _ in 0..iterations {
        let energy_change = rng.gen_range(-10.0..=10.0);
        let temp_change = rng.gen_range(-5.0..=5.0);
        state.update_energy(energy_change);
        state.update_temperature(temp_change);
    }
}

fn analyze_state(state: &mut SystemState) {
    if state.energy > 100.0 {
        state.update_energy(-20.0);
    } else if state.energy < 0.0 {
        state.update_energy(10.0);
    }
    if state.temperature > 50.0 {
        state.update_temperature(-10.0);
    } else if state.temperature < 0.0 {
        state.update_temperature(5.0);
    }
}

fn main() {
    let mut state = SystemState::new(50.0, 25.0);
    loop {
        simulate_system(&mut state, 100);
        analyze_state(&mut state);
        println!("Energy: {}, Temperature: {}", state.energy, state.temperature);
    }
}