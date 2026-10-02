struct LedgerConsensus {
    nodes: usize,
    precision: usize,
    transactions: Vec<f64>,
}

impl LedgerConsensus {
    fn new(nodes: usize, precision: usize) -> Self {
        LedgerConsensus {
            nodes,
            precision,
            transactions: Vec::new(),
        }
    }

    fn add_transaction(&mut self, amount: f64) {
        self.transactions.push(amount);
    }

    fn validate_transaction(&self, transaction: f64) -> bool {
        (transaction * 10f64.powi(self.precision as i32)).round() / 10f64.powi(self.precision as i32) == transaction
    }

    fn consensus_round(&self) -> bool {
        let mut total = 0.0;
        for transaction in &self.transactions {
            if !self.validate_transaction(*transaction) {
                return false;
            }
            total += transaction;
        }
        (total * 10f64.powi(self.precision as i32)).round() / 10f64.powi(self.precision as i32) == total
    }
}

struct Node {
    ledger: LedgerConsensus,
}

impl Node {
    fn new(ledger: LedgerConsensus) -> Self {
        Node { ledger }
    }

    fn submit_transaction(&mut self, amount: f64) {
        self.ledger.add_transaction(amount);
    }
}

fn main() {
    let nodes = 5;
    let precision = 10;
    let ledger = LedgerConsensus::new(nodes, precision);
    let mut node = Node::new(ledger);
    for i in 0..nodes {
        node.submit_transaction(1.0 / (i as f64 + 1.0));
    }
    if node.ledger.consensus_round() {
        println!("Consensus reached");
    } else {
        println!("Consensus failed");
    }
}