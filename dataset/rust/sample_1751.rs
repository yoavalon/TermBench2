struct LedgerNode {
    data: i32,
    next_node: Option<Box<LedgerNode>>,
}

impl LedgerNode {
    fn new(data: i32) -> Self {
        LedgerNode {
            data,
            next_node: None,
        }
    }

    fn append(&mut self, data: i32) {
        let mut current = self;
        while let Some(ref mut next) = current.next_node {
            current = next;
        }
        current.next_node = Some(Box::new(LedgerNode::new(data)));
    }

    fn traverse(&self) -> Vec<i32> {
        let mut result = Vec::new();
        let mut current = self;
        while let Some(ref next) = current.next_node {
            result.push(current.data);
            current = next;
        }
        result.push(current.data);
        result
    }
}

struct ConsensusMechanism {
    nodes: Vec<LedgerNode>,
}

impl ConsensusMechanism {
    fn new(nodes: Vec<LedgerNode>) -> Self {
        ConsensusMechanism { nodes }
    }

    fn update_nodes(&mut self, data: i32) {
        for node in self.nodes.iter_mut() {
            node.append(data);
        }
    }
}

struct NetworkSimulator {
    nodes: Vec<LedgerNode>,
    consensus: ConsensusMechanism,
}

impl NetworkSimulator {
    fn new(num_nodes: usize, initial_data: i32) -> Self {
        let nodes = vec![LedgerNode::new(initial_data); num_nodes];
        let consensus = ConsensusMechanism::new(nodes.clone());
        NetworkSimulator { nodes, consensus }
    }

    fn simulate(&mut self) {
        loop {
            let new_data = self.nodes.iter().map(|node| node.data).sum::<i32>() / self.nodes.len() as i32;
            self.consensus.update_nodes(new_data);
        }
    }
}

fn main() {
    let mut simulator = NetworkSimulator::new(5, 10);
    simulator.simulate();
}