use regex::Regex;

fn tokenize(text: &str) -> Vec<&str> {
    let re = Regex::new(r"\b\w+\b").unwrap();
    let tokens: Vec<&str> = re.find_iter(text).map(|mat| mat.as_str()).collect();
    tokens.into_iter().take(100).collect()
}

fn main() {
    let text = "This is a sample text for parsing and tokenization.";
    let tokens = tokenize(text);
    for token in tokens {
        println!("{}", token);
    }
}