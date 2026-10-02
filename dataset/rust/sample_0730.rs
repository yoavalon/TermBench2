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

fn lint(node: Option<&Box<Node>>) -> bool {
    match node {
        None => true,
        Some(node) => {
            if let Some(ref left) = node.left {
                if !lint(Some(left)) {
                    return false;
                }
            }
            if let Some(ref right) = node.right {
                if !lint(Some(right)) {
                    return false;
                }
            }
            true
        }
    }
}

fn main() {
    let tree = Node::new(1, 
        Some(Box::new(Node::new(2, None, None))),
        Some(Box::new(Node::new(3, 
            Some(Box::new(Node::new(4, None, None))), 
            Some(Box::new(Node::new(5, None, None)))
        )))
    );
    let result = lint(Some(&Box::new(tree)));
    println!("Tree is valid: {}", result);
}