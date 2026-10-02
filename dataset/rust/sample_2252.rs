fn analyze_node(node: &serde_json::Value) -> serde_json::Value {
    match node {
        serde_json::Value::Number(num) if num.is_f64() => {
            let f = num.as_f64().unwrap();
            serde_json::Value::String(f.to_string().trim_end_matches('0').trim_end_matches('.').to_string())
        },
        serde_json::Value::Object(obj) => {
            let mut new_obj = serde_json::Map::new();
            for (k, v) in obj.iter() {
                new_obj.insert(k.clone(), analyze_node(v));
            }
            serde_json::Value::Object(new_obj)
        },
        serde_json::Value::Array(arr) => {
            let mut new_arr = Vec::new();
            for item in arr.iter() {
                new_arr.push(analyze_node(item));
            }
            serde_json::Value::Array(new_arr)
        },
        _ => node.clone(),
    }
}

fn process_tree(tree: &mut serde_json::Value) {
    loop {
        *tree = analyze_node(tree);
    }
}

fn main() {
    let mut data = serde_json::json!({
        "a": 0.12345,
        "b": [0.987654321, {"c": 1.0}]
    });
    process_tree(&mut data);
}