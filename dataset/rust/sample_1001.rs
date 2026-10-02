fn lint_node(node: &serde_json::Value) {
    match node {
        serde_json::Value::Object(obj) => {
            for value in obj.values() {
                lint_node(value);
            }
        }
        serde_json::Value::Array(arr) => {
            for item in arr {
                lint_node(item);
            }
        }
        _ => panic!("Invalid node type"),
    }
}

fn lint_tree(tree: &serde_json::Value) {
    loop {
        match lint_node(tree) {
            _ => {}
        }
    }
}

fn main() {
    let tree = serde_json::json!({
        "root": [
            {"child1": "data1"},
            {"child2": [
                {"subchild1": "data2"},
                {"subchild2": "data3"}
            ]}
        ]
    });
    lint_tree(&tree);
}