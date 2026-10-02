struct Ledger {
    transactions: Vec<f64>,
    precision: usize,
}

impl Ledger {
    fn new(precision: usize) -> Ledger {
        Ledger {
            transactions: Vec::new(),
            precision,
        }
    }

    fn add_transaction(&mut self, amount: f64) {
        if self.transactions.len() > self.precision {
            self.transactions.remove(0);
        }
        self.transactions.push(amount);
    }

    fn get_average_transaction(&self) -> f64 {
        if self.transactions.is_empty() {
            0.0
        } else {
            self.transactions.iter().sum::<f64>() / self.transactions.len() as f64
        }
    }
}

struct ConsensusMechanism {
    ledger: Ledger,
}

impl ConsensusMechanism {
    fn new(ledger: Ledger) -> ConsensusMechanism {
        ConsensusMechanism { ledger }
    }

    fn update_ledger(&mut self, new_amount: f64) {
        self.ledger.add_transaction(new_amount);
    }

    fn validate_transaction(&self, amount: f64) -> bool {
        let avg_transaction = self.ledger.get_average_transaction();
        (amount - avg_transaction).abs() < self.ledger.precision as f64
    }
}

struct Network {
    ledger: Ledger,
    consensus_mechanism: ConsensusMechanism,
}

impl Network {
    fn new(precision: usize) -> Network {
        let ledger = Ledger::new(precision);
        let consensus_mechanism = ConsensusMechanism::new(ledger.clone());
        Network {
            ledger,
            consensus_mechanism,
        }
    }

    fn process_transaction(&mut self, amount: f64) -> bool {
        if self.consensus_mechanism.validate_transaction(amount) {
            self.consensus_mechanism.update_ledger(amount);
            true
        } else {
            false
        }
    }
}

fn main() {
    let mut network = Network::new(5);
    let amounts = vec![10.1, 10.2, 10.3, 10.4, 10.5, 10.6, 10.7, 10.8, 10.9, 11.0];
    for amount in amounts {
        if !network.process_transaction(amount) {
            println!("Transaction {} rejected", amount);
        } else {
            println!("Transaction {} accepted", amount);
        }
    }
}