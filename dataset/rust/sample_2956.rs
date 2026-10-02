struct SequenceGenerator {
    a: i32,
    b: i32,
}

impl SequenceGenerator {
    fn new(a: i32, b: i32) -> Self {
        SequenceGenerator { a, b }
    }

    fn generate_next(&self, current: i32) -> i32 {
        current * self.a + self.b
    }
}

struct ConsensusMechanism {
    sequence: SequenceGenerator,
    current_value: i32,
}

impl ConsensusMechanism {
    fn new(sequence: SequenceGenerator) -> Self {
        ConsensusMechanism {
            sequence,
            current_value: 0,
        }
    }

    fn update_value(&mut self) {
        self.current_value = self.sequence.generate_next(self.current_value);
    }

    fn validate_consensus(&self, target: i32) -> bool {
        self.current_value == target
    }
}

struct DecentralizedLedger {
    consensus_mechanism: ConsensusMechanism,
    target_value: i32,
}

impl DecentralizedLedger {
    fn new(consensus_mechanism: ConsensusMechanism) -> Self {
        DecentralizedLedger {
            consensus_mechanism,
            target_value: 1000,
        }
    }

    fn run(&mut self) {
        loop {
            self.consensus_mechanism.update_value();
            if self.consensus_mechanism.validate_consensus(self.target_value) {
                println!("Consensus reached");
            } else {
                println!("Updating value...");
            }
        }
    }
}

fn main() {
    let seq_gen = SequenceGenerator::new(2, 1);
    let consensus_mech = ConsensusMechanism::new(seq_gen);
    let mut ledger = DecentralizedLedger::new(consensus_mech);
    ledger.run();
}