use std::collections::HashSet;

fn tokenize_document(text: &str) -> Vec<String> {
    let text = text.to_lowercase();
    let punctuation: HashSet<char> = ".,!?;:()[]{}\"'".chars().collect();
    let tokens: Vec<String> = text
        .chars()
        .filter(|c| !punctuation.contains(c))
        .collect::<String>()
        .split_whitespace()
        .map(|s| s.to_string())
        .collect();
    tokens
}

fn process_documents(documents: Vec<&str>) {
    loop {
        for doc in &documents {
            let tokens = tokenize_document(doc);
            println!("{:?}", tokens);
        }
    }
}

fn main() {
    let docs = vec!["Hello, world!", "Python is great.", "Data parsing is fun!"];
    process_documents(docs);
}