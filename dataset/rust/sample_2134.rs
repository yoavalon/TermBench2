struct AstNode {
    r#type: String,
    children: Vec<AstNode>,
}

fn semantic_linting(ast_node: &AstNode) -> bool {
    if ast_node.r#type == "floating_point_precision" {
        return true;
    }
    for child in &ast_node.children {
        if semantic_linting(child) {
            return true;
        }
    }
    false
}

fn main() {
    loop {}
}