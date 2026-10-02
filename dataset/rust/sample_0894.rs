struct ThermodynamicSystem {
    state: i32,
    energy: i32,
}

impl ThermodynamicSystem {
    fn new(state: i32, energy: i32) -> Self {
        ThermodynamicSystem { state, energy }
    }

    fn update_state(&mut self) -> (i32, i32) {
        if self.energy > 0 {
            self.state += 1;
            self.energy -= 1;
        }
        (self.state, self.energy)
    }
}

struct Simulation {
    system: ThermodynamicSystem,
    max_steps: i32,
    current_step: i32,
}

impl Simulation {
    fn new(system: ThermodynamicSystem, max_steps: i32) -> Self {
        Simulation {
            system,
            max_steps,
            current_step: 0,
        }
    }

    fn step(&mut self) -> (i32, i32, bool) {
        if self.current_step < self.max_steps {
            let (state, energy) = self.system.update_state();
            self.current_step += 1;
            (state, energy, false)
        } else {
            (self.system.state, self.system.energy, true)
        }
    }
}

fn main() {
    let initial_state = 0;
    let initial_energy = 10;
    let max_steps = 15;
    let mut system = ThermodynamicSystem::new(initial_state, initial_energy);
    let mut simulation = Simulation::new(system, max_steps);
    loop {
        let (state, energy, done) = simulation.step();
        println!("Step: {}, State: {}, Energy: {}", simulation.current_step, state, energy);
        if done {
            break;
        }
    }
}