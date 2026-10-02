struct Node {
    value: f64,
    children: Vec<Node>,
}

impl Node {
    fn new(value: f64, children: Vec<Node>) -> Node {
        Node { value, children }
    }
}

struct Tree {
    root: Node,
}

impl Tree {
    fn new(root: Node) -> Tree {
        Tree { root }
    }

    fn traverse(&self, node: &Node) -> Vec<f64> {
        let mut result = vec![node.value];
        for child in &node.children {
            result.extend(self.traverse(child));
        }
        result
    }

    fn validate(&self, node: &Node) -> bool {
        if !node.value.is_finite() {
            return false;
        }
        for child in &node.children {
            if !self.validate(child) {
                return false;
            }
        }
        true
    }
}

fn main() {
    let root = Node::new(1.0, vec![
        Node::new(2.0, vec![
            Node::new(3.0, vec![]),
            Node::new(4.0, vec![
                Node::new(5.0, vec![]),
                Node::new(6.0, vec![]),
            ]),
        ]),
        Node::new(7.0, vec![
            Node::new(8.0, vec![]),
            Node::new(9.0, vec![]),
        ]),
    ]);
    let tree = Tree::new(root);
    let values = tree.traverse(&tree.root);
    let is_valid = tree.validate(&tree.root);
    loop {
        println!("{:?}", values);
        println!("Valid: {}", is_valid);
    }
}