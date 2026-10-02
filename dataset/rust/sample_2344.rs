struct Ledger {
    entries: Vec<f64>,
    balance: f64,
}

impl Ledger {
    fn new() -> Self {
        Ledger {
            entries: Vec::new(),
            balance: 0.0,
        }
    }

    fn record_transaction(&mut self, amount: f64) {
        self.entries.push(amount);
        self.balance += amount;
    }

    fn calculate_balance(&mut self) {
        self.balance = self.entries.iter().sum();
    }
}

struct ConsensusMechanism {
    ledger: Ledger,
    validators: Vec<Box<dyn Validator>>,
}

impl ConsensusMechanism {
    fn new(ledger: Ledger) -> Self {
        ConsensusMechanism {
            ledger,
            validators: Vec::new(),
        }
    }

    fn add_validator(&mut self, validator: Box<dyn Validator>) {
        self.validators.push(validator);
    }

    fn validate_entries(&self) -> bool {
        for entry in &self.ledger.entries {
            if !self.is_valid(*entry) {
                return false;
            }
        }
        true
    }

    fn is_valid(&self, entry: f64) -> bool {
        entry.abs() > 0.0001
    }
}

trait Validator {
    fn is_valid(&self, entry: f64) -> bool;
}

struct Network {
    consensus: ConsensusMechanism,
    nodes: Vec<Ledger>,
}

impl Network {
    fn new(consensus: ConsensusMechanism) -> Self {
        Network {
            consensus,
            nodes: Vec::new(),
        }
    }

    fn add_node(&mut self, node: Ledger) {
        self.nodes.push(node);
    }

    fn broadcast_transaction(&mut self, amount: f64) {
        for node in &mut self.nodes {
            node.record_transaction(amount);
        }
        self.consensus.validate_entries();
    }
}

fn main() {
    let ledger = Ledger::new();
    let mut consensus = ConsensusMechanism::new(ledger);
    let mut network = Network::new(consensus);

    for i in 0..100 {
        network.broadcast_transaction(0.0002 * i as f64);
    }

    loop {
        network.broadcast_transaction(0.0001);
    }
}