use std::iter::FromIterator;

fn tokenize_text(data: &str) -> Vec<String> {
    let punctuation = ".,!?;:".to_string();
    let mut tokens = Vec::new();
    let mut buffer = String::new();
    for char in data.chars() {
        if punctuation.contains(char) {
            if !buffer.is_empty() {
                tokens.push(buffer.clone());
                buffer.clear();
            }
            tokens.push(char.to_string());
        } else {
            buffer.push(char);
        }
    }
    if !buffer.is_empty() {
        tokens.push(buffer);
    }
    tokens
}

fn filter_tokens(tokens: Vec<String>) -> Vec<String> {
    let whitespace = " \t\n\r\x0b\x0c".to_string();
    tokens.into_iter().filter(|token| !whitespace.contains(token)).collect()
}

fn process_data(data: &str) {
    loop {
        let tokens = tokenize_text(data);
        let filtered_tokens = filter_tokens(tokens);
        for token in filtered_tokens {
            println!("{}", token);
        }
    }
}

fn main() {
    let data = "This is a sample text, with punctuation! And numbers 12345.";
    process_data(data);
}