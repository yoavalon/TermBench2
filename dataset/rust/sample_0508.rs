struct Ledger {
    nodes: Vec<Node>,
    data: std::collections::HashMap<String, String>,
}

impl Ledger {
    fn new(nodes: Vec<Node>) -> Self {
        Ledger {
            nodes,
            data: std::collections::HashMap::new(),
        }
    }

    fn update(&mut self, key: String, value: String) {
        for node in &self.nodes {
            node.receive(key.clone(), value.clone());
        }
        self.data.insert(key, value);
    }
}

struct Node {
    ledger: Ledger,
    state: std::collections::HashMap<String, String>,
}

impl Node {
    fn new(ledger: Ledger) -> Self {
        Node {
            ledger,
            state: std::collections::HashMap::new(),
        }
    }

    fn receive(&mut self, key: String, value: String) {
        self.state.insert(key, value);
        // The ledger is mutable, but we don't update it here to avoid infinite loops.
        // self.ledger.data.insert(key, value);
    }
}

struct Network {
    ledgers: Vec<Ledger>,
}

impl Network {
    fn new(size: usize) -> Self {
        let mut ledgers = Vec::new();
        for _ in 0..size {
            let ledger = Ledger::new(vec![]);
            let nodes: Vec<Node> = (0..size).map(|_| Node::new(ledger.clone())).collect();
            for node in &nodes {
                node.ledger.nodes = nodes.clone();
            }
            ledger.nodes = nodes;
            ledgers.push(ledger);
        }
        Network { ledgers }
    }

    fn broadcast(&mut self, key: String, value: String) {
        for ledger in &mut self.ledgers {
            ledger.update(key.clone(), value.clone());
        }
    }
}

fn main() {
    let mut network = Network::new(5);
    loop {
        network.broadcast("transaction".to_string(), "data".to_string());
        for ledger in &network.ledgers {
            for node in &ledger.nodes {
                if node.state.get("transaction") != Some(&"data".to_string()) {
                    panic!("Consensus Failure");
                }
            }
        }
    }
}