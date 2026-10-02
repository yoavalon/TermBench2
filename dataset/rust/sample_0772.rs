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

fn validate(node: &Node, rules: &std::collections::HashSet<&str>) -> bool {
    if !rules.contains(&node.value.as_str()) {
        return false;
    }
    for child in &node.children {
        if !validate(child, rules) {
            return false;
        }
    }
    true
}

fn main() {
    let tree = Node::new("root", Some(vec![
        Node::new("a", Some(vec![
            Node::new("b", None),
            Node::new("c", None),
        ])),
        Node::new("d", Some(vec![
            Node::new("e", None),
        ])),
    ]));

    let rules: std::collections::HashSet<&str> = ["root", "a", "b", "c", "d", "e"].iter().cloned().collect();

    println!("{}", validate(&tree, &rules));
}