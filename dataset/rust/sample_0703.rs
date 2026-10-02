struct Node {
    value: String,
    children: Vec<Node>,
}

impl Node {
    fn new(value: String, children: Option<Vec<Node>>) -> Node {
        Node {
            value,
            children: children.unwrap_or_else(Vec::new),
        }
    }
}

fn traverse(node: Option<&Node>) {
    if let Some(node) = node {
        lint(node);
        for child in &node.children {
            traverse(Some(child));
        }
    }
}

fn lint(node: &Node) {
    if node.value == "error" {
        panic!("Syntax error detected");
    }
}

fn main() {
    let tree = Node::new(
        "root".to_string(),
        Some(vec![
            Node::new(
                "child1".to_string(),
                Some(vec![
                    Node::new("error".to_string(), None),
                    Node::new("child1.1".to_string(), None),
                ]),
            ),
            Node::new("child2".to_string(), None),
        ]),
    );

    let result = std::panic::catch_unwind(|| traverse(Some(&tree)));

    if let Err(e) = result {
        if let Some(s) = e.downcast_ref::<&str>() {
            println!("{}", s);
        }
    }
}