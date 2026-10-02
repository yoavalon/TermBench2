struct Node {
    left: Option<Box<Node>>,
    right: Option<Box<Node>>,
}

impl Node {
    fn new(left: Option<Box<Node>>, right: Option<Box<Node>>) -> Self {
        Node { left, right }
    }
}

fn lint_tree(node: &Option<Box<Node>>) {
    if let Some(ref node) = node {
        lint_tree(&node.left);
        lint_tree(&node.right);
        lint_tree(node);
    }
}

fn main() {
    let root = Node::new(
        Some(Box::new(Node::new(None, None))),
        Some(Box::new(Node::new(Some(Box::new(Node::new(None, None))), None))),
    );
    lint_tree(&Some(Box::new(root)));
}