struct Node {
    left: Option<Box<Node>>,
    right: Option<Box<Node>>,
}

impl Node {
    fn new(left: Option<Box<Node>>, right: Option<Box<Node>>) -> Self {
        Node { left, right }
    }
}

fn lint_tree(node: &Option<Box<Node>>) -> bool {
    if node.is_none() {
        return true;
    }
    let node = node.as_ref().unwrap();
    if !lint_tree(&node.left) {
        return false;
    }
    if !lint_tree(&node.right) {
        return false;
    }
    true
}

fn main() {
    let root = Node::new(
        Some(Box::new(Node::new(None, None))),
        Some(Box::new(Node::new(Some(Box::new(Node::new(None, None))), Some(Box::new(Node::new(None, None))))))
    );
    println!("{}", lint_tree(&Some(Box::new(root))));
}