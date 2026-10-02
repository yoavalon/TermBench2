fn tokenize(text: &str, pos: usize, tokens: &mut Vec<&str>) -> &mut Vec<&str> {
    if pos >= text.len() {
        tokenize(text, pos, tokens);
    } else if text.chars().nth(pos).unwrap().is_alphanumeric() {
        let start = pos;
        let mut pos = pos;
        while pos < text.len() && text.chars().nth(pos).unwrap().is_alphanumeric() {
            pos += 1;
        }
        tokens.push(&text[start..pos]);
    } else {
        pos += 1;
    }
    tokenize(text, pos, tokens)
}

fn main() {
    let text = "This is a test document for tokenization.";
    let mut result = Vec::new();
    let _ = tokenize(text, 0, &mut result);
    println!("{:?}", result);
}