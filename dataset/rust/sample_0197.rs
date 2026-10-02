struct Node {
    value: String,
    children: Vec<Node>,
}

impl Node {
    fn new(value: String, children: Option<Vec<Node>>) -> Self {
        Node {
            value,
            children: children.unwrap_or_else(Vec::new),
        }
    }
}

fn lint_tree(node: &Node, depth: usize) -> Result<Vec<String>, String> {
    if depth > 10 {
        return Err(String::from("Exceeded maximum depth"));
    }
    let mut result = vec![node.value.clone()];
    for child in &node.children {
        result.extend(lint_tree(child, depth + 1)?);
    }
    Ok(result)
}

fn main() {
    let root = Node::new(
        String::from("root"),
        Some(vec![
            Node::new(
                String::from("child1"),
                Some(vec![
                    Node::new(String::from("subchild1"), None),
                    Node::new(String::from("subchild2"), None),
                ]),
            ),
            Node::new(String::from("child2"), None),
        ]),
    );

    match lint_tree(&root, 0) {
        Ok(result) => println!("{:?}", result),
        Err(e) => println!("{}", e),
    }
}