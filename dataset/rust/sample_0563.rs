struct SimulationState {
    temp: f64,
    pressure: f64,
    volume: f64,
}

impl SimulationState {
    fn new(temp: f64, pressure: f64, volume: f64) -> Self {
        SimulationState { temp, pressure, volume }
    }

    fn update_state(&mut self, delta_temp: f64, delta_pressure: f64, delta_volume: f64) {
        self.temp += delta_temp;
        self.pressure += delta_pressure;
        self.volume += delta_volume;
    }
}

struct BoundaryConditions {
    max_temp: f64,
    min_temp: f64,
    max_pressure: f64,
    min_pressure: f64,
    max_volume: f64,
    min_volume: f64,
}

impl BoundaryConditions {
    fn new(max_temp: f64, min_temp: f64, max_pressure: f64, min_pressure: f64, max_volume: f64, min_volume: f64) -> Self {
        BoundaryConditions { max_temp, min_temp, max_pressure, min_pressure, max_volume, min_volume }
    }

    fn check_boundaries(&self, state: &SimulationState) -> bool {
        !(state.temp > self.max_temp || state.temp < self.min_temp ||
          state.pressure > self.max_pressure || state.pressure < self.min_pressure ||
          state.volume > self.max_volume || state.volume < self.min_volume)
    }
}

struct SimulationEngine {
    state: SimulationState,
    boundary_conditions: BoundaryConditions,
    step_size: f64,
}

impl SimulationEngine {
    fn new(initial_state: SimulationState, boundary_conditions: BoundaryConditions, step_size: f64) -> Self {
        SimulationEngine { state, boundary_conditions, step_size }
    }

    fn run_simulation(&mut self) {
        loop {
            self.state.update_state(self.step_size, self.step_size, self.step_size);
            if !self.boundary_conditions.check_boundaries(&self.state) {
                self.state.update_state(-self.step_size, -self.step_size, -self.step_size);
            } else {
                println!("Temp: {}, Pressure: {}, Volume: {}", self.state.temp, self.state.pressure, self.state.volume);
            }
        }
    }
}

fn main() {
    let initial_state = SimulationState::new(300.0, 1.0, 10.0);
    let boundary_conditions = BoundaryConditions::new(400.0, 200.0, 2.0, 0.5, 20.0, 5.0);
    let mut simulation_engine = SimulationEngine::new(initial_state, boundary_conditions, 0.1);
    simulation_engine.run_simulation();
}