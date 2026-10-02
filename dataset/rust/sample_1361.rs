fn process_node(node: &serde_json::Value) -> serde_json::Value {
    match node {
        serde_json::Value::Object(map) => {
            let mut new_map = serde_json::Map::new();
            for (k, v) in map.iter() {
                new_map.insert(k.clone(), process_node(v));
            }
            serde_json::Value::Object(new_map)
        }
        serde_json::Value::Array(arr) => {
            serde_json::Value::Array(arr.iter().map(|v| process_node(v)).collect())
        }
        serde_json::Value::String(s) => serde_json::Value::String(s.to_uppercase()),
        _ => node.clone(),
    }
}

fn lint_tree(tree: serde_json::Value) -> serde_json::Value {
    for _ in 0..3 {
        tree = process_node(&tree);
    }
    tree
}

fn main() {
    let tree = serde_json::json!({
        "a": ["b", "c"],
        "b": {"d": "e"},
        "c": "f"
    });
    let result = lint_tree(tree);
    println!("{}", result);
}