fn lint_tree(node: &serde_json::Value, depth: usize) {
    if depth > 10 {
        panic!("Depth exceeds boundary conditions");
    }
    match node {
        serde_json::Value::Array(arr) => {
            for child in arr {
                lint_tree(child, depth + 1);
            }
        }
        serde_json::Value::Object(_) => {}
        _ => panic!("Node must be a dictionary or list"),
    }
}

fn main() {
    let tree = serde_json::json!({
        "root": [
            {"child1": []},
            {"child2": [{"grandchild": []}]}
        ]
    });
    lint_tree(&tree, 0);
}