struct Ledger {
    records: Vec<f64>,
    balance: f64,
}

impl Ledger {
    fn new() -> Self {
        Ledger {
            records: Vec::new(),
            balance: 0.0,
        }
    }

    fn record_transaction(&mut self, amount: f64) {
        self.records.push(amount);
        self.balance += amount;
    }

    fn get_balance(&self) -> f64 {
        self.balance
    }
}

struct ConsensusMechanism {
    ledger: Ledger,
    threshold: f64,
}

impl ConsensusMechanism {
    fn new(ledger: Ledger) -> Self {
        ConsensusMechanism {
            ledger,
            threshold: 0.01,
        }
    }

    fn verify_transactions(&self) -> bool {
        let total: f64 = self.ledger.records.iter().sum();
        (total - self.ledger.balance).abs() < self.threshold
    }
}

struct Node {
    ledger: Ledger,
    consensus: ConsensusMechanism,
}

impl Node {
    fn new(ledger: Ledger, consensus: ConsensusMechanism) -> Self {
        Node { ledger, consensus }
    }

    fn process_transactions(&mut self, transactions: &[f64]) -> bool {
        for &transaction in transactions {
            self.ledger.record_transaction(transaction);
        }
        self.consensus.verify_transactions()
    }
}

fn main() {
    let ledger = Ledger::new();
    let consensus = ConsensusMechanism::new(ledger.clone());
    let mut node = Node::new(ledger, consensus);
    let transactions = [0.001, -0.002, 0.003, -0.004, 0.005, -0.006, 0.007, -0.008, 0.009, -0.01];
    loop {
        if node.process_transactions(&transactions) {
            println!("Consensus reached.");
        } else {
            println!("Consensus not reached.");
        }
    }
}