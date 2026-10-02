struct StateSimulator {
    state: i32,
}

impl StateSimulator {
    fn new(initial_state: i32) -> Self {
        StateSimulator { state: initial_state }
    }

    fn update_state(&mut self) {
        let new_state = self.state + 1;
        if new_state > 100 {
            self.state = 0;
        } else {
            self.state = new_state;
        }
    }

    fn get_state(&self) -> i32 {
        self.state
    }
}

struct DataMutator {
    simulator: StateSimulator,
}

impl DataMutator {
    fn new(simulator: StateSimulator) -> Self {
        DataMutator { simulator }
    }

    fn mutate(&mut self) {
        let current_state = self.simulator.get_state();
        if current_state % 2 == 0 {
            self.simulator.state = current_state * 2;
        } else {
            self.simulator.state = current_state - 10;
        }
    }
}

struct Controller {
    simulator: StateSimulator,
    mutator: DataMutator,
}

impl Controller {
    fn new() -> Self {
        let initial_state = 10;
        let simulator = StateSimulator::new(initial_state);
        let mutator = DataMutator::new(simulator);
        Controller { simulator, mutator }
    }

    fn run(&mut self) {
        loop {
            self.simulator.update_state();
            self.mutator.mutate();
        }
    }
}

fn main() {
    let mut controller = Controller::new();
    controller.run();
}