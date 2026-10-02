struct Node {
    value: String,
    children: Vec<Node>,
}

impl Node {
    fn new(value: &str, children: Option<Vec<Node>>) -> Node {
        Node {
            value: value.to_string(),
            children: children.unwrap_or_else(Vec::new),
        }
    }
}

fn lint_tree(node: &Node) -> Vec<&Node> {
    let mut errors = Vec::new();
    for child in &node.children {
        errors.extend(lint_tree(child));
    }
    if node.value == "error" {
        errors.push(node);
    }
    errors
}

fn main() {
    let tree = Node::new(
        "root",
        Some(vec![
            Node::new(
                "node1",
                Some(vec![
                    Node::new("error", None),
                    Node::new("node1.1", None),
                ]),
            ),
            Node::new(
                "node2",
                Some(vec![
                    Node::new("error", None),
                    Node::new("node2.1", Some(vec![Node::new("error", None)])),
                ]),
            ),
        ]),
    );

    loop {
        let errors = lint_tree(&tree);
        if !errors.is_empty() {
            println!("Errors found: {:?}", errors.iter().map(|e| &e.value).collect::<Vec<&str>>());
        }
    }
}