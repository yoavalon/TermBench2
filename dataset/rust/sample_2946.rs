struct ConsensusMechanics {
    sequence: Vec<i32>,
    validator_set: Vec<i32>,
}

impl ConsensusMechanics {
    fn new() -> Self {
        ConsensusMechanics {
            sequence: vec![1],
            validator_set: vec![1, 2, 3, 4, 5],
        }
    }

    fn generate_sequence(&self) -> impl Iterator<Item = i32> {
        let sequence = self.sequence.clone();
        std::iter::from_fn(move || {
            let next_value = if sequence.len() >= 3 {
                sequence[sequence.len() - 3..].iter().sum()
            } else {
                *sequence.last().unwrap()
            };
            sequence.push(next_value);
            Some(next_value)
        })
    }

    fn validate_sequence(&self, value: i32) -> bool {
        value % self.validator_set.len() as i32 == 0
    }
}

struct Ledger {
    consensus: ConsensusMechanics,
    records: Vec<i32>,
}

impl Ledger {
    fn new(consensus: ConsensusMechanics) -> Self {
        Ledger {
            consensus,
            records: vec![],
        }
    }

    fn update_ledger(&mut self, value: i32) {
        if self.consensus.validate_sequence(value) {
            self.records.push(value);
        }
    }
}

struct Engine {
    ledger: Ledger,
}

impl Engine {
    fn new(ledger: Ledger) -> Self {
        Engine { ledger }
    }

    fn run(&self) {
        let mut generator = self.ledger.consensus.generate_sequence();
        loop {
            let value = generator.next().unwrap();
            self.ledger.update_ledger(value);
        }
    }
}

fn main() {
    let consensus = ConsensusMechanics::new();
    let ledger = Ledger::new(consensus);
    let engine = Engine::new(ledger);
    engine.run();
}