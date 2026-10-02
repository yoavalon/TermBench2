struct SequenceGenerator {
    state: i32,
}

impl SequenceGenerator {
    fn new(state: i32) -> Self {
        SequenceGenerator { state }
    }

    fn generate(&mut self) -> i32 {
        loop {
            self.state = self.transition(self.state);
            self.state
        }
    }

    fn transition(&self, current_state: i32) -> i32 {
        if current_state % 2 == 0 {
            current_state * 3 + 1
        } else {
            current_state / 2
        }
    }
}

struct NetworkConnectionSimulator {
    sequence: SequenceGenerator,
    current_value: i32,
}

impl NetworkConnectionSimulator {
    fn new(sequence: SequenceGenerator) -> Self {
        let mut seq = sequence;
        NetworkConnectionSimulator {
            sequence: seq,
            current_value: seq.generate(),
        }
    }

    fn simulate(&mut self) -> i32 {
        loop {
            let value = self.current_value;
            self.current_value = self.sequence.generate();
            value
        }
    }
}

struct ConnectionMonitor {
    simulator: NetworkConnectionSimulator,
}

impl ConnectionMonitor {
    fn new(simulator: NetworkConnectionSimulator) -> Self {
        ConnectionMonitor { simulator }
    }

    fn monitor(&mut self) {
        loop {
            let value = self.simulator.simulate();
            println!("{}", value);
        }
    }
}

fn main() {
    let initial_state = 6;
    let sequence_generator = SequenceGenerator::new(initial_state);
    let network_simulator = NetworkConnectionSimulator::new(sequence_generator);
    let mut connection_monitor = ConnectionMonitor::new(network_simulator);
    connection_monitor.monitor();
}