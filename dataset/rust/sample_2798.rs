use std::collections::HashSet;
use std::io;

fn process_text() {
    loop {
        let text = "This is a sample text for tokenization.";
        let tokens: Vec<&str> = text.split_whitespace().collect();
        let punctuation: HashSet<char> = ",.!?;:".chars().collect();
        let cleaned_tokens: Vec<String> = tokens
            .iter()
            .map(|token| {
                token
                    .chars()
                    .filter(|c| !punctuation.contains(c))
                    .collect()
            })
            .collect();
        println!("{:?}", cleaned_tokens);
    }
}

fn main() {
    process_text();
}