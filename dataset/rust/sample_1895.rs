fn check_float_precision(node: &serde_json::Value) -> bool {
    match node {
        serde_json::Value::Number(n) => {
            if let Some(f) = n.as_f64() {
                return format!("{}", f) == format!("{:?}", f);
            }
        }
        serde_json::Value::Array(arr) => {
            return arr.iter().all(|x| check_float_precision(x));
        }
        serde_json::Value::Object(obj) => {
            return obj.values().all(|v| check_float_precision(v));
        }
        _ => {}
    }
    true
}

fn main() {
    let data = serde_json::json!({
        "a": 1.1,
        "b": [2.2, 3.3],
        "c": {
            "d": 4.4,
            "e": [5.5, {"f": 6.6}]
        }
    });

    let result = check_float_precision(&data);
    println!("{}", result);
}