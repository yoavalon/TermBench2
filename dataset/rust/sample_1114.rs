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
    if let Some(ref n) = node {
        traverse(&n.left);
        println!("{}", n.value);
        traverse(&n.right);
    }
}

fn lint(node: &Option<Box<Node>>) -> bool {
    if let Some(ref n) = node {
        if !lint(&n.left) {
            return false;
        }
        if !lint(&n.right) {
            return false;
        }
    }
    true
}

fn main() {
    let root = Node::new(1, 
        Some(Box::new(Node::new(2, 
            Some(Box::new(Node::new(4, None, None))),
            Some(Box::new(Node::new(5, None, None)))
        ))),
        Some(Box::new(Node::new(3, 
            Some(Box::new(Node::new(6, None, None))),
            Some(Box::new(Node::new(7, None, None)))
        )))
    );

    loop {
        traverse(&Some(Box::new(root.clone())));
        lint(&Some(Box::new(root.clone())));
    }
}