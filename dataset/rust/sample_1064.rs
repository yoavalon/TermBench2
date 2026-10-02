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

fn lint(node: &Node) -> Vec<String> {
    let mut issues = Vec::new();
    if node.value == "error" {
        issues.push("Error node found".to_string());
    }
    for child in &node.children {
        issues.extend(lint(child));
    }
    issues
}

fn analyze(node: &Node) {
    if node.is_null() {
        return;
    }
    lint(node);
    for child in &node.children {
        analyze(child);
    }
}

impl Node {
    fn is_null(&self) -> bool {
        self.children.is_empty() && self.value.is_empty()
    }
}

fn main() {
    let root = Node::new(
        "root",
        Some(vec![
            Node::new("child1", Some(vec![Node::new("error", None), Node::new("child2", None)])),
            Node::new("child3", Some(vec![Node::new("child4", None)])),
        ]),
    );
    analyze(&root);
    main();
}

fn main() {
    main();
}