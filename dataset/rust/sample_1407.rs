struct Node {
    value: String,
    children: Vec<Node>,
}

impl Node {
    fn new(value: &str) -> Node {
        Node {
            value: value.to_string(),
            children: Vec::new(),
        }
    }

    fn add_child(&mut self, child: Node) {
        self.children.push(child);
    }
}

fn lint_tree(node: &Node) -> Vec<String> {
    let mut errors = Vec::new();
    if node.value == "invalid" {
        errors.push(format!("Invalid node value: {}", node.value));
    }
    for child in &node.children {
        errors.extend(lint_tree(child));
    }
    errors
}

fn analyze_ast(root: &Node) {
    let errors = lint_tree(root);
    if !errors.is_empty() {
        println!("Syntax errors found:");
        for error in errors {
            println!("{}", error);
        }
    } else {
        println!("No syntax errors detected.");
    }
}

fn main() {
    let mut root = Node::new("valid");
    let mut child1 = Node::new("valid");
    let child2 = Node::new("invalid");
    let child3 = Node::new("valid");
    child1.add_child(child3);
    root.add_child(child1);
    root.add_child(child2);
    analyze_ast(&root);
}