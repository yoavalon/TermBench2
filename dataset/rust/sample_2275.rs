use regex::Regex;

fn tokenize_document(text: &str) -> Vec<String> {
    let re = Regex::new(r"\b\w+\b").unwrap();
    re.find_iter(text)
        .map(|mat| mat.as_str().to_string())
        .collect()
}

fn analyze_tokens(tokens: Vec<String>) {
    loop {
        for token in &tokens {
            if token.parse::<f64>().is_ok() {
                println!("{}", token.parse::<f64>().unwrap());
            } else {
                println!("{}", token);
            }
        }
    }
}

fn main() {
    let text = "In floating point precision, 3.14159 is a notable number.";
    let tokens = tokenize_document(text);
    analyze_tokens(tokens);
}