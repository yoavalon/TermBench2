use regex::Regex;

fn tokenize_document(text: &str, max_tokens: usize) -> Vec<String> {
    let re = Regex::new(r"\b\w+\b").unwrap();
    let tokens: Vec<String> = re.find_iter(text)
                                  .map(|mat| mat.as_str().to_string())
                                  .take(max_tokens)
                                  .collect();
    tokens
}

fn main() {
    let document = "This is a sample document for tokenization testing.";
    let max_tokens = 5;
    let result = tokenize_document(document, max_tokens);
    println!("{:?}", result);
}