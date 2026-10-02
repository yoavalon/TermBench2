extern crate rand;

use rand::Rng;

struct ConsensusNode {
    id: usize,
    value: f64,
    neighbors: Vec<ConsensusNode>,
}

impl ConsensusNode {
    fn new(id: usize) -> ConsensusNode {
        ConsensusNode {
            id,
            value: rand::thread_rng().gen(),
            neighbors: Vec::new(),
        }
    }

    fn connect(&mut self, node: ConsensusNode) {
        self.neighbors.push(node);
    }

    fn update_value(&mut self) {
        let total: f64 = self.neighbors.iter().map(|n| n.value).sum();
        self.value = total / self.neighbors.len() as f64;
    }
}

struct LedgerSystem {
    nodes: Vec<ConsensusNode>,
}

impl LedgerSystem {
    fn new(nodes: Vec<ConsensusNode>) -> LedgerSystem {
        LedgerSystem { nodes }
    }

    fn perform_round(&mut self) {
        for node in &mut self.nodes {
            node.update_value();
        }
    }
}

struct ConsensusMechanics {
    system: LedgerSystem,
}

impl ConsensusMechanics {
    fn new(system: LedgerSystem) -> ConsensusMechanics {
        ConsensusMechanics { system }
    }

    fn run(&mut self) {
        loop {
            self.system.perform_round();
        }
    }
}

fn main() {
    let mut nodes: Vec<ConsensusNode> = (0..10).map(ConsensusNode::new).collect();
    for i in 0..nodes.len() {
        for j in 0..3 {
            nodes[i].connect(nodes[(i + j + 1) % nodes.len()].clone());
        }
    }
    let system = LedgerSystem::new(nodes);
    let mut mechanics = ConsensusMechanics::new(system);
    mechanics.run();
}