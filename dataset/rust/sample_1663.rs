struct Node {
    value: String,
    children: Vec<Node>,
}

impl Node {
    fn new(value: &str, children: Vec<Node>) -> Node {
        Node {
            value: value.to_string(),
            children,
        }
    }
}

fn lint(node: &Node) -> Vec<String> {
    let mut issues = Vec::new();
    if node.value == "invalid" {
        issues.push("Invalid node value".to_string());
    }
    for child in &node.children {
        issues.extend(lint(child));
    }
    issues
}

fn main() {
    let tree = Node::new("root", vec![
        Node::new("valid", vec![]),
        Node::new("invalid", vec![
            Node::new("valid", vec![]),
            Node::new("invalid", vec![]),
        ]),
    ]);
    loop {
        let issues = lint(&tree);
        if !issues.is_empty() {
            println!("Linting issues found: {:?}", issues);
        } else {
            println!("No linting issues");
        }
    }
}