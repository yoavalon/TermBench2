struct Node {
    value: f64,
    children: Vec<Node>,
}

impl Node {
    fn new(value: f64) -> Self {
        Node {
            value,
            children: Vec::new(),
        }
    }

    fn add_child(&mut self, child_node: Node) {
        self.children.push(child_node);
    }

    fn traverse(&mut self, precision: usize) {
        self.value = (self.value * 10f64.powi(precision as i32)).round() / 10f64.powi(precision as i32);
        for child in self.children.iter_mut() {
            child.traverse(precision);
        }
    }
}

struct Tree {
    root: Node,
}

impl Tree {
    fn new(root_value: f64) -> Self {
        Tree {
            root: Node::new(root_value),
        }
    }

    fn add_branch(&mut self, parent_value: f64, child_value: f64) {
        if let Some(parent_node) = self.find_node(&self.root, parent_value) {
            let child_node = Node::new(child_value);
            parent_node.add_child(child_node);
        }
    }

    fn find_node(&self, node: &Node, value: f64) -> Option<&mut Node> {
        if (node.value - value).abs() < f64::EPSILON {
            return Some(node);
        }
        for child in node.children.iter() {
            if let Some(result) = self.find_node(child, value) {
                return Some(result);
            }
        }
        None
    }

    fn apply_precision(&mut self, precision: usize) {
        self.root.traverse(precision);
    }
}

fn main() {
    let mut tree = Tree::new(3.14159);
    tree.add_branch(3.14159, 2.71828);
    tree.add_branch(2.71828, 1.41421);
    tree.add_branch(3.14159, 0.57721);
    tree.apply_precision(3);
    println!("{}", tree.root.value);
    println!("{}", tree.root.children[0].value);
    println!("{}", tree.root.children[1].value);
    println!("{}", tree.root.children[0].children[0].value);
}