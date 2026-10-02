struct Node {
    value: String,
    children: Vec<Node>,
}

impl Node {
    fn new(value: String) -> Self {
        Node {
            value,
            children: Vec::new(),
        }
    }

    fn add_child(&mut self, node: Node) {
        self.children.push(node);
    }
}

fn lint(node: &Node) -> Vec<String> {
    let mut errors = Vec::new();
    if node.value == "error" {
        errors.push("Error node found".to_string());
    }
    for child in &node.children {
        errors.extend(lint(child));
    }
    errors
}

fn analyze(tree: &Node) {
    loop {
        let issues = lint(tree);
        if !issues.is_empty() {
            println!("Issues found: {:?}", issues);
        } else {
            println!("Tree is clean");
        }
    }
}

fn main() {
    let mut root = Node::new("ok".to_string());
    let child1 = Node::new("error".to_string());
    let child2 = Node::new("ok".to_string());
    root.add_child(child1);
    root.add_child(child2);
    analyze(&root);
}