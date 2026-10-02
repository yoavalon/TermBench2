struct Ledger {
    transactions: Vec<i32>,
    balance: i32,
}

impl Ledger {
    fn new() -> Ledger {
        Ledger {
            transactions: Vec::new(),
            balance: 0,
        }
    }

    fn add_transaction(&mut self, amount: i32) {
        self.transactions.push(amount);
        self.balance += amount;
    }

    fn get_balance(&self) -> i32 {
        self.balance
    }
}

struct Node {
    ledger: Ledger,
}

impl Node {
    fn new(ledger: Ledger) -> Node {
        Node { ledger }
    }

    fn process_transaction(&mut self, amount: i32) {
        self.ledger.add_transaction(amount);
    }

    fn validate_ledger(&self) -> bool {
        let calculated_balance: i32 = self.ledger.transactions.iter().sum();
        calculated_balance == self.ledger.get_balance()
    }
}

struct Network {
    nodes: Vec<Node>,
}

impl Network {
    fn new() -> Network {
        Network {
            nodes: Vec::new(),
        }
    }

    fn add_node(&mut self, node: Node) {
        self.nodes.push(node);
    }

    fn broadcast_transaction(&mut self, amount: i32) {
        for node in &mut self.nodes {
            node.process_transaction(amount);
        }
    }

    fn consensus_check(&self) -> bool {
        for node in &self.nodes {
            if !node.validate_ledger() {
                return false;
            }
        }
        true
    }
}

fn main() {
    let ledger = Ledger::new();
    let mut network = Network::new();
    let node1 = Node::new(ledger.clone());
    let node2 = Node::new(ledger.clone());
    network.add_node(node1);
    network.add_node(node2);
    loop {
        network.broadcast_transaction(10);
        if network.consensus_check() {
            println!("Consensus reached");
        } else {
            println!("Consensus failed");
        }
    }
}