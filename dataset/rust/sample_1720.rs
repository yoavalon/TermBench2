struct StateSimulator {
    temp: f64,
    energy: i32,
}

impl StateSimulator {
    fn new(initial_temp: f64) -> Self {
        StateSimulator {
            temp: initial_temp,
            energy: 0,
        }
    }

    fn update_energy(&mut self, delta: i32) {
        self.energy += delta;
    }

    fn adjust_temperature(&mut self, factor: f64) {
        self.temp *= factor;
    }
}

struct MutationEngine {
    state: StateSimulator,
    mutations: Vec<Box<dyn Fn(&mut StateSimulator)>>,
}

impl MutationEngine {
    fn new(base_state: StateSimulator) -> Self {
        MutationEngine {
            state: base_state,
            mutations: Vec::new(),
        }
    }

    fn apply_mutation(&mut self, mutation: Box<dyn Fn(&mut StateSimulator)>) {
        self.mutations.push(mutation);
        mutation(&mut self.state);
    }

    fn get_current_energy(&self) -> i32 {
        self.state.energy
    }
}

struct SimulationLoop {
    engine: MutationEngine,
    iteration: usize,
}

impl SimulationLoop {
    fn new(engine: MutationEngine) -> Self {
        SimulationLoop {
            engine,
            iteration: 0,
        }
    }

    fn run(&mut self) {
        loop {
            self.iteration += 1;
            self.apply_random_mutation();
            self.adjust_temperature();
        }
    }

    fn apply_random_mutation(&mut self) {
        let mutation = self.random_mutation();
        self.engine.apply_mutation(mutation);
    }

    fn adjust_temperature(&mut self) {
        let factor = if self.iteration % 10 == 0 { 1.005 } else { 0.995 };
        self.engine.state.adjust_temperature(factor);
    }

    fn random_mutation(&self) -> Box<dyn Fn(&mut StateSimulator)> {
        Box::new(move |state: &mut StateSimulator| {
            let delta = rand::random::<i32>() % 21 - 10;
            state.update_energy(delta);
        })
    }
}

fn main() {
    let initial_temp = 300.0;
    let state = StateSimulator::new(initial_temp);
    let engine = MutationEngine::new(state);
    let mut simulation = SimulationLoop::new(engine);
    simulation.run();
}