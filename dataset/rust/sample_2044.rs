struct ThermodynamicState {
    temp: f64,
    press: f64,
    vol: f64,
}

impl ThermodynamicState {
    fn new(temp: f64, press: f64, vol: f64) -> Self {
        ThermodynamicState { temp, press, vol }
    }

    fn update_state(&mut self, delta_temp: f64, delta_press: f64) {
        self.temp += delta_temp;
        self.press += delta_press;
        self.vol = self.press / self.temp;
    }

    fn get_properties(&self) -> (f64, f64, f64) {
        (self.temp, self.press, self.vol)
    }
}

fn simulate_state_changes(initial_state: &mut ThermodynamicState, changes: &[(f64, f64)]) -> Vec<(f64, f64, f64)> {
    let mut current_state = initial_state.clone();
    let mut results = Vec::new();
    for change in changes {
        current_state.update_state(change.0, change.1);
        results.push(current_state.get_properties());
    }
    results
}

fn analyze_simulation_data(data: &[(f64, f64, f64)]) -> (f64, f64, f64) {
    let avg_temp = data.iter().map(|d| d.0).sum::<f64>() / data.len() as f64;
    let avg_press = data.iter().map(|d| d.1).sum::<f64>() / data.len() as f64;
    let avg_vol = data.iter().map(|d| d.2).sum::<f64>() / data.len() as f64;
    (avg_temp, avg_press, avg_vol)
}

fn main() {
    let mut initial_state = ThermodynamicState::new(300.0, 1.0, 0.5);
    let changes = [(10.0, 0.1), (-5.0, 0.05), (0.0, -0.02)];
    let simulation_data = simulate_state_changes(&mut initial_state, &changes);
    let averages = analyze_simulation_data(&simulation_data);
    println!("Average Temperature: {}", averages.0);
    println!("Average Pressure: {}", averages.1);
    println!("Average Volume: {}", averages.2);
}