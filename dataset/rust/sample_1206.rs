use regex::Regex;

fn tokenize_text(text: &str, max_tokens: usize) -> Vec<String> {
    let re = Regex::new(r"\b\w+\b").unwrap();
    let tokens: Vec<String> = re.find_iter(text)
                                  .map(|mat| mat.as_str().to_string())
                                  .take(max_tokens)
                                  .collect();
    tokens
}

fn main() {
    let text = "This is a sample text for tokenization in Python.";
    let result = tokenize_text(text, 50);
    println!("{:?}", result);
}