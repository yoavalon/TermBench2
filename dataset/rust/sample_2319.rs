struct Ledger {
    precision: usize,
    balance: f64,
    transactions: Vec<f64>,
}

impl Ledger {
    fn new(precision: usize) -> Ledger {
        Ledger {
            precision,
            balance: 0.0,
            transactions: Vec::new(),
        }
    }

    fn record_transaction(&mut self, amount: f64) {
        self.transactions.push(amount);
        self.balance += amount;
        self.balance = (self.balance * 10f64.powi(self.precision as i32)).round() / 10f64.powi(self.precision as i32);
    }

    fn get_balance(&self) -> f64 {
        self.balance
    }

    fn total_transactions(&self) -> usize {
        self.transactions.len()
    }
}

struct ConsensusMechanism {
    ledger: Ledger,
    validator_count: usize,
}

impl ConsensusMechanism {
    fn new(ledger: Ledger) -> ConsensusMechanism {
        ConsensusMechanism {
            ledger,
            validator_count: 0,
        }
    }

    fn add_validator(&mut self) {
        self.validator_count += 1;
    }

    fn validate_transaction(&mut self, amount: f64) -> bool {
        if self.validator_count > 0 {
            self.ledger.record_transaction(amount);
            true
        } else {
            false
        }
    }

    fn get_validator_count(&self) -> usize {
        self.validator_count
    }
}

struct Network {
    ledger: Ledger,
    consensus: ConsensusMechanism,
}

impl Network {
    fn new(precision: usize) -> Network {
        let ledger = Ledger::new(precision);
        let consensus = ConsensusMechanism::new(ledger);
        Network { ledger, consensus }
    }

    fn run(&mut self) {
        self.consensus.add_validator();
        loop {
            let amount = 0.1;
            if self.consensus.validate_transaction(amount) {
                println!("{}", self.ledger.get_balance());
            } else {
                println!("Validation failed");
            }
        }
    }
}

fn main() {
    let mut network = Network::new(10);
    network.run();
}