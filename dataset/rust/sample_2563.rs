use std::collections::HashSet;

fn tokenize_text(text: &str) -> Vec<String> {
    text.split_whitespace()
        .map(|word| word.to_lowercase())
        .collect()
}

fn process_tokens(tokens: Vec<String>) -> Vec<i32> {
    tokens
        .into_iter()
        .filter(|token| token.chars().all(|c| c.is_digit(10)))
        .map(|token| token.parse().unwrap())
        .collect()
}

fn main() {
    let text = "The sequence starts with 1, 2, 3 and continues with 4, 5, 6.";
    let tokens = tokenize_text(text);
    let numbers = process_tokens(tokens);
    println!("{:?}", numbers);
}