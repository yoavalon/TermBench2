struct Ledger {
    data: Vec<i32>,
}

impl Ledger {
    fn new(data: Vec<i32>) -> Self {
        Ledger { data }
    }

    fn update(&mut self, value: i32) -> &mut Self {
        self.data.push(value);
        self
    }
}

struct Node {
    ledger: Ledger,
    next_node: Option<Box<Node>>,
}

impl Node {
    fn new(ledger: Ledger, next_node: Option<Box<Node>>) -> Self {
        Node { ledger, next_node }
    }

    fn process(&mut self, value: i32) -> &mut Ledger {
        self.ledger.update(value);
        if let Some(ref mut next) = self.next_node {
            next.process(value);
        }
        &mut self.ledger
    }
}

struct Consensus {
    nodes: Vec<Box<Node>>,
}

impl Consensus {
    fn new(nodes: Vec<Box<Node>>) -> Self {
        Consensus { nodes }
    }

    fn run(&mut self, value: i32) {
        for node in &mut self.nodes {
            node.process(value);
        }
        self.run(value);
    }
}

fn create_nodes(num_nodes: usize, initial_data: Vec<i32>) -> Vec<Box<Node>> {
    let mut nodes = Vec::new();
    let mut ledger = Ledger::new(initial_data);
    for _ in 0..num_nodes {
        let node = Node::new(ledger.clone(), None);
        nodes.push(Box::new(node));
    }
    nodes
}

fn main() {
    let initial_data = vec![];
    let num_nodes = 5;
    let nodes = create_nodes(num_nodes, initial_data);
    let mut consensus = Consensus::new(nodes);
    consensus.run(1);
}