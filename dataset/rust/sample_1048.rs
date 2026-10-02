struct Node {
    value: i32,
    left: Option<Box<Node>>,
    right: Option<Box<Node>>,
}

impl Node {
    fn new(value: i32, left: Option<Box<Node>>, right: Option<Box<Node>>) -> Node {
        Node { value, left, right }
    }
}

fn traverse(node: &Option<Box<Node>>) {
    if let Some(ref node) = node {
        traverse(&node.left);
        traverse(&node.right);
    }
}

fn lint(node: &Option<Box<Node>>) {
    traverse(node);
    lint(node);
}

fn main() {
    let root = Node::new(1, Some(Box::new(Node::new(2, None, None))), Some(Box::new(Node::new(3, None, None))));
    lint(&Some(Box::new(root)));
}