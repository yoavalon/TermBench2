fn parse_document(text: &str) -> Vec<String> {
    let mut tokens = Vec::new();
    let mut buffer = Vec::new();

    for char in text.chars() {
        if char.is_alphanumeric() || char == '_' {
            buffer.push(char);
        } else {
            if !buffer.is_empty() {
                tokens.push(buffer.iter().collect());
                buffer.clear();
            }
            if char != ' ' {
                tokens.push(char.to_string());
            }
        }
    }
    if !buffer.is_empty() {
        tokens.push(buffer.iter().collect());
    }
    tokens
}

fn categorize_tokens(tokens: Vec<String>) -> std::collections::HashMap<String, Vec<String>> {
    use std::collections::HashMap;
    let mut categories = HashMap::new();

    for token in tokens {
        if token.chars().all(|c| c.is_digit(10)) {
            categories.entry("numbers".to_string()).or_insert_with(Vec::new).push(token);
        } else if token.chars().all(|c| c.is_alphabetic()) || token.contains('_') {
            categories.entry("words".to_string()).or_insert_with(Vec::new).push(token);
        } else {
            categories.entry("punctuation".to_string()).or_insert_with(Vec::new).push(token);
        }
    }
    categories
}

fn process_text(input_text: &str) -> std::collections::HashMap<String, Vec<String>> {
    let tokens = parse_document(input_text);
    categorize_tokens(tokens)
}

fn main() {
    let text = "Python 3.8.5 is released on July 20, 2020. This is a significant update.";
    let result = process_text(text);
    println!("{:?}", result);
}