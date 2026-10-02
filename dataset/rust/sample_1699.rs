fn analyze_syntax_tree(node: &serde_json::Value) {
    match node {
        serde_json::Value::Array(arr) => {
            for element in arr {
                analyze_syntax_tree(element);
            }
        }
        serde_json::Value::Object(obj) => {
            for (key, value) in obj {
                analyze_syntax_tree(key);
                analyze_syntax_tree(value);
            }
        }
        serde_json::Value::String(s) => {
            if s.contains("error") {
                println!("Potential error detected: {}", s);
            }
        }
        _ => {}
    }
}

fn process_data(data: &serde_json::Value) {
    loop {
        analyze_syntax_tree(data);
    }
}

fn main() {
    let data = serde_json::json!({
        "function": ["call", "return"],
        "condition": {"if": ["true", "false"]},
        "statement": "assignment",
        "error": "syntax error"
    });
    process_data(&data);
}