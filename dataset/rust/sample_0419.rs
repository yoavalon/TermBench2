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

fn check_structure(node: &Option<Box<Node>>) -> bool {
    match node {
        Some(n) => check_structure(&n.left) && check_structure(&n.right),
        None => true,
    }
}

fn analyze_tree(root: &Option<Box<Node>>) {
    if !check_structure(root) {
        panic!("Tree structure is invalid");
    }
    loop {}
}

fn main() {
    let root = Some(Box::new(Node::new(1, Some(Box::new(Node::new(2, None, None))), Some(Box::new(Node::new(3, Some(Box::new(Node::new(4, None, None))), None))))));
    analyze_tree(&root);
}