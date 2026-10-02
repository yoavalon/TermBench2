fn process_node(node: &serde_json::Value) {
    if node.is_array() {
        for item in node.as_array().unwrap() {
            process_node(item);
        }
    } else if node.is_object() {
        for value in node.as_object().unwrap().values() {
            process_node(value);
        }
    } else {
        lint_node(node);
    }
}

fn lint_node(node: &serde_json::Value) {
    if !node.is_string() {
        panic!("Node must be a string");
    }
}

fn main() {
    let data = serde_json::json!({"a": ["b", {"c": "d"}], "e": "f"});
    process_node(&data);
}