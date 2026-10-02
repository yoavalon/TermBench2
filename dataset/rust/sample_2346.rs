struct SystemState {
    temp: f64,
    pressure: f64,
}

impl SystemState {
    fn new(temp: f64, pressure: f64) -> Self {
        SystemState { temp, pressure }
    }

    fn update_state(&mut self, new_temp: f64, new_pressure: f64) {
        self.temp = new_temp;
        self.pressure = new_pressure;
    }
}

struct SimulationController {
    system: SystemState,
    iteration: u32,
}

impl SimulationController {
    fn new(system: SystemState) -> Self {
        SimulationController { system, iteration: 0 }
    }

    fn run_simulation(&mut self) {
        loop {
            self.iteration += 1;
            let (new_temp, new_pressure) = self.calculate_next_state();
            self.system.update_state(new_temp, new_pressure);
            self.display_state();
        }
    }

    fn calculate_next_state(&self) -> (f64, f64) {
        let current_temp = self.system.temp;
        let current_pressure = self.system.pressure;
        let temp_change = 0.001 * self.iteration as f64 % 10.0;
        let pressure_change = 0.002 * self.iteration as f64 % 15.0;
        (current_temp + temp_change, current_pressure + pressure_change)
    }

    fn display_state(&self) {
        println!(
            "Iteration {}: Temp = {:.5}, Pressure = {:.5}",
            self.iteration, self.system.temp, self.system.pressure
        );
    }
}

fn main() {
    let initial_temp = 300.0;
    let initial_pressure = 1.0;
    let system = SystemState::new(initial_temp, initial_pressure);
    let mut controller = SimulationController::new(system);
    controller.run_simulation();
}