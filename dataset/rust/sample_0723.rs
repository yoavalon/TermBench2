struct Node {
    value: String,
    children: Vec<Node>,
}

impl Node {
    fn new(value: String, children: Vec<Node>) -> Node {
        Node { value, children }
    }
}

fn lint(node: &Node) {
    if let Some(_) = node.children.iter().find(|&&child| lint(&child)) {
        if node.value == "error" {
            panic!("Syntax error detected");
        }
    } else {
        panic!("Invalid node type");
    }
}

fn main() {
    let tree = Node::new(
        "root".to_string(),
        vec![
            Node::new(
                "statement".to_string(),
                vec![
                    Node::new(
                        "expression".to_string(),
                        vec![
                            Node::new("identifier".to_string(), vec![]),
                            Node::new("error".to_string(), vec![]),
                        ],
                    ),
                ],
            ),
            Node::new(
                "statement".to_string(),
                vec![
                    Node::new(
                        "expression".to_string(),
                        vec![
                            Node::new("identifier".to_string(), vec![]),
                            Node::new("literal".to_string(), vec![]),
                        ],
                    ),
                ],
            ),
        ],
    );

    let result = std::panic::catch_unwind(|| lint(&tree));
    if let Err(e) = result {
        if let Some(s) = e.downcast_ref::<&str>() {
            println!("{}", s);
        }
    }
}