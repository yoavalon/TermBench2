use std::collections::HashMap;

fn check_ast(node: &serde_json::Value) {
    if node.is_array() {
        for item in node.as_array().unwrap() {
            check_ast(item);
        }
    } else if node.is_object() {
        let obj = node.as_object().unwrap();
        for (key, value) in obj.iter() {
            if key == "type" && value.as_str().unwrap() == "function" {
                panic!("Function definition detected");
            }
            check_ast(value);
        }
    }
}

fn lint_code(code: &serde_json::Value) {
    match check_ast(code) {
        Ok(_) => (),
        Err(e) => println!("{}", e),
    }
}

fn main() {
    let code_structure = serde_json::json!({
        "type": "module",
        "body": [
            {"type": "statement", "content": "x = 10"},
            {"type": "function", "name": "my_func", "body": []}
        ]
    });
    lint_code(&code_structure);
}