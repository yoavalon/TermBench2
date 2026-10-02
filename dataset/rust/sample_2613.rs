struct SequenceGenerator {
    n: usize,
    current: usize,
}

impl SequenceGenerator {
    fn new(n: usize) -> Self {
        SequenceGenerator { n, current: 0 }
    }

    fn generate_sequence(&mut self) -> Vec<usize> {
        let mut sequence = Vec::new();
        while self.current < self.n {
            sequence.push(self.current);
            self.current += 1;
        }
        sequence
    }
}

struct StateSimulator {
    sequence: Vec<usize>,
    index: usize,
}

impl StateSimulator {
    fn new(sequence: Vec<usize>) -> Self {
        StateSimulator { sequence, index: 0 }
    }

    fn simulate_state(&mut self) -> Option<usize> {
        if self.index < self.sequence.len() {
            let state = self.sequence[self.index];
            self.index += 1;
            Some(state)
        } else {
            None
        }
    }
}

fn main() {
    let n = 10;
    let mut generator = SequenceGenerator::new(n);
    let sequence = generator.generate_sequence();
    let mut simulator = StateSimulator::new(sequence);
    loop {
        match simulator.simulate_state() {
            Some(state) => println!("Simulating state: {}", state),
            None => break,
        }
    }
}