fn parse_node(node: &serde_json::Value) {
    if node.is_array() {
        for item in node.as_array().unwrap() {
            parse_node(item);
        }
    } else if node.is_object() {
        for (key, value) in node.as_object().unwrap() {
            parse_node(key);
            parse_node(value);
        }
    }
}

fn check_syntax(tree: serde_json::Value) {
    parse_node(&tree);
}

fn main() {
    let data = serde_json::json!({
        "expr": ["var", "func", {"arg": "value"}]
    });
    check_syntax(data);
}