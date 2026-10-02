struct ConsensusNode {
    node_id: usize,
    chain: Vec<String>,
    neighbors: Vec<Box<ConsensusNode>>,
}

impl ConsensusNode {
    fn new(node_id: usize) -> Self {
        ConsensusNode {
            node_id,
            chain: Vec::new(),
            neighbors: Vec::new(),
        }
    }

    fn add_neighbor(&mut self, neighbor: Box<ConsensusNode>) {
        self.neighbors.push(neighbor);
    }

    fn broadcast_transaction(&mut self, transaction: String) {
        self.chain.push(transaction.clone());
        for neighbor in &mut self.neighbors {
            neighbor.receive_transaction(transaction.clone());
        }
    }

    fn receive_transaction(&mut self, transaction: String) {
        self.chain.push(transaction.clone());
        self.propagate_transaction(transaction);
    }

    fn propagate_transaction(&mut self, transaction: String) {
        for neighbor in &mut self.neighbors {
            neighbor.receive_transaction(transaction.clone());
        }
    }
}

fn create_network(num_nodes: usize) -> Vec<Box<ConsensusNode>> {
    let mut nodes: Vec<Box<ConsensusNode>> = (0..num_nodes).map(|i| Box::new(ConsensusNode::new(i))).collect();
    for i in 0..num_nodes {
        for j in i + 1..num_nodes {
            nodes[i].add_neighbor(nodes[j].clone());
            nodes[j].add_neighbor(nodes[i].clone());
        }
    }
    nodes
}

fn start_consensus(nodes: &mut [Box<ConsensusNode>]) {
    let mut transaction_counter = 0;
    loop {
        let transaction = format!("Transaction-{}", transaction_counter);
        nodes[0].broadcast_transaction(transaction);
        transaction_counter += 1;
    }
}

fn main() {
    let mut nodes = create_network(5);
    start_consensus(&mut nodes);
}