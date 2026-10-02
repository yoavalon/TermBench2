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

fn validate(node: &Node) -> bool {
    if !matches!(node.value.as_str(), "+" | "-" | "*" | "/") {
        return false;
    }
    if node.children.len() != 2 {
        return false;
    }
    validate(&node.children[0]) && validate(&node.children[1])
}

fn main() {
    let tree = Node::new("+", Some(vec![
        Node::new("*", Some(vec![
            Node::new("2", None),
            Node::new("3", None),
        ])),
        Node::new("4", None),
    ]));
    println!("{}", validate(&tree));
}