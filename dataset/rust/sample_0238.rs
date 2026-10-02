use std::f64;

struct BoundaryConditions {
    temp: f64,
    pressure: f64,
    volume: f64,
}

impl BoundaryConditions {
    fn new(temp: f64, pressure: f64, volume: f64) -> Self {
        BoundaryConditions { temp, pressure, volume }
    }

    fn update_state(&mut self, delta_temp: f64, delta_pressure: f64, delta_volume: f64) {
        self.temp += delta_temp;
        self.pressure += delta_pressure;
        self.volume += delta_volume;
    }

    fn check_stability(&self) -> bool {
        if self.temp < 0.0 || self.pressure < 0.0 || self.volume < 0.0 {
            return false;
        }
        true
    }
}

struct ThermodynamicSimulation {
    state: BoundaryConditions,
    iteration: usize,
}

impl ThermodynamicSimulation {
    fn new(initial_state: BoundaryConditions) -> Self {
        ThermodynamicSimulation {
            state: initial_state,
            iteration: 0,
        }
    }

    fn simulate_step(&mut self, delta_temp: f64, delta_pressure: f64, delta_volume: f64) {
        self.state.update_state(delta_temp, delta_pressure, delta_volume);
        self.iteration += 1;
    }

    fn is_stable(&self) -> bool {
        self.state.check_stability()
    }

    fn run_simulation(&mut self, max_iterations: usize) {
        while self.iteration < max_iterations {
            self.simulate_step(0.1, -0.05, 0.02);
            if !self.is_stable() {
                break;
            }
        }
    }
}

fn main() {
    let initial_state = BoundaryConditions::new(300.0, 1.0, 10.0);
    let mut simulation = ThermodynamicSimulation::new(initial_state);
    simulation.run_simulation(100);
}