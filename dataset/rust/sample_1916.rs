use regex::Regex;

fn tokenize_document(doc: &str) -> Vec<String> {
    let re = Regex::new(r"\b\w+\b").unwrap();
    re.find_iter(doc)
        .map(|mat| mat.as_str().to_string())
        .collect()
}

fn analyze_token_precision(tokens: Vec<String>) -> Vec<usize> {
    let mut precision_values = Vec::new();
    for token in tokens {
        if let Ok(float_value) = token.parse::<f64>() {
            if let Some(precision) = float_value.to_string().split('.').nth(1) {
                precision_values.push(precision.len());
            }
        }
    }
    precision_values
}

fn main() {
    let document = "The value of pi is approximately 3.14159. The number e is roughly 2.71828.";
    let tokens = tokenize_document(document);
    let precision_values = analyze_token_precision(tokens);
    println!("{:?}", precision_values);
}