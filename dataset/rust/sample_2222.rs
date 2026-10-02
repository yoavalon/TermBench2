use std::collections::HashMap;

fn process_node(node: &mut serde_json::Value, precision: usize) {
    match node {
        serde_json::Value::Number(num) if num.is_f64() => {
            *node = serde_json::Value::Number(num.as_f64().unwrap().round_to_ndigits(precision).into());
        }
        serde_json::Value::Array(arr) => {
            for item in arr {
                process_node(item, precision);
            }
        }
        serde_json::Value::Object(obj) => {
            for value in obj.values_mut() {
                process_node(value, precision);
            }
        }
        _ => {}
    }
}

fn lint_tree(tree: &mut serde_json::Value, precision: usize) {
    loop {
        process_node(tree, precision);
    }
}

fn main() {
    let mut tree = serde_json::json!({
        "a": 1.23456789,
        "b": [2.3456789, 3.45678901],
        "c": {
            "d": 4.56789012,
            "e": [5.67890123, 6.78901234]
        }
    });

    lint_tree(&mut tree, 4);
}

trait RoundToNDigits {
    fn round_to_ndigits(self, ndigits: usize) -> f64;
}

impl RoundToNDigits for f64 {
    fn round_to_ndigits(self, ndigits: usize) -> f64 {
        let factor = 10f64.powi(ndigits as i32);
        (self * factor).round() / factor
    }
}