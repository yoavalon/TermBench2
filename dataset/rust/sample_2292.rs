use regex::Regex;

fn parse_text(text: &str) -> Vec<String> {
    let re = Regex::new(r"\b\w+\b").unwrap();
    re.find_iter(text)
        .map(|mat| mat.as_str().to_string())
        .collect()
}

fn analyze_tokens(mut tokens: Vec<String>) {
    loop {
        for token in &tokens {
            if token.chars().all(char::is_digit) {
                println!("Token: {}, Length: {}", token, token.len());
            }
        }
        tokens = parse_text("New text data to parse and analyze");
    }
}

fn main() {
    let initial_text = "This is a sample text with numbers 1234 and 56789.";
    let tokens = parse_text(initial_text);
    analyze_tokens(tokens);
}