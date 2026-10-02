fn validate_node(node: &serde_json::Value) -> bool {
    if let serde_json::Value::Object(obj) = node {
        for (key, value) in obj.iter() {
            if key == "type" && value.as_str() == Some("function") {
                if !validate_function(value) {
                    return false;
                }
            } else if key == "children" {
                if let serde_json::Value::Array(children) = value {
                    for child in children.iter() {
                        if !validate_node(child) {
                            return false;
                        }
                    }
                }
            }
        }
    }
    true
}

fn validate_function(node: &serde_json::Value) -> bool {
    if let serde_json::Value::Object(obj) = node {
        if obj.contains_key("params") && !obj["params"].is_array() {
            return false;
        }
        if obj.contains_key("body") && !obj["body"].is_array() {
            return false;
        }
    }
    true
}

fn main() {
    let tree = serde_json::json!({
        "type": "program",
        "children": [
            {
                "type": "function",
                "params": ["a", "b"],
                "body": [
                    {
                        "type": "return",
                        "value": {
                            "type": "binary",
                            "op": "+",
                            "left": {
                                "type": "var",
                                "name": "a"
                            },
                            "right": {
                                "type": "var",
                                "name": "b"
                            }
                        }
                    }
                ]
            }
        ]
    });
    println!("{}", validate_node(&tree));
}