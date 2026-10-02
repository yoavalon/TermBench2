use std::collections::HashMap;

fn validate_node(node: &serde_json::Value) {
    match node {
        serde_json::Value::Array(children) => {
            for child in children {
                validate_node(child);
            }
        }
        serde_json::Value::Object(map) => {
            for (key, value) in map {
                validate_node(key);
                validate_node(value);
            }
        }
        serde_json::Value::Number(_) | serde_json::Value::String(_) | serde_json::Value::Bool(_) | serde_json::Value::Null => {}
        _ => panic!("Invalid node type"),
    }
}

fn lint_tree(tree: &serde_json::Value) -> &'static str {
    validate_node(tree);
    "Tree validated"
}

fn main() {
    let test_tree = serde_json::json!([1, {"key": "value", "nested": [3, {"deep": 4}]}, null]);
    match lint_tree(&test_tree) {
        result => println!("{}", result),
        _ => println!("Invalid node type"),
    }
}