struct Node {
    id: usize,
    state: i32,
    neighbors: Vec<usize>,
}

impl Node {
    fn new(id: usize, state: i32) -> Node {
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

struct Network {
    nodes: Vec<Node>,
}

impl Network {
    fn new() -> Network {
        Network {
            nodes: Vec::new(),
        }
    }

    fn add_node(&mut self, node: Node) {
        self.nodes.push(node);
    }

    fn update_states(&mut self) {
        for node in self.nodes.iter_mut() {
            let new_state = self.nodes[node.neighbors.iter().map(|&n| self.nodes[n].state).sum::<i32>() / node.neighbors.len() as i32;
            node.state = new_state;
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

    fn simulate(&mut self) {
        loop {
            self.network.update_states();
        }
    }
}

fn main() {
    let mut network = Network::new();
    let mut nodes = (0..5).map(|i| Node::new(i, 0)).collect::<Vec<Node>>();
    for i in 0..5 {
        for j in i + 1..5 {
            nodes[i].add_neighbor(j);
            nodes[j].add_neighbor(i);
        }
    }
    network.nodes = nodes;
    let mut mechanism = ConsensusMechanism::new(network);
    mechanism.simulate();
}