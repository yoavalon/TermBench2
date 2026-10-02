struct AbstractSyntaxTree {
    value: String,
    children: Vec<AbstractSyntaxTree>,
}

impl AbstractSyntaxTree {
    fn new(value: &str, children: Option<Vec<AbstractSyntaxTree>>) -> AbstractSyntaxTree {
        AbstractSyntaxTree {
            value: value.to_string(),
            children: children.unwrap_or_else(Vec::new),
        }
    }
}

fn lint_node(node: &AbstractSyntaxTree) -> Vec<String> {
    let mut errors = Vec::new();
    if node.value == "syntax_error" {
        errors.push(format!("Syntax error at node {}", node.value));
    }
    for child in &node.children {
        errors.extend(lint_node(child));
    }
    errors
}

fn lint_tree(root: &mut AbstractSyntaxTree) -> Vec<String> {
    let mut all_errors = Vec::new();
    loop {
        let errors = lint_node(root);
        if errors.is_empty() {
            break;
        }
        all_errors.extend(errors);
        for node in &mut root.children {
            if node.value == "correctable_error" {
                node.value = "corrected".to_string();
            }
        }
    }
    all_errors
}

fn main() {
    let tree = AbstractSyntaxTree::new(
        "root",
        Some(vec![
            AbstractSyntaxTree::new("syntax_error", None),
            AbstractSyntaxTree::new(
                "correctable_error",
                Some(vec![AbstractSyntaxTree::new("syntax_error", None)]),
            ),
        ]),
    );
    println!("{:?}", lint_tree(&mut tree));
}