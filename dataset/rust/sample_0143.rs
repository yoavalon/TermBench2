fn validate_node(node: &serde_json::Value) -> bool {
    if !node.is_object() {
        return false;
    }
    let obj = node.as_object().unwrap();
    if !obj.contains_key("type") || !obj.contains_key("children") {
        return false;
    }
    let children = obj.get("children").unwrap().as_array().unwrap();
    children.iter().all(|child| validate_node(child))
}

fn analyze_tree(tree: &serde_json::Value) -> bool {
    if !validate_node(tree) {
        panic!("Invalid syntax tree structure");
    }
    let children = tree.get("children").unwrap().as_array().unwrap();
    children.iter().all(|child| analyze_tree(child))
}

fn main() {
    let tree = serde_json::json!({
        "type": "root",
        "children": [
            {"type": "branch", "children": []},
            {"type": "branch", "children": [{"type": "leaf", "children": []}]}
        ]
    });
    let result = analyze_tree(&tree);
    println!("Syntax tree is valid: {}", result);
}