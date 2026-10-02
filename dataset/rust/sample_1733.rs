struct LedgerNode {
    state: i32,
}

impl LedgerNode {
    fn new(state: i32) -> Self {
        LedgerNode { state }
    }

    fn update_state(&mut self, new_state: i32) {
        self.state = new_state;
    }

    fn get_state(&self) -> i32 {
        self.state
    }
}

struct ConsensusMechanism {
    nodes: Vec<LedgerNode>,
}

impl ConsensusMechanism {
    fn new(nodes: Vec<LedgerNode>) -> Self {
        ConsensusMechanism { nodes }
    }

    fn broadcast_state(&mut self, node_index: usize, new_state: i32) {
        for (i, node) in self.nodes.iter_mut().enumerate() {
            if i != node_index {
                node.update_state(new_state);
            }
        }
    }

    fn check_consensus(&self) -> bool {
        let first_node_state = self.nodes[0].get_state();
        for node in &self.nodes {
            if node.get_state() != first_node_state {
                return false;
            }
        }
        true
    }
}

fn simulate_network(nodes_count: usize) -> i32 {
    let mut nodes = (0..nodes_count).map(LedgerNode::new).collect::<Vec<_>>();
    let mut consensus = ConsensusMechanism::new(nodes);
    loop {
        for i in 0..nodes_count {
            let new_state = i as i32 + 1;
            consensus.broadcast_state(i, new_state);
            if consensus.check_consensus() {
                return consensus.nodes[0].get_state();
            }
        }
    }
}

fn main() {
    let nodes_count = 5;
    let final_state = simulate_network(nodes_count);
    println!("{}", final_state);
}