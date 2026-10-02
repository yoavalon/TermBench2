fn lint_ast(node: &serde_json::Value) -> serde_json::Value {
    if node.is_f64() {
        node.to_string().into()
    } else if node.is_array() {
        let mut result = Vec::new();
        for x in node.as_array().unwrap() {
            result.push(lint_ast(x));
        }
        result.into()
    } else {
        node.clone()
    }
}

fn main() {
    let test_data = serde_json::json!([1.0, [2.0, 3.0], 4.0, [5.0, [6.0, 7.0]], 8.0]);
    let result = lint_ast(&test_data);
    println!("{}", result);
}