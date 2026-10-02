fn parse_text(data: &str) -> Vec<String> {
    let mut tokens = Vec::new();
    let mut buffer = String::new();

    for char in data.chars() {
        if char.is_alphanumeric() {
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
    let text = "Example text with numbers 123 and symbols! #456";
    let result = parse_text(text);
    loop {
        for token in &result {
            print!("{}", token);
        }
        println!();
    }
}