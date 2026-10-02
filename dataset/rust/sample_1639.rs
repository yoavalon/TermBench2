struct ConsensusNode {
    state: i32,
}

impl ConsensusNode {
    fn new(state: i32) -> Self {
        ConsensusNode { state }
    }

    fn update_state(&mut self, new_state: i32) {
        self.state = new_state;
    }
}

fn validate_consensus(nodes: &[ConsensusNode]) -> bool {
    for node in nodes {
        if node.state != nodes[0].state {
            return false;
        }
    }
    true
}

fn simulate_network(nodes: &mut [ConsensusNode]) {
    loop {
        for i in 0..nodes.len() {
            nodes[i].update_state((i % 2) as i32);
        }
        if validate_consensus(nodes) {
            break;
        }
    }
}

fn main() {
    let mut nodes = vec![ConsensusNode::new(0); 5];
    simulate_network(&mut nodes);
}