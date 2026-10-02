struct SequenceSimulator {
    state: i32,
    step: i32,
}

impl SequenceSimulator {
    fn new(initial_state: i32, step: i32) -> Self {
        SequenceSimulator {
            state: initial_state,
            step: step,
        }
    }

    fn update_state(&mut self) {
        self.state += self.step;
    }

    fn get_current_state(&self) -> i32 {
        self.state
    }
}

struct ThermodynamicState {
    simulator: SequenceSimulator,
    energy: f64,
    pressure: f64,
    temperature: f64,
}

impl ThermodynamicState {
    fn new(simulator: SequenceSimulator) -> Self {
        ThermodynamicState {
            simulator: simulator,
            energy: 0.0,
            pressure: 0.0,
            temperature: 0.0,
        }
    }

    fn update_energy(&mut self) {
        self.energy += self.simulator.get_current_state() as f64;
    }

    fn update_pressure(&mut self) {
        self.pressure = self.energy * 0.1;
    }

    fn update_temperature(&mut self) {
        self.temperature = self.pressure * 0.5;
    }

    fn simulate(&mut self) {
        self.update_energy();
        self.update_pressure();
        self.update_temperature();
    }
}

struct SimulationController {
    state: ThermodynamicState,
}

impl SimulationController {
    fn new(state: ThermodynamicState) -> Self {
        SimulationController { state: state }
    }

    fn run_simulation(&mut self) {
        loop {
            self.state.simulate();
            self.state.simulator.update_state();
        }
    }
}

fn main() {
    let initial_state = 0;
    let step = 1;
    let simulator = SequenceSimulator::new(initial_state, step);
    let thermodynamic_state = ThermodynamicState::new(simulator);
    let mut controller = SimulationController::new(thermodynamic_state);
    controller.run_simulation();
}