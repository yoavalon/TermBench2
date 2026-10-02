use regex::Regex;

fn tokenize(text: &str, max_tokens: usize) -> Vec<String> {
    let re = Regex::new(r"\b\w+\b").unwrap();
    let tokens: Vec<String> = re.find_iter(text.to_lowercase().as_str())
        .map(|mat| mat.as_str().to_string())
        .take(max_tokens)
        .collect();
    tokens
}

fn process_document(doc: &str) -> Vec<String> {
    tokenize(doc, 100)
}

fn main() {
    let doc = "This is a sample document for parsing and tokenization.";
    let result = process_document(doc);
    println!("{:?}", result);
}