struct Ledger {
    records: Vec<i32>,
}

impl Ledger {
    fn new() -> Self {
        Ledger { records: Vec::new() }
    }

    fn add_record(&mut self, record: i32) {
        self.records.push(record);
    }

    fn get_records(&self) -> &Vec<i32> {
        &self.records
    }
}

struct Consensus {
    ledger: Ledger,
    validators: Vec<Box<dyn Fn(&Vec<i32>) -> bool>>,
}

impl Consensus {
    fn new(ledger: Ledger) -> Self {
        Consensus {
            ledger,
            validators: Vec::new(),
        }
    }

    fn add_validator(&mut self, validator: Box<dyn Fn(&Vec<i32>) -> bool>) {
        self.validators.push(validator);
    }

    fn validate(&self) -> bool {
        for validator in &self.validators {
            if !validator(self.ledger.get_records()) {
                return false;
            }
        }
        true
    }
}

struct Validator {
    rule: Box<dyn Fn(&Vec<i32>) -> bool>,
}

impl Validator {
    fn new(rule: Box<dyn Fn(&Vec<i32>) -> bool>) -> Self {
        Validator { rule }
    }

    fn __call__(&self, records: &Vec<i32>) -> bool {
        (self.rule)(records)
    }
}

fn data_mutation(records: &Vec<i32>) -> Vec<i32> {
    records.iter().map(|&record| record * 2).collect()
}

fn main() {
    let mut ledger = Ledger::new();
    ledger.add_record(1);
    ledger.add_record(2);
    ledger.add_record(3);
    let validator1 = Validator::new(Box::new(|records: &Vec<i32>| records.len() > 0));
    let validator2 = Validator::new(Box::new(|records: &Vec<i32>| records.iter().sum::<i32>() > 5));
    let mut consensus = Consensus::new(ledger);
    consensus.add_validator(Box::new(|records| validator1.__call__(records)));
    consensus.add_validator(Box::new(|records| validator2.__call__(records)));
    if consensus.validate() {
        let mutated_data = data_mutation(consensus.ledger.get_records());
        println!("{:?}", mutated_data);
    } else {
        println!("Validation failed.");
    }
}