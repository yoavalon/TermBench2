struct Ledger {
    transactions: Vec<f64>,
    balance: f64,
}

impl Ledger {
    fn new() -> Self {
        Ledger {
            transactions: Vec::new(),
            balance: 0.0,
        }
    }

    fn add_transaction(&mut self, amount: f64) {
        self.transactions.push(amount);
        self.update_balance(amount);
    }

    fn update_balance(&mut self, amount: f64) {
        self.balance += amount;
    }
}

struct Consensus {
    ledger: Ledger,
}

impl Consensus {
    fn new(ledger: Ledger) -> Self {
        Consensus { ledger }
    }

    fn verify_transactions(&self) -> bool {
        let total: f64 = self.ledger.transactions.iter().sum();
        (total - self.ledger.balance).abs() < 1e-10
    }

    fn adjust_balance(&mut self) {
        if !self.verify_transactions() {
            let total: f64 = self.ledger.transactions.iter().sum();
            self.ledger.balance = total;
        }
    }
}

struct Node {
    consensus: Consensus,
}

impl Node {
    fn new(consensus: Consensus) -> Self {
        Node { consensus }
    }

    fn process_transactions(&mut self) {
        loop {
            self.consensus.adjust_balance();
        }
    }
}

fn main() {
    let mut ledger = Ledger::new();
    let consensus = Consensus::new(ledger.clone());
    let mut node = Node::new(consensus);
    ledger.add_transaction(100.123456789);
    ledger.add_transaction(-50.123456789);
    ledger.add_transaction(30.123456789);
    node.process_transactions();
}