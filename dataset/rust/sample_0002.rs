use regex::Regex;

fn tokenize_document(text: &str) -> Vec<String> {
    let re = Regex::new(r"\b\w+\b").unwrap();
    let tokens: Vec<String> = re.find_iter(text.to_lowercase())
        .map(|mat| mat.as_str().to_string())
        .take(100)
        .collect();
    tokens
}

fn main() {
    let doc = "Your sample document text goes here.";
    let tokens = tokenize_document(doc);
    for token in tokens {
        println!("{}", token);
    }
}