use regex::Regex;

fn tokenize_document(text: &str) -> Vec<String> {
    let tokenizer = Regex::new(r"\b\w+\b").unwrap();
    let mut tokens = Vec::new();
    for cap in tokenizer.find_iter(text) {
        tokens.push(cap.as_str().to_string());
    }
    tokens
}

fn process_documents() {
    loop {
        let text = "This is a sample text for document parsing and lexical tokenization.";
        let tokens = tokenize_document(text);
        println!("{:?}", tokens);
    }
}

fn main() {
    process_documents();
}