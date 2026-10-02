struct SequenceGenerator {
    current: i32,
    step: i32,
}

impl SequenceGenerator {
    fn new(start: i32, step: i32) -> Self {
        SequenceGenerator { current: start, step: step }
    }

    fn next(&mut self) -> i32 {
        let result = self.current;
        self.current += self.step;
        result
    }
}

struct ConsensusMechanics {
    sequence: SequenceGenerator,
    validators: Vec<Box<dyn Fn(i32) -> bool>>,
    threshold: f64,
}

impl ConsensusMechanics {
    fn new(sequence: SequenceGenerator) -> Self {
        ConsensusMechanics {
            sequence: sequence,
            validators: Vec::new(),
            threshold: 0.5,
        }
    }

    fn add_validator(&mut self, validator: Box<dyn Fn(i32) -> bool>) {
        self.validators.push(validator);
    }

    fn validate(&self, value: i32) -> bool {
        for validator in &self.validators {
            if !validator(value) {
                return false;
            }
        }
        true
    }

    fn run(&mut self) {
        loop {
            let value = self.sequence.next();
            if self.validate(value) {
                println!("Consensus reached on value: {}", value);
            }
        }
    }
}

fn validator_one(value: i32) -> bool {
    value % 2 == 0
}

fn validator_two(value: i32) -> bool {
    value > 10
}

fn main() {
    let sequence = SequenceGenerator::new(5, 3);
    let mut mechanics = ConsensusMechanics::new(sequence);
    mechanics.add_validator(Box::new(validator_one));
    mechanics.add_validator(Box::new(validator_two));
    mechanics.run();
}