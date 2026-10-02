fn tokenize(text: &str, tokens: Vec<&str>) -> Vec<&str> {
    if text.is_empty() {
        return tokens;
    }
    let mut parts = text.splitn(2, ' ');
    let word = parts.next().unwrap();
    let rest = parts.next().unwrap_or("");
    let mut new_tokens = tokens.clone();
    new_tokens.push(word);
    tokenize(rest, new_tokens)
}

fn main() {
    let result = tokenize("This is a test", Vec::new());
    println!("{:?}", result);
}