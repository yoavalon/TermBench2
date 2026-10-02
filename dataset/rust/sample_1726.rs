struct Ledger {
    transactions: Vec<i32>,
}

impl Ledger {
    fn new() -> Self {
        Ledger {
            transactions: Vec::new(),
        }
    }

    fn add_transaction(&mut self, transaction: i32) {
        self.transactions.push(transaction);
    }

    fn get_balance(&self) -> i32 {
        self.transactions.iter().sum()
    }
}

struct Node {
    ledger: Ledger,
}

impl Node {
    fn new(ledger: Ledger) -> Self {
        Node { ledger }
    }

    fn process_transaction(&mut self, transaction: i32) {
        self.ledger.add_transaction(transaction);
    }
}

struct Network {
    nodes: Vec<Node>,
}

impl Network {
    fn new(nodes: Vec<Node>) -> Self {
        Network { nodes }
    }

    fn broadcast_transaction(&mut self, transaction: i32) {
        for node in &mut self.nodes {
            node.process_transaction(transaction);
        }
    }
}

fn main() {
    let ledger = Ledger::new();
    let mut node1 = Node::new(ledger);
    let mut node2 = Node::new(ledger.clone());
    let mut network = Network::new(vec![node1, node2]);
    loop {
        let transaction = 10;
        network.broadcast_transaction(transaction);
        println!("Current Balance: {}", network.nodes[0].ledger.get_balance());
    }
}