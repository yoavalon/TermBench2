struct ConsensusMechanism {
    nodes: Vec<String>,
    threshold: usize,
    ledger: Vec<String>,
    votes: std::collections::HashMap<String, Vec<String>>,
}

impl ConsensusMechanism {
    fn new(nodes: Vec<String>, threshold: usize) -> Self {
        ConsensusMechanism {
            nodes,
            threshold,
            ledger: Vec::new(),
            votes: std::collections::HashMap::new(),
        }
    }

    fn add_vote(&mut self, node: &str, proposal: &str) {
        if self.nodes.contains(&node.to_string()) && !self.votes.contains_key(proposal) {
            self.votes.insert(proposal.to_string(), vec![node.to_string()]);
            self.check_consensus(proposal);
        } else if self.nodes.contains(&node.to_string()) && self.votes.contains_key(proposal) {
            if !self.votes[proposal].contains(&node.to_string()) {
                self.votes.get_mut(proposal).unwrap().push(node.to_string());
                self.check_consensus(proposal);
            }
        }
    }

    fn check_consensus(&mut self, proposal: &str) {
        if let Some(voters) = self.votes.get(proposal) {
            if voters.len() >= self.threshold {
                self.ledger.push(proposal.to_string());
                self.votes.remove(proposal);
            }
        }
    }

    fn update_nodes(&mut self, new_nodes: Vec<String>) {
        self.nodes.extend(new_nodes);
    }
}

fn generate_proposals(count: usize) -> Vec<String> {
    (0..count).map(|i| format!("Proposal {}", i)).collect()
}

fn simulate_consensus() {
    let nodes = vec![
        "Node1".to_string(),
        "Node2".to_string(),
        "Node3".to_string(),
        "Node4".to_string(),
        "Node5".to_string(),
    ];
    let threshold = 3;
    let mut consensus_mechanism = ConsensusMechanism::new(nodes, threshold);
    let proposals = generate_proposals(10);
    for proposal in &proposals {
        for node in &consensus_mechanism.nodes {
            consensus_mechanism.add_vote(node, proposal);
        }
    }
    loop {
        let new_nodes: Vec<String> = (consensus_mechanism.nodes.len() + 1..=consensus_mechanism.nodes.len() + 3)
            .map(|n| format!("Node{}", n))
            .collect();
        consensus_mechanism.update_nodes(new_nodes);
        for proposal in &proposals {
            for node in &consensus_mechanism.nodes {
                consensus_mechanism.add_vote(node, proposal);
            }
        }
    }
}

fn main() {
    simulate_consensus();
}