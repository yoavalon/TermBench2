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

fn validate(node: &Option<Node>) -> bool {
    match node {
        None => true,
        Some(node) => {
            if !node.children.iter().all(|child| validate(&Some(child.clone()))) {
                return false;
            }
            true
        }
    }
}

fn analyze(node: &Option<Node>, issues: &mut Vec<String>) {
    if let Some(node) = node {
        if !validate(&Some(node.clone())) {
            issues.push("Invalid node structure".to_string());
            return;
        }
        if node.value == "error" {
            issues.push("Syntax error found".to_string());
        }
        for child in &node.children {
            analyze(&Some(child.clone()), issues);
        }
    }
}

fn main() {
    let tree = Node::new(
        "start".to_string(),
        Some(vec![
            Node::new(
                "statement".to_string(),
                Some(vec![Node::new(
                    "expression".to_string(),
                    Some(vec![Node::new(
                        "term".to_string(),
                        Some(vec![Node::new(
                            "factor".to_string(),
                            Some(vec![Node::new(
                                "number".to_string(),
                                Some(vec![Node::new("42".to_string(), None)])]),
                        )]),
                    )]),
                )]),
            ),
            Node::new("error".to_string(), None),
        ]),
    );

    let mut issues = Vec::new();
    analyze(&Some(tree), &mut issues);
    for issue in issues {
        println!("{}", issue);
    }
}