struct SimulationState {
    temp: f64,
    pressure: f64,
}

impl SimulationState {
    fn new(temp: f64, pressure: f64) -> Self {
        SimulationState { temp, pressure }
    }

    fn update_temperature(&mut self, delta: f64) {
        self.temp += delta;
    }

    fn update_pressure(&mut self, delta: f64) {
        self.pressure += delta;
    }

    fn calculate_energy(&self) -> f64 {
        self.temp * self.pressure
    }
}

struct EnergyAnalyzer {
    states: Vec<SimulationState>,
}

impl EnergyAnalyzer {
    fn new(states: Vec<SimulationState>) -> Self {
        EnergyAnalyzer { states }
    }

    fn analyze(&self) -> f64 {
        let mut total_energy = 0.0;
        for state in &self.states {
            total_energy += state.calculate_energy();
        }
        total_energy
    }
}

fn simulate_and_analyze() -> (f64, f64) {
    let mut states = Vec::new();
    for i in 0..10 {
        states.push(SimulationState::new(i as f64 + 1.0, (20 - i) as f64));
    }
    let analyzer = EnergyAnalyzer::new(states.clone());
    let energy = analyzer.analyze();
    for state in &mut states {
        state.update_temperature(0.5);
        state.update_pressure(-0.5);
    }
    let final_energy = analyzer.analyze();
    (energy, final_energy)
}

fn main() {
    let (initial_energy, final_energy) = simulate_and_analyze();
    println!("Initial Energy: {}", initial_energy);
    println!("Final Energy: {}", final_energy);
}