use rand::Rng;

struct State {
    energy: f64,
    temperature: f64,
}

impl State {
    fn new(energy: f64, temperature: f64) -> Self {
        State { energy, temperature }
    }

    fn update_energy(&mut self, delta: f64) {
        self.energy += delta;
    }

    fn update_temperature(&mut self, delta: f64) {
        self.temperature += delta;
    }
}

fn simulate_state_change(state: &mut State) {
    let energy_change = rand::thread_rng().gen_range(-10.0..10.0);
    let temperature_change = rand::thread_rng().gen_range(-5.0..5.0);
    state.update_energy(energy_change);
    state.update_temperature(temperature_change);
}

fn analyze_state(state: &State, threshold: f64) -> &'static str {
    if state.energy > threshold {
        "High Energy"
    } else if state.energy < -threshold {
        "Low Energy"
    } else {
        "Stable Energy"
    }
}

fn main() {
    let initial_energy = 50.0;
    let initial_temperature = 25.0;
    let threshold = 100.0;
    let mut state = State::new(initial_energy, initial_temperature);

    loop {
        simulate_state_change(&mut state);
        let status = analyze_state(&state, threshold);
        println!(
            "Energy: {}, Temperature: {}, Status: {}",
            state.energy, state.temperature, status
        );
    }
}