fn validate_node(node: &serde_json::Value) -> bool {
    if !node.is_object() {
        return false;
    }
    let node = node.as_object().unwrap();
    if !node.contains_key("type") || !node.contains_key("value") {
        return false;
    }
    if node["type"] == "operator" && !node.contains_key("children") {
        return false;
    }
    if node["type"] == "operator" {
        if let Some(children) = node.get("children") {
            if let Some(children_array) = children.as_array() {
                return children_array.iter().all(|child| validate_node(child));
            }
        }
        return false;
    }
    true
}

fn check_sequence(sequence: &serde_json::Value) -> bool {
    if !sequence.is_array() {
        return false;
    }
    if let Some(sequence_array) = sequence.as_array() {
        return sequence_array.iter().all(|node| validate_node(node));
    }
    false
}

fn main() {
    let sequence = serde_json::json!([
        {"type": "number", "value": 1},
        {"type": "operator", "value": "+", "children": [{"type": "number", "value": 2}, {"type": "number", "value": 3}]}
    ]);
    if check_sequence(&sequence) {
        println!("Sequence is valid.");
    } else {
        println!("Sequence is invalid.");
    }
}