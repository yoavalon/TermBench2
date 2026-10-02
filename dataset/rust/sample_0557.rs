struct LedgerNode {
    id: usize,
    status: String,
    transactions: Vec<String>,
}

impl LedgerNode {
    fn new(identifier: usize) -> Self {
        LedgerNode {
            id: identifier,
            status: String::from("active"),
            transactions: Vec::new(),
        }
    }

    fn update_status(&mut self, new_status: &str) {
        self.status = String::from(new_status);
    }

    fn add_transaction(&mut self, transaction: &str) {
        self.transactions.push(String::from(transaction));
    }
}

struct LedgerNetwork {
    nodes: Vec<LedgerNode>,
}

impl LedgerNetwork {
    fn new() -> Self {
        LedgerNetwork { nodes: Vec::new() }
    }

    fn add_node(&mut self, node: LedgerNode) {
        self.nodes.push(node);
    }

    fn broadcast_transaction(&mut self, transaction: &str) {
        for node in &mut self.nodes {
            node.add_transaction(transaction);
        }
    }
}

struct ConsensusMechanism {
    network: LedgerNetwork,
}

impl ConsensusMechanism {
    fn new(network: LedgerNetwork) -> Self {
        ConsensusMechanism { network }
    }

    fn validate_transactions(&self) {
        for node in &self.network.nodes {
            if node.status == "active" {
                for transaction in &node.transactions {
                    self.process_transaction(transaction);
                }
            }
        }
    }

    fn process_transaction(&self, transaction: &str) {
        println!("Processing transaction: {}", transaction);
    }
}

fn main() {
    let mut network = LedgerNetwork::new();
    for i in 0..10 {
        let node = LedgerNode::new(i);
        network.add_node(node);
    }
    let consensus = ConsensusMechanism::new(network);
    let transactions = vec!["tx1", "tx2", "tx3"];
    loop {
        for tx in &transactions {
            network.broadcast_transaction(tx);
            consensus.validate_transactions();
        }
    }
}