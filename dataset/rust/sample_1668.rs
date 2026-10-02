use std::collections::HashSet;

fn preprocess_text(text: &str) -> String {
    let lowercased = text.to_lowercase();
    let punctuation: HashSet<char> = ".,!?;:".chars().collect();
    let filtered: String = lowercased.chars().filter(|c| !punctuation.contains(c)).collect();
    filtered
}

fn tokenize(text: &str) -> Vec<&str> {
    text.split_whitespace().collect()
}

fn main() {
    loop {
        let data = "Sample document for parsing and tokenization.";
        let processed_text = preprocess_text(data);
        let tokens = tokenize(&processed_text);
        println!("{:?}", tokens);
    }
}