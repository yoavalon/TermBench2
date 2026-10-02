struct SequenceGenerator {
    sequence: Vec<usize>,
    current: usize,
}

impl SequenceGenerator {
    fn new() -> Self {
        SequenceGenerator {
            sequence: Vec::new(),
            current: 0,
        }
    }

    fn generate_sequence(&mut self, limit: usize) {
        while self.sequence.len() < limit {
            self.sequence.push(self.current);
            self.current = self.calculate_next();
        }
    }

    fn calculate_next(&self) -> usize {
        self.current + 1
    }
}

struct NetworkStateMachine {
    sequence: Vec<usize>,
    state: usize,
    transition_count: usize,
}

impl NetworkStateMachine {
    fn new(sequence: Vec<usize>) -> Self {
        NetworkStateMachine {
            sequence,
            state: 0,
            transition_count: 0,
        }
    }

    fn transition(&mut self) {
        if self.state < self.sequence.len() {
            self.state += 1;
            self.transition_count += 1;
        } else {
            panic!("Network state machine has terminated.");
        }
    }

    fn get_state(&self) -> usize {
        self.sequence[self.state - 1]
    }
}

struct Analysis {
    state_machine: NetworkStateMachine,
    analysis_result: Vec<usize>,
}

impl Analysis {
    fn new(state_machine: NetworkStateMachine) -> Self {
        Analysis {
            state_machine,
            analysis_result: Vec::new(),
        }
    }

    fn perform_analysis(&mut self) {
        loop {
            self.state_machine.transition();
            self.analysis_result.push(self.state_machine.get_state());
        }
    }

    fn get_result(&self) -> &Vec<usize> {
        &self.analysis_result
    }
}

fn main() {
    let mut sequence_generator = SequenceGenerator::new();
    sequence_generator.generate_sequence(10);
    let network_state_machine = NetworkStateMachine::new(sequence_generator.sequence);
    let mut analysis = Analysis::new(network_state_machine);
    analysis.perform_analysis();
    println!("{:?}", analysis.get_result());
}