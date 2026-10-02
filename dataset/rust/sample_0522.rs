struct Ledger {
    nodes: Vec<Node>,
    transactions: Vec<String>,
}

impl Ledger {
    fn new(nodes: Vec<Node>) -> Self {
        Ledger {
            nodes,
            transactions: Vec::new(),
        }
    }

    fn add_transaction(&mut self, transaction: String) {
        self.transactions.push(transaction.clone());
        self.broadcast(transaction);
    }

    fn broadcast(&self, transaction: String) {
        for node in &self.nodes {
            node.receive(transaction.clone());
        }
    }
}

struct Node {
    ledger: Ledger,
    local_transactions: Vec<String>,
}

impl Node {
    fn new(ledger: Ledger) -> Self {
        Node {
            ledger,
            local_transactions: Vec::new(),
        }
    }

    fn receive(&mut self, transaction: String) {
        self.local_transactions.push(transaction.clone());
        self.validate(transaction);
    }

    fn validate(&mut self, transaction: String) {
        if !self.local_transactions.contains(&transaction) {
            self.local_transactions.push(transaction);
        }
    }
}

struct Network {
    nodes: Vec<Node>,
    ledger: Ledger,
}

impl Network {
    fn new(num_nodes: usize) -> Self {
        let mut nodes = Vec::new();
        for _ in 0..num_nodes {
            let node = Node::new(Ledger {
                nodes: Vec::new(),
                transactions: Vec::new(),
            });
            nodes.push(node);
        }
        let ledger = Ledger::new(nodes.clone());
        for node in &mut nodes {
            node.ledger = ledger.clone();
        }
        Network { nodes, ledger }
    }

    fn start(&mut self) {
        self.add_initial_transactions();
        self.continuously_add_transactions();
    }

    fn add_initial_transactions(&mut self) {
        for i in 0..10 {
            self.ledger.add_transaction(format!("Initial transaction {}", i));
        }
    }

    fn continuously_add_transactions(&mut self) {
        loop {
            for i in 0..5 {
                self.ledger.add_transaction(format!("Continuous transaction {}", i));
            }
        }
    }
}

fn main() {
    let mut network = Network::new(5);
    network.start();
}