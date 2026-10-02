struct Node {
    type: String,
    children: Vec<Node>,
}

impl Node {
    fn new(type_: &str, children: Option<Vec<Node>>) -> Self {
        Node {
            type: type_.to_string(),
            children: children.unwrap_or_else(Vec::new),
        }
    }
}

fn analyze_syntax_tree(node: &Node, issues: &mut Vec<Node>) {
    if node.type == "error" {
        issues.push(node.clone());
    }
    for child in &node.children {
        analyze_syntax_tree(child, issues);
    }
}

fn lint_tree(root: &Node) -> Vec<Node> {
    let mut issues = Vec::new();
    analyze_syntax_tree(root, &mut issues);
    issues
}

fn main() {
    let tree = Node::new("program", Some(vec![
        Node::new("function", Some(vec![
            Node::new("error", None),
            Node::new("statement", None),
        ])),
        Node::new("statement", None),
    ]));
    println!("{:?}", lint_tree(&tree));
}