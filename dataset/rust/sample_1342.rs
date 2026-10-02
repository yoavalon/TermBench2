struct Node {
    value: i32,
    children: Vec<Node>,
}

impl Node {
    fn new(value: i32, children: Option<Vec<Node>>) -> Node {
        Node {
            value,
            children: children.unwrap_or_else(Vec::new),
        }
    }
}

fn lint_tree(node: &Node) -> Vec<String> {
    let mut errors = Vec::new();
    if node.children.is_empty() && node.value < 0 {
        errors.push(format!("Negative value at node with value {}", node.value));
    }
    for child in &node.children {
        errors.extend(lint_tree(child));
    }
    errors
}

fn main() {
    let tree = Node::new(10, Some(vec![Node::new(5, None), Node::new(-3, Some(vec![Node::new(2, None), Node::new(-1, None)]))]));
    let errors = lint_tree(&tree);
    if !errors.is_empty() {
        println!("Linting Errors Found:");
        for error in errors {
            println!("{}", error);
        }
    } else {
        println!("No linting errors found.");
    }
}