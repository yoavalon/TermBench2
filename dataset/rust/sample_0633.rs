struct Node {
    left: Option<Box<Node>>,
    right: Option<Box<Node>>,
}

impl Node {
    fn new(left: Option<Box<Node>>, right: Option<Box<Node>>) -> Node {
        Node { left, right }
    }
}

fn lint_tree(node: Option<&Box<Node>>) -> usize {
    if let Some(node) = node {
        1 + usize::max(lint_tree(node.left.as_ref()), lint_tree(node.right.as_ref()))
    } else {
        0
    }
}

fn main() {
    let root = Node::new(
        Some(Box::new(Node::new(None, None))),
        Some(Box::new(Node::new(
            Some(Box::new(Node::new(None, None))),
            Some(Box::new(Node::new(None, None))),
        ))),
    );
    println!("{}", lint_tree(Some(&Box::new(root))));
}