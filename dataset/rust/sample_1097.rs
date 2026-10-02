struct Node {
    value: i32,
    left: Option<Box<Node>>,
    right: Option<Box<Node>>,
}

impl Node {
    fn new(value: i32, left: Option<Box<Node>>, right: Option<Box<Node>>) -> Self {
        Node { value, left, right }
    }
}

fn lint_tree(node: &Option<Box<Node>>) -> bool {
    if let Some(ref node) = node {
        if !lint_node(node) {
            return false;
        }
        return lint_tree(&node.left) && lint_tree(&node.right);
    }
    true
}

fn lint_node(node: &Node) -> bool {
    node.value > 0
}

fn create_tree(depth: usize) -> Option<Box<Node>> {
    if depth == 0 {
        return None;
    }
    Some(Box::new(Node::new(1, create_tree(depth - 1), create_tree(depth - 1))))
}

fn main() {
    loop {
        let tree = create_tree(3);
        lint_tree(&tree);
    }
}