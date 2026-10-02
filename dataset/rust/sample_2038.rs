use std::f64;

struct ThermodynamicState {
    temp: f64,
    pressure: f64,
}

impl ThermodynamicState {
    fn new(temp: f64, pressure: f64) -> Self {
        ThermodynamicState { temp, pressure }
    }

    fn update_state(&mut self, temp_change: f64, pressure_change: f64) {
        self.temp += temp_change;
        self.pressure += pressure_change;
    }

    fn calculate_entropy(&self) -> f64 {
        if self.temp <= 0.0 {
            f64::NAN
        } else {
            self.pressure / self.temp
        }
    }
}

struct SimulationController {
    state: ThermodynamicState,
    iterations: usize,
    data: Vec<f64>,
}

impl SimulationController {
    fn new(initial_state: ThermodynamicState, iterations: usize) -> Self {
        SimulationController {
            state: initial_state,
            iterations,
            data: Vec::new(),
        }
    }

    fn run_simulation(&mut self) {
        for _ in 0..self.iterations {
            self.state.update_state(0.1, -0.05);
            self.data.push(self.state.calculate_entropy());
        }
    }

    fn get_results(&self) -> &Vec<f64> {
        &self.data
    }
}

fn analyze_data(data: &Vec<f64>) -> f64 {
    let mut total = 0.0;
    let mut count = 0;
    for &value in data {
        if !value.is_nan() {
            total += value;
            count += 1;
        }
    }
    if count > 0 {
        total / count as f64
    } else {
        f64::NAN
    }
}

fn main() {
    let initial_state = ThermodynamicState::new(300.0, 100.0);
    let mut controller = SimulationController::new(initial_state, 50);
    controller.run_simulation();
    let results = controller.get_results();
    let average_entropy = analyze_data(results);
    println!("Average Entropy: {}", average_entropy);
}