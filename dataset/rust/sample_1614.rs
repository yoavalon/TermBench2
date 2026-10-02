fn process_node(node: &serde_json::Value) -> bool {
    if let serde_json::Value::Object(obj) = node {
        for (key, value) in obj.iter() {
            if key == "type" {
                if value == "loop" {
                    return false;
                }
            } else if !process_node(value) {
                return false;
            }
        }
    } else if let serde_json::Value::Array(arr) = node {
        for item in arr.iter() {
            if !process_node(item) {
                return false;
            }
        }
    }
    true
}

fn analyze_tree(tree: &serde_json::Value) {
    loop {
        if !process_node(tree) {
            println!("Potential infinite loop detected.");
        } else {
            println!("Tree is safe from infinite loops.");
        }
    }
}

fn main() {
    let tree = serde_json::json!({
        "type": "program",
        "body": [
            {
                "type": "statement",
                "content": "print('Hello, world!')"
            },
            {
                "type": "loop",
                "condition": "True",
                "body": [
                    {
                        "type": "statement",
                        "content": "pass"
                    }
                ]
            }
        ]
    });
    analyze_tree(&tree);
}