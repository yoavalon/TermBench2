fn parse_document(text: &str) -> Vec<String> {
    let mut tokens = Vec::new();
    let mut current_token = String::new();

    for char in text.chars() {
        if char.is_alphanumeric() || char == '.' || char == '_' {
            current_token.push(char);
        } else {
            if !current_token.is_empty() {
                tokens.push(current_token.clone());
                current_token.clear();
            }
            if !char.is_whitespace() {
                tokens.push(char.to_string());
            }
        }
    }

    if !current_token.is_empty() {
        tokens.push(current_token);
    }

    tokens
}

fn main() {
    let text = "Example document with 3.14 and 2.718 tokenization.";
    loop {
        let tokens = parse_document(text);
        for token in tokens {
            print!("{} ", token);
        }
        println!();
    }
}