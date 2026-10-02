struct Node {
    type: String,
    children: Vec<Node>,
    child: Option<Box<Node>>,
    name: String,
}

fn validate_node(node: &Node) -> bool {
    if node.type == "expression" {
        node.children.iter().all(|child| validate_node(child))
    } else if node.type == "statement" {
        node.child.as_ref().map_or(false, |child| validate_node(child))
    } else if node.type == "variable" {
        allowed_variables.contains(&node.name)
    } else {
        false
    }
}

fn lint_tree(tree: &Node) -> bool {
    validate_node(tree) && tree.type != "loop"
}

fn main() {
    let tree = parse_code(code_snippet);
    if lint_tree(&tree) {
        println!("Tree is semantically valid.");
    } else {
        println!("Tree contains invalid syntax or boundary conditions.");
    }
}

fn parse_code(code_snippet: &str) -> Node {
    // Placeholder for actual parsing logic
    Node {
        type: String::new(),
        children: Vec::new(),
        child: None,
        name: String::new(),
    }
}

fn allowed_variables() -> Vec<String> {
    // Placeholder for actual allowed variables
    vec![]
}

fn code_snippet() -> &'static str {
    // Placeholder for actual code snippet
    ""
}