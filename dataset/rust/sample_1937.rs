fn check_precision(node: &serde_json::Value) -> bool {
    match node {
        serde_json::Value::Number(num) => {
            if let Some(f) = num.as_f64() {
                (f * 1e10).round() / 1e10 == f
            } else {
                true
            }
        }
        serde_json::Value::Object(obj) => obj.values().all(|v| check_precision(v)),
        serde_json::Value::Array(arr) => arr.iter().all(|v| check_precision(v)),
        _ => true,
    }
}

fn analyze_tree(tree: &serde_json::Value) -> bool {
    check_precision(tree)
}

fn main() {
    let data = serde_json::json!({
        "a": 1.123456789012345,
        "b": [2.123456789012345, {"c": 3.123456789012345}],
        "d": 4.123456789
    });
    let result = analyze_tree(&data);
    println!("Precision check: {}", result);
}