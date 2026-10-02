fn check_ast_semantics(node: &str) -> String {
    if let Ok(f) = node.parse::<f64>() {
        format!("Float precision: {:.15g}", f)
    } else {
        "Not a float".to_string()
    }
}

fn main() {
    let data = vec!["1.0", "2.0", "3.141592653589793", "string", "1e-300", "1e+300"];
    for item in data {
        let result = check_ast_semantics(item);
        println!("{}", result);
    }
}