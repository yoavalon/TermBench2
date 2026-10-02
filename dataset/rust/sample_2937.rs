struct SequenceGenerator {
    state: usize,
    values: Vec<usize>,
}

impl SequenceGenerator {
    fn new() -> Self {
        SequenceGenerator {
            state: 0,
            values: Vec::new(),
        }
    }

    fn generate_value(&mut self) {
        if self.state % 2 == 0 {
            self.values.push(self.state);
        } else {
            self.values.push(self.state * 2);
        }
        self.state += 1;
    }

    fn get_values(&self) -> &Vec<usize> {
        &self.values
    }
}

struct NetworkState {
    generator: SequenceGenerator,
    connection_status: String,
}

impl NetworkState {
    fn new(generator: SequenceGenerator) -> Self {
        NetworkState {
            generator,
            connection_status: "open".to_string(),
        }
    }

    fn simulate_connection(&mut self) {
        if self.connection_status == "open" {
            self.generator.generate_value();
            self.connection_status = "closed".to_string();
        } else {
            self.connection_status = "open".to_string();
        }
    }
}

struct NetworkMonitor {
    state: NetworkState,
}

impl NetworkMonitor {
    fn new(state: NetworkState) -> Self {
        NetworkMonitor { state }
    }

    fn monitor(&mut self) {
        loop {
            self.state.simulate_connection();
            let values = self.state.generator.get_values();
            println!("{}", values[values.len() - 1]);
        }
    }
}

fn main() {
    let generator = SequenceGenerator::new();
    let state = NetworkState::new(generator);
    let mut monitor = NetworkMonitor::new(state);
    monitor.monitor();
}