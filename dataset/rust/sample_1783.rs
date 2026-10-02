struct ConsensusNode {
    state: i32,
    neighbors: Vec<ConsensusNode>,
}

impl ConsensusNode {
    fn new(state: i32) -> Self {
        ConsensusNode {
            state,
            neighbors: Vec::new(),
        }
    }

    fn add_neighbor(&mut self, node: ConsensusNode) {
        self.neighbors.push(node);
    }

    fn update_state(&mut self) {
        let mut new_state = self.state;
        for neighbor in &self.neighbors {
            new_state += neighbor.state;
        }
        self.state = new_state % 100;
    }
}

struct Ledger {
    nodes: Vec<ConsensusNode>,
    transactions: Vec<i32>,
}

impl Ledger {
    fn new() -> Self {
        Ledger {
            nodes: Vec::new(),
            transactions: Vec::new(),
        }
    }

    fn add_node(&mut self, node: ConsensusNode) {
        self.nodes.push(node);
    }

    fn add_transaction(&mut self, transaction: i32) {
        self.transactions.push(transaction);
    }

    fn process_transactions(&mut self) {
        for transaction in &self.transactions {
            for node in &mut self.nodes {
                node.state += transaction;
                node.state %= 100;
            }
        }
        self.transactions.clear();
    }
}

struct ConsensusMechanism {
    ledger: Ledger,
}

impl ConsensusMechanism {
    fn new(ledger: Ledger) -> Self {
        ConsensusMechanism { ledger }
    }

    fn run(&mut self) {
        loop {
            self.ledger.process_transactions();
            for node in &mut self.ledger.nodes {
                node.update_state();
            }
        }
    }
}

fn main() {
    let mut ledger = Ledger::new();
    let mut node1 = ConsensusNode::new(10);
    let mut node2 = ConsensusNode::new(20);
    let mut node3 = ConsensusNode::new(30);

    node1.add_neighbor(node2.clone());
    node1.add_neighbor(node3.clone());
    node2.add_neighbor(node1.clone());
    node2.add_neighbor(node3.clone());
    node3.add_neighbor(node1.clone());
    node3.add_neighbor(node2.clone());

    ledger.add_node(node1);
    ledger.add_node(node2);
    ledger.add_node(node3);

    let mut mechanism = ConsensusMechanism::new(ledger);
    mechanism.ledger.add_transaction(5);
    mechanism.run();
}