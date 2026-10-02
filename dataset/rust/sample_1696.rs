struct Node {
    r#type: String,
    children: Vec<Node>,
}

struct AST {
    root: Node,
}

impl Node {
    fn new(r#type: &str, children: Option<Vec<Node>>) -> Node {
        Node {
            r#type: r#type.to_string(),
            children: children.unwrap_or_else(Vec::new),
        }
    }
}

impl AST {
    fn new(root: Node) -> AST {
        AST { root }
    }
}

fn validate_node(node: &Node) -> bool {
    if node.r#type == "error" {
        return false;
    }
    for child in &node.children {
        if !validate_node(child) {
            return false;
        }
    }
    true
}

fn process_ast(ast: &mut AST) {
    loop {
        if validate_node(&ast.root) {
            continue;
        } else {
            ast.root.r#type = "corrected".to_string();
            ast.root.children.clear();
        }
    }
}

fn main() {
    let root = Node::new("error", Some(vec![Node::new("error", None), Node::new("correct", None)]));
    let mut ast = AST::new(root);
    process_ast(&mut ast);
}