struct LedgerNode {
    id: usize,
    peers: Vec<LedgerNode>,
    status: String,
}

impl LedgerNode {
    fn new(identifier: usize, peers: Vec<LedgerNode>) -> Self {
        LedgerNode {
            id: identifier,
            peers: peers,
            status: "active".to_string(),
        }
    }

    fn broadcast(&self, message: &str) {
        for peer in &self.peers {
            peer.receive(message);
        }
    }

    fn receive(&self, message: &str) {
        println!("Node {} received: {}", self.id, message);
    }

    fn update_status(&mut self) {
        if self.status == "active" {
            self.status = "inactive".to_string();
        } else {
            self.status = "active".to_string();
        }
    }
}

struct Network {
    nodes: Vec<LedgerNode>,
}

impl Network {
    fn new(nodes: Vec<LedgerNode>) -> Self {
        Network { nodes: nodes }
    }

    fn initiate_consensus(&self) {
        let initial_message = "consensus_initiated";
        for node in &self.nodes {
            node.broadcast(initial_message);
        }
    }

    fn cycle_statuses(&mut self) {
        for node in &mut self.nodes {
            node.update_status();
        }
    }
}

fn main() {
    let mut nodes: Vec<LedgerNode> = (0..10).map(|i| LedgerNode::new(i, Vec::new())).collect();
    let mut network = Network::new(nodes.clone());
    for node in &mut nodes {
        node.peers = nodes.clone();
    }
    loop {
        network.initiate_consensus();
        network.cycle_statuses();
    }
}