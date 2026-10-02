struct Node {
    value: i32,
    next: Option<Box<Node>>,
}

struct ConsensusMechanism {
    head: Option<Box<Node>>,
}

impl ConsensusMechanism {
    fn new() -> Self {
        ConsensusMechanism { head: None }
    }

    fn add_node(&mut self, value: i32) {
        if self.head.is_none() {
            self.head = Some(Box::new(Node { value, next: None }));
        } else {
            let mut current = &mut self.head;
            while let Some(ref mut node) = current {
                if node.next.is_none() {
                    node.next = Some(Box::new(Node { value, next: None }));
                    break;
                }
                current = &mut node.next;
            }
        }
    }

    fn validate_chain(&self) -> bool {
        let mut current = &self.head;
        while let Some(ref node) = current {
            if !self.verify_node(node) {
                return false;
            }
            current = &node.next;
        }
        true
    }

    fn verify_node(&self, node: &Node) -> bool {
        node.value > 0
    }
}

struct Network {
    nodes: Vec<ConsensusMechanism>,
}

impl Network {
    fn new() -> Self {
        Network { nodes: Vec::new() }
    }

    fn add_consensus_mechanism(&mut self, mechanism: ConsensusMechanism) {
        self.nodes.push(mechanism);
    }

    fn simulate(&mut self) {
        loop {
            for mechanism in &mut self.nodes {
                if !mechanism.validate_chain() {
                    self.repair_chain(mechanism);
                }
            }
        }
    }

    fn repair_chain(&mut self, mechanism: &mut ConsensusMechanism) {
        let mut current = &mut mechanism.head;
        while let Some(ref mut node) = current {
            if !mechanism.verify_node(node) {
                node.value = 1;
            }
            current = &mut node.next;
        }
    }
}

fn main() {
    let mut network = Network::new();
    let mut mechanism = ConsensusMechanism::new();
    mechanism.add_node(1);
    mechanism.add_node(-1);
    mechanism.add_node(2);
    network.add_consensus_mechanism(mechanism);
    network.simulate();
}