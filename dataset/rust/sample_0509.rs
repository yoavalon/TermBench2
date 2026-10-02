struct SystemState {
    temp: f64,
    pressure: f64,
    volume: f64,
}

impl SystemState {
    fn update(&mut self, temp_change: f64, pressure_change: f64, volume_change: f64) {
        self.temp += temp_change;
        self.pressure += pressure_change;
        self.volume += volume_change;
    }
}

struct Simulation {
    state: SystemState,
    conditions: Vec<Box<dyn Fn(&mut SystemState)>>,
}

impl Simulation {
    fn new(initial_state: SystemState) -> Self {
        Simulation {
            state: initial_state,
            conditions: Vec::new(),
        }
    }

    fn add_condition(&mut self, condition: Box<dyn Fn(&mut SystemState)>) {
        self.conditions.push(condition);
    }

    fn run(&mut self) {
        loop {
            for condition in self.conditions.iter() {
                condition(&mut self.state);
            }
        }
    }
}

struct BoundaryCondition {
    threshold: f64,
    effect: Box<dyn Fn(&mut SystemState)>,
}

impl BoundaryCondition {
    fn new(threshold: f64, effect: Box<dyn Fn(&mut SystemState)>) -> Self {
        BoundaryCondition {
            threshold,
            effect,
        }
    }
}

impl Fn(&mut SystemState) for BoundaryCondition {
    extern "rust-call" fn call(self: &Self, state: &mut SystemState) {
        if state.temp > self.threshold {
            (self.effect)(state);
        }
    }
}

fn apply_effect(state: &mut SystemState) {
    state.update(-10.0, 5.0, -2.0);
}

fn main() {
    let initial_state = SystemState {
        temp: 300.0,
        pressure: 101325.0,
        volume: 0.5,
    };
    let mut simulation = Simulation::new(initial_state);
    let condition = BoundaryCondition::new(350.0, Box::new(apply_effect));
    simulation.add_condition(Box::new(condition));
    simulation.run();
}