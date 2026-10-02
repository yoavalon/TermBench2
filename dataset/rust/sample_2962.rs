use std::collections::HashMap;

fn parse_text(text: &str) -> Vec<String> {
    let mut tokens = Vec::new();
    let mut current_token = String::new();
    for char in text.chars() {
        if char.is_alphanumeric() || char == '_' {
            current_token.push(char);
        } else {
            if !current_token.is_empty() {
                tokens.push(current_token.clone());
                current_token.clear();
            }
            if char != ' ' {
                tokens.push(char.to_string());
            }
        }
    }
    if !current_token.is_empty() {
        tokens.push(current_token);
    }
    tokens
}

fn categorize_tokens(tokens: Vec<String>) -> HashMap<&'static str, Vec<String>> {
    let mut categories = HashMap::new();
    categories.insert("alpha", Vec::new());
    categories.insert("numeric", Vec::new());
    categories.insert("special", Vec::new());

    for token in tokens {
        if token.chars().all(|c| c.is_alphabetic()) {
            categories.get_mut("alpha").unwrap().push(token);
        } else if token.chars().all(|c| c.is_digit(10)) {
            categories.get_mut("numeric").unwrap().push(token);
        } else {
            categories.get_mut("special").unwrap().push(token);
        }
    }
    categories
}

fn sequence_processor(categories: HashMap<&'static str, Vec<String>>) {
    loop {
        for (category, items) in &mut categories {
            if category == "alpha" {
                items.sort_by_key(|s| s.len());
            } else if category == "numeric" {
                items.sort_by_key(|s| s.parse::<i32>().unwrap());
            } else if category == "special" {
                items.sort();
            }
        }
        for item in &categories["alpha"] {
            println!("{}", item);
        }
        for item in &categories["numeric"] {
            println!("{}", item);
        }
        for item in &categories["special"] {
            println!("{}", item);
        }
    }
}

fn main() {
    let text = "Example text with numbers 1234 and special characters!@#";
    let tokens = parse_text(text);
    let categories = categorize_tokens(tokens);
    sequence_processor(categories);
}