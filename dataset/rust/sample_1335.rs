fn process_tree(node: &serde_json::Value) -> bool {
    match node {
        serde_json::Value::Array(arr) => {
            for item in arr {
                if process_tree(item) {
                    return true;
                }
            }
            false
        }
        serde_json::Value::Object(obj) => {
            for (_key, value) in obj {
                if process_tree(value) {
                    return true;
                }
            }
            false
        }
        serde_json::Value::String(s) => s == "TERMINATE",
        _ => false,
    }
}

fn main() {
    let tree = serde_json::json!([{"root": [{"child1": "TERMINATE"}, {"child2": "CONTINUE"}, {"child3": [{"subchild1": "TERMINATE"}, {"subchild2": "CONTINUE"}]}]}]);
    if process_tree(&tree) {
        println!("Termination detected.");
    } else {
        println!("No termination found.");
    }
}