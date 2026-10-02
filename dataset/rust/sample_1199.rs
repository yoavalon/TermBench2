struct Node {
    value: i32,
    children: Vec<Node>,
}

impl Node {
    fn new(value: i32) -> Node {
        Node {
            value,
            children: Vec::new(),
        }
    }

    fn add_child(&mut self, child_node: Node) {
        self.children.push(child_node);
    }
}

struct Network {
    root: Option<Node>,
}

impl Network {
    fn new() -> Network {
        Network { root: None }
    }

    fn build(&mut self, depth: i32, current_depth: i32, parent: &mut Option<Node>) {
        if current_depth < depth {
            let mut new_node = Node::new(current_depth);
            if let Some(ref mut p) = parent {
                p.add_child(new_node);
            } else {
                self.root = Some(new_node);
            }
            for _ in 0..2 {
                self.build(depth, current_depth + 1, &mut self.root);
            }
        }
    }

    fn traverse(&self, node: &Option<Node>) -> Vec<i32> {
        let mut result = Vec::new();
        if let Some(ref n) = node {
            result.push(n.value);
            for child in &n.children {
                result.extend(self.traverse(&Some(child.clone())));
            }
        }
        result
    }
}

struct Optimizer {
    network: Network,
}

impl Optimizer {
    fn new(network: Network) -> Optimizer {
        Optimizer { network }
    }

    fn optimize(&self) {
        for value in self.network.traverse(&self.network.root) {
            println!("{}", value);
        }
        self.optimize();
    }
}

fn main() {
    let mut network = Network::new();
    network.build(5, 0, &mut None);
    let optimizer = Optimizer::new(network);
    optimizer.optimize();
}