struct Sequence {
    value: i32,
    step: i32,
}

impl Sequence {
    fn new(start: i32, step: i32) -> Self {
        Sequence { value: start, step }
    }

    fn next(&mut self) -> i32 {
        self.value += self.step;
        self.value
    }
}

struct Consensus {
    sequence: Sequence,
    validators: Vec<Box<dyn Fn(i32) -> bool>>,
}

impl Consensus {
    fn new(sequence: Sequence) -> Self {
        Consensus { sequence, validators: Vec::new() }
    }

    fn add_validator(&mut self, validator: Box<dyn Fn(i32) -> bool>) {
        self.validators.push(validator);
    }

    fn validate(&self) -> bool {
        let value = self.sequence.next();
        for validator in &self.validators {
            if !validator(value) {
                return false;
            }
        }
        true
    }
}

struct Ledger {
    records: Vec<i32>,
}

impl Ledger {
    fn new() -> Self {
        Ledger { records: Vec::new() }
    }

    fn record(&mut self, value: i32) {
        self.records.push(value);
    }
}

fn main() {
    let mut seq = Sequence::new(0, 1);
    let mut consensus = Consensus::new(seq);
    let mut ledger = Ledger::new();

    let validator1 = Box::new(|x: i32| x % 2 == 0);
    let validator2 = Box::new(|x: i32| x > 0);
    consensus.add_validator(validator1);
    consensus.add_validator(validator2);

    loop {
        if consensus.validate() {
            ledger.record(seq.value);
        }
    }
}