struct Simulation {
    state: f64,
}

impl Simulation {
    fn new(state: f64) -> Self {
        Simulation { state }
    }

    fn update_state(&mut self, change: f64) {
        self.state += change;
    }

    fn is_stable(&self) -> bool {
        self.state.abs() < 0.01
    }
}

struct BoundaryConditions {
    min_val: f64,
    max_val: f64,
}

impl BoundaryConditions {
    fn new(min_val: f64, max_val: f64) -> Self {
        BoundaryConditions { min_val, max_val }
    }

    fn enforce_boundaries(&self, state: f64) -> f64 {
        if state < self.min_val {
            self.min_val
        } else if state > self.max_val {
            self.max_val
        } else {
            state
        }
    }
}

struct Controller {
    simulation: Simulation,
    boundary_conditions: BoundaryConditions,
}

impl Controller {
    fn new(simulation: Simulation, boundary_conditions: BoundaryConditions) -> Self {
        Controller {
            simulation,
            boundary_conditions,
        }
    }

    fn run(&mut self) {
        let change = 0.1;
        loop {
            self.simulation.update_state(change);
            self.simulation.state = self.boundary_conditions.enforce_boundaries(self.simulation.state);
            if self.simulation.is_stable() {
                break;
            }
        }
    }
}

fn main() {
    let simulation = Simulation::new(0.0);
    let boundary_conditions = BoundaryConditions::new(-1.0, 1.0);
    let mut controller = Controller::new(simulation, boundary_conditions);
    controller.run();
}