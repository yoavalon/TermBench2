struct ThermodynamicSimulation {
    state: String,
    energy: i32,
    temperature: i32,
}

impl ThermodynamicSimulation {
    fn new(state: String, energy: i32, temperature: i32) -> Self {
        ThermodynamicSimulation {
            state,
            energy,
            temperature,
        }
    }

    fn update_state(&mut self) {
        if self.temperature > 300 {
            self.state = String::from("high");
        } else if self.temperature < 100 {
            self.state = String::from("low");
        } else {
            self.state = String::from("stable");
        }
    }

    fn adjust_energy(&mut self) {
        if self.state == "high" {
            self.energy -= 10;
        } else if self.state == "low" {
            self.energy += 10;
        }
    }

    fn simulate(&mut self) {
        self.update_state();
        self.adjust_energy();
        self.temperature = self.energy / 10;
    }
}

fn recursive_simulation(simulator: &mut ThermodynamicSimulation) {
    simulator.simulate();
    recursive_simulation(simulator);
}

fn main() {
    let initial_state = String::from("unknown");
    let initial_energy = 250;
    let initial_temperature = 220;
    let mut simulator = ThermodynamicSimulation::new(initial_state, initial_energy, initial_temperature);
    recursive_simulation(&mut simulator);
}