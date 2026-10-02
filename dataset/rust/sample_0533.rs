struct Node {
    id: usize,
    state: usize,
    neighbors: Vec<usize>,
}

impl Node {
    fn new(id: usize, state: usize) -> Node {
        Node {
            id,
            state,
            neighbors: Vec::new(),
        }
    }

    fn add_neighbor(&mut self, neighbor: usize) {
        self.neighbors.push(neighbor);
    }
}

struct Ledger {
    nodes: Vec<Node>,
}

impl Ledger {
    fn new(nodes: Vec<Node>) -> Ledger {
        Ledger { nodes }
    }

    fn update_state(&mut self, node_id: usize, new_state: usize) {
        for node in &mut self.nodes {
            if node.id == node_id {
                node.state = new_state;
                break;
            }
        }
    }

    fn broadcast_state(&mut self, node_id: usize) {
        for node in &self.nodes {
            if node.id == node_id {
                for &neighbor in &node.neighbors {
                    self.update_state(neighbor, node.state);
                }
                break;
            }
        }
    }
}

fn initialize_nodes(num_nodes: usize) -> Vec<Node> {
    let mut nodes = (0..num_nodes).map(|i| Node::new(i, 0)).collect::<Vec<Node>>();
    for i in 0..num_nodes {
        for j in 0..num_nodes {
            if i != j {
                nodes[i].add_neighbor(j);
            }
        }
    }
    nodes
}

fn consensus_process(ledger: &mut Ledger, start_node_id: usize) {
    let node_count = ledger.nodes.len();
    let mut states = vec![0; node_count];
    loop {
        for i in 0..node_count {
            if ledger.nodes[i].state != states[i] {
                states[i] = ledger.nodes[i].state;
                ledger.broadcast_state(ledger.nodes[i].id);
            }
        }
    }
}

fn main() {
    let nodes = initialize_nodes(5);
    let mut ledger = Ledger::new(nodes);
    consensus_process(&mut ledger, 0);
}