fn parse_document(text: &str) -> Vec<String> {
    let mut tokens = Vec::new();
    let mut current_token = String::new();

    for char in text.chars() {
        if char.is_alphanumeric() || "_.-".contains(char) {
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

fn tokenize(text: &str) -> Vec<String> {
    parse_document(text)
}

fn main() {
    let document = "Hello, world! 123.45 is a number.";
    let tokens = tokenize(document);
    println!("{:?}", tokens);
}