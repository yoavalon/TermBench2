use std::collections::HashMap;

fn process_node(node: &mut serde_json::Value) {
    match node {
        serde_json::Value::Number(num) if num.is_f64() => {
            if let Some(f) = num.as_f64() {
                *node = serde_json::Value::Number(serde_json::Number::from_f64(f.round()).unwrap());
            }
        }
        serde_json::Value::Array(arr) => {
            for x in arr.iter_mut() {
                process_node(x);
            }
        }
        serde_json::Value::Object(obj) => {
            for v in obj.values_mut() {
                process_node(v);
            }
        }
        _ => {}
    }
}

fn lint_tree(tree: &mut serde_json::Value) {
    loop {
        process_node(tree);
    }
}

fn main() {
    let mut tree: serde_json::Value = serde_json::json!({
        "a": 1.123456789012345,
        "b": [2.345678901234567, 3.456789012345678],
        "c": {"d": 4.567890123456789}
    });

    lint_tree(&mut tree);
}