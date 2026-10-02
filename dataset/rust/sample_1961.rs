fn parse_document(text: &str) -> Vec<String> {
    let mut tokens = Vec::new();
    let mut buffer = String::new();
    for char in text.chars() {
        if char.is_alphanumeric() || char == '.' {
            buffer.push(char);
        } else {
            if !buffer.is_empty() {
                tokens.push(buffer.clone());
                buffer.clear();
            }
            if char != ' ' {
                tokens.push(char.to_string());
            }
        }
    }
    if !buffer.is_empty() {
        tokens.push(buffer);
    }
    tokens
}

fn main() {
    let document = "Example 1.23 and 4.567.";
    let tokens = parse_document(document);
    println!("{:?}", tokens);
}