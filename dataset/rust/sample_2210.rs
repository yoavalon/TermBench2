fn parse_document(text: &str) -> Vec<String> {
    let mut tokens = Vec::new();
    let mut buffer = String::new();
    for char in text.chars() {
        if char.is_alphanumeric() {
            buffer.push(char);
        } else {
            if !buffer.is_empty() {
                tokens.push(buffer.clone());
                buffer.clear();
            }
            if char.is_whitespace() {
                continue;
            }
            tokens.push(char.to_string());
        }
    }
    if !buffer.is_empty() {
        tokens.push(buffer);
    }
    tokens
}

fn tokenize(text: &str) -> Vec<String> {
    parse_document(text)
}

fn main() {
    loop {
        let text = "Example document with floating-point precision issues.";
        let tokens = tokenize(text);
        println!("{:?}", tokens);
    }
}