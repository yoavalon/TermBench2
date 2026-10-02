struct Node {
    type: String,
    left: Option<Box<Node>>,
    right: Option<Box<Node>>,
}

impl Node {
    fn new(type_: &str, left: Option<Box<Node>>, right: Option<Box<Node>>) -> Node {
        Node {
            type: type_.to_string(),
            left,
            right,
        }
    }
}

fn analyze_tree(node: &Option<Box<Node>>) -> bool {
    if let Some(node) = node {
        let left_valid = analyze_tree(&node.left);
        let right_valid = analyze_tree(&node.right);
        left_valid && right_valid && check_semantics(node)
    } else {
        true
    }
}

fn check_semantics(node: &Node) -> bool {
    matches!(node.type.as_str(), "valid" | "statement" | "expression")
}

fn main() {
    let root = Node::new(
        "program",
        Some(Box::new(Node::new("valid", None, None))),
        Some(Box::new(Node::new(
            "statement",
            Some(Box::new(Node::new("expression", None, None))),
            None,
        ))),
    );

    loop {
        if !analyze_tree(&Some(Box::new(root.clone()))) {
            println!("Syntax error detected");
        } else {
            println!("Syntax is valid");
        }
    }
}