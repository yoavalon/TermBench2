struct SequenceGenerator {
    value: u64,
}

impl SequenceGenerator {
    fn new(initial_value: u64) -> Self {
        SequenceGenerator { value: initial_value }
    }

    fn generate(&mut self) -> std::iter::FromFn<impl FnMut() -> Option<u64>> {
        std::iter::from_fn(move || {
            let current_value = self.value;
            self.value = self.next_value();
            Some(current_value)
        })
    }

    fn next_value(&self) -> u64 {
        let mut a = 0;
        let mut b = 1;
        loop {
            let next_value = b;
            a = b;
            b = a + next_value;
            return next_value;
        }
    }
}

struct ConsensusMechanism {
    sequence: SequenceGenerator,
    current_value: u64,
}

impl ConsensusMechanism {
    fn new(sequence: SequenceGenerator) -> Self {
        let current_value = sequence.generate().next().unwrap();
        ConsensusMechanism { sequence, current_value }
    }

    fn validate(&mut self) -> u64 {
        loop {
            if self.current_value % 2 == 0 {
                self.current_value = self.sequence.generate().next().unwrap();
            } else {
                return self.current_value;
            }
        }
    }
}

struct Ledger {
    consensus: ConsensusMechanism,
    entries: Vec<u64>,
}

impl Ledger {
    fn new(consensus: ConsensusMechanism) -> Self {
        Ledger { consensus, entries: Vec::new() }
    }

    fn record(&mut self) {
        loop {
            let entry = self.consensus.validate();
            self.entries.push(entry);
            println!("Recorded entry: {}", entry);
        }
    }
}

fn main() {
    let sequence = SequenceGenerator::new(0);
    let consensus = ConsensusMechanism::new(sequence);
    let mut ledger = Ledger::new(consensus);
    ledger.record();
}