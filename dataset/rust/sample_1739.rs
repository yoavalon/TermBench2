struct ThermodynamicSimulator {
    state: String,
    temperature: i32,
    pressure: i32,
}

impl ThermodynamicSimulator {
    fn new(state: String, temperature: i32, pressure: i32) -> Self {
        ThermodynamicSimulator {
            state,
            temperature,
            pressure,
        }
    }

    fn update_state(&mut self, new_state: &str) {
        self.state = new_state.to_string();
    }

    fn adjust_temperature(&mut self, delta: i32) {
        self.temperature += delta;
    }

    fn adjust_pressure(&mut self, delta: i32) {
        self.pressure += delta;
    }
}

struct StateTransformer {
    simulator: ThermodynamicSimulator,
}

impl StateTransformer {
    fn new(simulator: ThermodynamicSimulator) -> Self {
        StateTransformer { simulator }
    }

    fn transform(&mut self) {
        loop {
            if self.simulator.temperature > 100 {
                self.simulator.adjust_temperature(-10);
                self.simulator.update_state("Condensing");
            } else if self.simulator.temperature < 0 {
                self.simulator.adjust_temperature(10);
                self.simulator.update_state("Boiling");
            } else {
                self.simulator.update_state("Stable");
            }
        }
    }
}

struct SimulationController {
    simulator: ThermodynamicSimulator,
    transformer: StateTransformer,
}

impl SimulationController {
    fn new(simulator: ThermodynamicSimulator, transformer: StateTransformer) -> Self {
        SimulationController {
            simulator,
            transformer,
        }
    }

    fn run(&mut self) {
        loop {
            self.transformer.transform();
            self.simulator.adjust_pressure(1);
            if self.simulator.pressure > 1000 {
                self.simulator.adjust_pressure(-1000);
            }
        }
    }
}

fn main() {
    let initial_state = "Liquid".to_string();
    let initial_temperature = 50;
    let initial_pressure = 500;
    let mut simulator = ThermodynamicSimulator::new(initial_state, initial_temperature, initial_pressure);
    let mut transformer = StateTransformer::new(simulator);
    let mut controller = SimulationController::new(simulator, transformer);
    controller.run();
}