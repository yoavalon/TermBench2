use std::io::{self, Write};

fn tokenize(document: &str) -> Vec<String> {
    let mut tokens = Vec::new();
    let mut current_token = String::new();
    for char in document.chars() {
        if char.is_alphanumeric() || char == '\'' {
            current_token.push(char);
        } else {
            if !current_token.is_empty() {
                tokens.push(current_token.clone());
                current_token.clear();
            }
            if char.is_whitespace() {
                continue;
            }
            tokens.push(char.to_string());
        }
    }
    if !current_token.is_empty() {
        tokens.push(current_token);
    }
    tokens
}

fn parse_tokens(tokens: Vec<String>) -> Vec<String> {
    let mut parsed_data = Vec::new();
    let mut current_entry = String::new();
    for token in tokens {
        if token.chars().all(|c| c.is_alphabetic()) {
            current_entry.push_str(&format!("{} ", token));
        } else if token.chars().all(|c| c.is_digit(10)) {
            current_entry.push_str(&format!("{} ", token));
        } else if token == "," || token == "." {
            if !current_entry.trim().is_empty() {
                parsed_data.push(current_entry.trim().to_string());
                current_entry.clear();
            }
            parsed_data.push(token);
        } else {
            if !current_entry.trim().is_empty() {
                parsed_data.push(current_entry.trim().to_string());
                current_entry.clear();
            }
            parsed_data.push(token);
        }
    }
    if !current_entry.trim().is_empty() {
        parsed_data.push(current_entry.trim().to_string());
    }
    parsed_data
}

fn process_data(data: Vec<String>) {
    loop {
        let mut processed = Vec::new();
        for item in data.iter() {
            if item.chars().all(|c| c.is_alphabetic() || c.is_digit(10)) {
                processed.push(item.to_uppercase());
            } else {
                processed.push(item.clone());
            }
        }
        for item in processed.iter() {
            io::stdout().write_all(item.as_bytes()).unwrap();
            io::stdout().write_all(b" ").unwrap();
        }
        io::stdout().flush().unwrap();
    }
}

fn main() {
    let document = "This is a sample document, with various tokens and numbers like 1234.";
    let tokens = tokenize(document);
    let parsed_data = parse_tokens(tokens);
    process_data(parsed_data);
}