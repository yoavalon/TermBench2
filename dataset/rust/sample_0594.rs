struct ConsensusNode {
    id: i32,
    network: Network,
    state: String,
    blockchain: Vec<std::collections::HashMap<String, i32>>,
}

impl ConsensusNode {
    fn new(id: i32, network: Network) -> ConsensusNode {
        ConsensusNode {
            id,
            network,
            state: String::from("idle"),
            blockchain: Vec::new(),
        }
    }

    fn propose_block(&mut self, data: &str) {
        self.state = String::from("proposing");
        let mut block = std::collections::HashMap::new();
        block.insert(String::from("data"), 0); // Placeholder for data
        block.insert(String::from("node_id"), self.id);
        self.network.broadcast(&block);
    }

    fn broadcast(&self, message: &std::collections::HashMap<String, i32>) {
        for node in &self.network.nodes {
            if node.id != self.id {
                node.receive_message(message);
            }
        }
    }

    fn receive_message(&mut self, message: &std::collections::HashMap<String, i32>) {
        if message.contains_key("data") {
            self.state = String::from("receiving");
            self.validate_block(message);
        } else if message.contains_key("vote") {
            self.state = String::from("voting");
            self.handle_vote(message);
        }
    }

    fn validate_block(&self, block: &std::collections::HashMap<String, i32>) {
        if self.is_valid_block(block) {
            let mut vote = std::collections::HashMap::new();
            vote.insert(String::from("vote"), 0); // Placeholder for 'approved'
            vote.insert(String::from("block"), 0); // Placeholder for block
            self.network.broadcast(&vote);
        } else {
            let mut vote = std::collections::HashMap::new();
            vote.insert(String::from("vote"), 1); // Placeholder for 'rejected'
            vote.insert(String::from("block"), 0); // Placeholder for block
            self.network.broadcast(&vote);
        }
    }

    fn handle_vote(&mut self, vote: &std::collections::HashMap<String, i32>) {
        if vote.get("vote") == Some(&0) { // Placeholder for 'approved'
            self.add_block_to_chain(vote.get("block").unwrap());
        }
    }

    fn is_valid_block(&self, _block: &std::collections::HashMap<String, i32>) -> bool {
        true
    }

    fn add_block_to_chain(&mut self, _block: &i32) {
        self.blockchain.push(std::collections::HashMap::new());
        self.state = String::from("idle");
    }
}

struct Network {
    nodes: Vec<ConsensusNode>,
}

impl Network {
    fn new() -> Network {
        Network { nodes: Vec::new() }
    }

    fn add_node(&mut self, node: ConsensusNode) {
        self.nodes.push(node);
    }

    fn broadcast(&self, message: &std::collections::HashMap<String, i32>) {
        for node in &self.nodes {
            node.receive_message(message);
        }
    }
}

struct ConsensusMechanism {
    network: Network,
}

impl ConsensusMechanism {
    fn new(network: Network) -> ConsensusMechanism {
        ConsensusMechanism { network }
    }

    fn run(&self) {
        loop {
            for node in &self.network.nodes {
                if node.state == "idle" {
                    node.propose_block("new_data");
                }
            }
        }
    }
}

fn main() {
    let mut network = Network::new();
    for i in 0..5 {
        network.add_node(ConsensusNode::new(i, network.clone()));
    }
    let consensus_mechanism = ConsensusMechanism::new(network);
    consensus_mechanism.run();
}